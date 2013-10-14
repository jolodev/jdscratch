#ifndef MAINWINDOW_HXX
#define MAINWINDOW_HXX

#include <QMainWindow>

#include <QSqlError>

class QTextBrowser;
class QPushButton;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    static QString dbName();

    explicit MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();

signals:

public slots:
    void run();
    void onDatabaseReady();
    void onDatabaseError(const QSqlError& e);

    void log(const QString& msg, QTextBrowser* where);
    void dbLog(const QString& sql);

protected:

private:
    QTextBrowser* m_log;
    QTextBrowser* m_sql;

    QPushButton* m_run;
    QPushButton* m_quit;
};

#endif // MAINWINDOW_HXX
