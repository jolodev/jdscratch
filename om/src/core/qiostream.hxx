#ifndef QIOSTREAM_HXX
#define QIOSTREAM_HXX

#include <core/Types.hxx>

std::ostream& operator<<(std::ostream& strm, const QString& s);
std::ostream& operator<<(std::ostream& strm, const QUuid& u);
std::ostream& operator<<(std::ostream& strm, const QUuidV& v);

#endif // QIOSTREAM_HXX
