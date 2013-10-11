#ifndef OBJECTFORMATTER_HXX
#define OBJECTFORMATTER_HXX

#include <obj/AbstractObjectFwd.hxx>
#include <obj/AbstractPropertyFwd.hxx>

template<typename ObjectT>
class ObjectFormatter
{
public:
    using ObjectType = ObjectT;

    static QString format(AbstractObjectSP o) {
        return ObjectFormatter<ObjectType>::format(o.get());
    }

    static QString format(AbstractObjectRP o) {
        QStringList l;
        l.append(ObjectType::singular() + ": " + o->id().toString());

        for (auto p : o->properties()) {
            l.append("\t" + p->toString());
        }

        return l.join("\n");
    }
};

#endif // OBJECTFORMATTER_HXX

