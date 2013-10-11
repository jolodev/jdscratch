#include "AbstractDbGen.hxx"

AbstractDbGen::AbstractDbGen()
{
}

AbstractDbGen::~AbstractDbGen()
{

}

QStringList AbstractDbGen::create(Database *db) const
{
    return implCreate(db);
}

QString AbstractDbGen::comment(const QString &txt) const
{
    return QString("-- %1").arg(txt);
}
