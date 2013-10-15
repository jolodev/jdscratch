#include <Tools.hxx>



std::ostream &operator<<(std::ostream &strm, const QString &s)
{
    strm << s.toStdString();
    return strm;
}
/*
std::ostream &operator<<(std::ostream &strm, const Id &s)
{
    strm << s.toString();
    return strm;
}
*/

Id createInvalidId()
{
    return 0;
    //return QUuid();
}


Id createId()
{
    static qulonglong id = 1;
    return id++;
    //return QUuid::createUuid();
}


bool isValid(const Id &id)
{
    return (id != createInvalidId());
    //return (!id.isNull());
}
