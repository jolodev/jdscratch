#include "DatabaseConnectionData.hxx"

DatabaseConnectionData::DatabaseConnectionData()
{
}

DatabaseConnectionData::~DatabaseConnectionData()
{

}

QString DatabaseConnectionData::host() const
{
    return m_host;
}

QString DatabaseConnectionData::driver() const
{
    return m_driver;
}

int DatabaseConnectionData::port() const
{
    return m_port;
}

QString DatabaseConnectionData::database() const
{
    return m_db;
}

QString DatabaseConnectionData::login() const
{
    return m_login;
}

QString DatabaseConnectionData::password() const
{
    return m_password;
}
