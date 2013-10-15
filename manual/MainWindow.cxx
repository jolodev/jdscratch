#include "MainWindow.hxx"
#include "ui_MainWindow.h"

#include <QPushButton>
#include <QTextBrowser>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->m_runW, &QPushButton::clicked, this, &MainWindow::onRun);
    connect(ui->m_quitW, &QPushButton::clicked, qApp, &QApplication::quit);

    onRun();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onRun()
{
    ui->m_logW->clear();

    log(tr("Running..."));
}

void MainWindow::log(const QString &msg)
{
    ui->m_logW->append(msg);
}
