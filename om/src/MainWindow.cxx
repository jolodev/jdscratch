#include "MainWindow.hxx"

#include <QLayout>
#include <QTextBrowser>
#include <QPushButton>
#include <QApplication>

#include <obj/TestNode.hxx>
#include <obj/ObjectFormatter.hxx>

#include <db/Database.hxx>
#include <orm/Mapper.hxx>
#include <orm/DbGen.hxx>
#include <orm/PgDialect.hxx>

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

    run();
}

MainWindow::~MainWindow()
{}

void MainWindow::run()
{
    auto db = Database("demo");

    m_log->clear();
    m_sql->clear();

    auto o = AbstractObject::createObject<TestNode>();
    log(ObjectFormatter<TestNode>::format(o), m_log);

    Mapper::instance()->createDataTableIn<TestNode>(&db);

    auto dbgen = DbGen<PgDialect>();

    for (auto cmd : dbgen.create(&db)) {
        log(cmd, m_sql);
    }

}

void MainWindow::log(const QString& msg, QTextBrowser *where) {
    where->append(msg);
}
