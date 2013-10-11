#include "qiostream.hxx"

std::ostream &operator<<(std::ostream &strm, const QString &s)
{
    strm << s.toStdString();
    return strm;
}


std::ostream &operator<<(std::ostream &strm, const QUuid &u)
{
    strm << u.toString().toStdString();
    return strm;
}
