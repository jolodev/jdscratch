#include "PgConn.hxx"

#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

QString PgConn::connectionName()
{
    return "pgconn";
}

PgConn *PgConn::instance()
{
    static auto i = new PgConn(qApp);
    return i;
}

PgConn::PgConn(QObject *parent) :
    QObject(parent)
{
}

PgConn::~PgConn()
{

}

void PgConn::exec(const QStringList &q)
{
    for (auto sql : q) {
        exec(sql);
    }
}

void PgConn::exec(const QString &q)
{
    auto dbConn = QSqlDatabase::database(PgConn::connectionName());

    if (!dbConn.isOpen()) {
        emit connectionError(dbConn.lastError());
        return;
    }

    auto qry = QSqlQuery(dbConn);

    if (!qry.exec(q)) {
        emit queryError(qry.lastError());
    }

    emit executed(q);
}

bool PgConn::begin()
{
    auto r = QSqlDatabase::database(PgConn::connectionName()).transaction();
    emit logRequest(tr("Starting transaction... %1").arg(r ? tr("Success.") : tr("Failed: %1").arg(lastError().text())));

    if (!r) {
        emit transactionError(lastError());
    }

    return r;
}

bool PgConn::commit()
{
    auto r = QSqlDatabase::database(PgConn::connectionName()).commit();
    emit logRequest(tr("Committing transaction... %1").arg(r ? tr("Success.") : tr("Failed: %1").arg(lastError().text())));

    if (!r) {
        emit transactionError(lastError());
    }

    return r;
}

bool PgConn::rollback()
{
    auto r = QSqlDatabase::database(PgConn::connectionName()).rollback();
    emit logRequest(tr("Rolling back transaction... %1").arg(r ? tr("Success.") : tr("Failed: %1").arg(lastError().text())));

    if (!r) {
        emit transactionError(lastError());
    }

    return r;
}

QSqlError PgConn::lastError() const
{
    return QSqlDatabase::database(PgConn::connectionName()).lastError();
}

void PgConn::open(const DatabaseConnectionData &cd)
{
    if (QSqlDatabase::contains(PgConn::connectionName())) {
        QSqlDatabase::removeDatabase(PgConn::connectionName());
    }

    auto conn = QSqlDatabase::addDatabase(cd.driver(), PgConn::connectionName());
    conn.setHostName(cd.host());
    conn.setPort(cd.port());
    conn.setDatabaseName(cd.database());
    conn.setUserName(cd.login());
    conn.setPassword(cd.password());

    if (!conn.open()) {
        emit connectionError(conn.lastError());
        return;
    }

    emit ready();
}
