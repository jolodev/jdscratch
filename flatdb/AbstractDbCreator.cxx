#include "AbstractDbCreator.hxx"

AbstractDbCreator::AbstractDbCreator()
{
}

AbstractDbCreator::~AbstractDbCreator()
{

}

QStringList AbstractDbCreator::create(DatabaseSP db)
{
    return implCreate(db);
}
