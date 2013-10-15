#include "DataType.hxx"

QString DataType::staticSingular()
{
    return "DATA TYPE";
}

DataType::DataType(AbstractNodeP p, const QString &n, const QString &c)
    : InDatabaseNode(p, n, c)
{
}

DataType::~DataType()
{

}

QString DataType::implSingular() const
{
    return DataType::staticSingular();
}
