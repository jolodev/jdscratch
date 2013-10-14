#ifndef PGCONN_HXX
#define PGCONN_HXX

#include <QObject>

#include <QSqlError>

#include <core/DatabaseConnectionData.hxx>

class PgConn : public QObject
{
    Q_OBJECT
public:
    static QString connectionName();

    static PgConn* instance();

    virtual ~PgConn();

    void exec(const QStringList& q);
    void exec(const QString& q);

    bool begin();
    bool commit();
    bool rollback();

    QSqlError lastError() const;

protected:
    explicit PgConn(QObject *parent = 0);

signals:
    void executed(const QString& sql);
    void queryError(const QSqlError& e);
    void connectionError(const QSqlError& e);
    void transactionError(const QSqlError& e);
    void logRequest(const QString& msg);

    void ready();
    void closed();

public slots:
    void open(const DatabaseConnectionData& cd);
};

#endif // PGCONN_HXX
