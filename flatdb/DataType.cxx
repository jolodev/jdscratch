#include "DataType.hxx"

QString DataType::staticSingular()
{
    return "DATA TYPE";
}

QString DataType::staticPlural()
{
    return "DATA TYPES";
}

DataType::DataType(DatabaseP db, const Id &parentId, const Id &id, const QString &n, const QString &c)
    : InDatabaseNode(db, parentId, id, n, c)
{
}

DataType::~DataType()
{
}

QString DataType::implSingular() const
{
    return DataType::staticSingular();
}

QString DataType::implPlural() const
{
    return DataType::staticPlural();
}
