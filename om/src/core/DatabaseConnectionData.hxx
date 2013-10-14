#ifndef DATABASECONNECTIONDATA_HXX
#define DATABASECONNECTIONDATA_HXX

#include <core/Types.hxx>

class DatabaseConnectionData
{
public:
    explicit DatabaseConnectionData();
    virtual ~DatabaseConnectionData();

    QString host() const;
    QString driver() const;
    int port() const;
    QString database() const;
    QString login() const;
    QString password() const;

private:
    QString m_driver { "QPSQL" };
    QString m_host { "localhost" };
    int m_port { 5444 };
    QString m_db { "omdev" };
    QString m_login { "jolodev" };
    QString m_password { "" };
};

#endif // DATABASECONNECTIONDATA_HXX
