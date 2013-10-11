#ifndef OMTOOLS_HXX
#define OMTOOLS_HXX

#include <core/Types.hxx>
#include <core/qiostream.hxx>

class OMTools {
public:
    static QUuid invalidId();
    static QUuid createId();
    static bool isValid(const QUuid& id);
};

#endif // OMTOOLS_HXX
