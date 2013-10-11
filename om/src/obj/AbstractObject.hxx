#ifndef ABSTRACTOBJECT_HXX
#define ABSTRACTOBJECT_HXX

#include <core/OMTools.hxx>

#include <obj/AbstractObjectFwd.hxx>

class AbstractObject
{
public:
    explicit AbstractObject();
    virtual ~AbstractObject();

    QString toString() const;
    QUuid id() const;

    template<typename ObjectT>
    static std::shared_ptr<ObjectT> createObject() {
        auto o = std::make_shared<ObjectT>(ObjectT(OMTools::createId()));
        return o;
    }

protected:
    virtual QString implToString() const = 0;
    virtual QUuid implId() const = 0;
};

#endif // ABSTRACTOBJECT_HXX
