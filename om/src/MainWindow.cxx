#include "MainWindow.hxx"

#include <QLayout>
#include <QTextBrowser>
#include <QPushButton>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    auto w = new QWidget(this);
    w->setLayout(new QVBoxLayout(w));

    m_run = new QPushButton(tr("&Run"), w);
    connect(m_run, &QPushButton::clicked, this, &MainWindow::run);

    m_quit = new QPushButton(tr("&Quit"), w);
    connect(m_quit, &QPushButton::clicked, qApp, &QApplication::quit);

    m_browser = new QTextBrowser(w);

    w->layout()->addWidget(m_quit);
    w->layout()->addWidget(m_run);
    w->layout()->addWidget(m_browser);

    setCentralWidget(w);

    run();
}

MainWindow::~MainWindow()
{}

void MainWindow::run()
{
    m_browser->clear();
    log("running...");
}

void MainWindow::log(const QString& msg) {
    m_browser->append(msg);
}
