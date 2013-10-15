#ifndef TOOLS_HXX
#define TOOLS_HXX

#include <Types.hxx>

std::ostream& operator<<(std::ostream& strm, const QString& s);
//std::ostream& operator<<(std::ostream& strm, const Id& s);

template<typename T>
QString optionalToString(std::shared_ptr<T> t) {
    if (t) {
        return t->name();
    }

    return QObject::tr("[%1 not set]").arg(T::staticSingular());
}

Id createInvalidId();
Id createId();
bool isValid(const Id& id);

#endif // TOOLS_HXX
