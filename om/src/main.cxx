#include <QApplication>

#include <MainWindow.hxx>

int main(int argc, char** argv) {
    auto app = new QApplication(argc, argv);
    auto w = new MainWindow();

    QObject::connect(app, &QApplication::lastWindowClosed, app, &QApplication::quit);
    w->show();

    return app->exec();
}
