#ifndef MAINWINDOW_HXX
#define MAINWINDOW_HXX

#include <QMainWindow>

class QTextBrowser;
class QPushButton;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();

signals:

public slots:
    void run();

    void log(const QString& msg);

private:
    QTextBrowser* m_browser;
    QPushButton* m_run;
    QPushButton* m_quit;
};

#endif // MAINWINDOW_HXX
