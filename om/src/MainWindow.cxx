#include "MainWindow.hxx"

#include <QLayout>
#include <QTextBrowser>
#include <QPushButton>
#include <QApplication>
#include <QMessageBox>

#include <core/DatabaseConnectionData.hxx>

#include <obj/TestNode.hxx>
#include <obj/ObjectFormatter.hxx>

#include <db/Database.hxx>
#include <orm/Mapper.hxx>
#include <orm/DbGen.hxx>
#include <orm/PgDialect.hxx>

#include <pgconn/PgConn.hxx>

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

QString MainWindow::dbName()
{
    return "demo";
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    auto w = new QWidget(this);
    w->setLayout(new QVBoxLayout(w));

    m_run = new QPushButton(tr("&Run"), w);
    connect(m_run, &QPushButton::clicked, this, &MainWindow::run);

    m_quit = new QPushButton(tr("&Quit"), w);
    connect(m_quit, &QPushButton::clicked, qApp, &QApplication::quit);

    m_log = new QTextBrowser(w);
    m_sql = new QTextBrowser(w);

    w->layout()->addWidget(m_quit);
    w->layout()->addWidget(m_run);
    w->layout()->addWidget(m_sql);
    w->layout()->addWidget(m_log);

    setCentralWidget(w);

    connect(PgConn::instance(), &PgConn::ready, this, &MainWindow::onDatabaseReady);
    connect(PgConn::instance(), &PgConn::queryError, this, &MainWindow::onDatabaseError);
    connect(PgConn::instance(), &PgConn::transactionError, this, &MainWindow::onDatabaseError);
    connect(PgConn::instance(), &PgConn::executed, this, &MainWindow::dbLog);
    connect(PgConn::instance(), &PgConn::logRequest, this, &MainWindow::dbLog);
    run();
}

MainWindow::~MainWindow()
{}

void MainWindow::run()
{
    m_log->clear();
    m_sql->clear();

/*
    auto o = AbstractObject::createObject<TestNode>();
    log(ObjectFormatter<TestNode>::format(o), m_log);
*/

    log(tr("Opening Database..."), m_log);
    PgConn::instance()->open(DatabaseConnectionData());
}

void MainWindow::onDatabaseReady()
{
    auto dbModel = Database(MainWindow::dbName());

    Mapper::instance()->createDataTableIn<TestNode>(&dbModel);

    auto dbgen = DbGen<PgDialect>();

    log(tr("Database connected."), m_log);

    if (!PgConn::instance()->begin()) {
        QMessageBox::critical(this, tr("Transaction error"), tr("Failed to start transaction: %1").arg(PgConn::instance()->lastError().text()));
        return;
    }

    PgConn::instance()->exec(dbgen.create(&dbModel));

    if (!PgConn::instance()->begin()) {
        QMessageBox::critical(this, tr("Transaction error"), tr("Failed to commit transaction: %1").arg(PgConn::instance()->lastError().text()));
        return;
    }


    log(tr("Schema ready."), m_log);
}

void MainWindow::onDatabaseError(const QSqlError &e)
{
    QMessageBox::critical(this, tr("Database Error"), e.text());

    log(tr("Error: %1").arg(e.text()), m_log)   ;
}

void MainWindow::log(const QString& msg, QTextBrowser *where) {
    where->append(msg);
}

void MainWindow::dbLog(const QString &sql)
{
    log(tr("Executed: %1").arg(sql), m_log);
}

