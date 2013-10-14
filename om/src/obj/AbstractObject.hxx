#ifndef ABSTRACTOBJECT_HXX
#define ABSTRACTOBJECT_HXX

#include <core/OMTools.hxx>

#include <obj/AbstractObjectFwd.hxx>
#include <obj/Property.hxx>

class AbstractObject
{
public:
    explicit AbstractObject();
    virtual ~AbstractObject();

    QString toString() const;
    QUuid id() const;

    const AbstractPropertySPV properties() const;

    template<typename ObjectT>
    static std::shared_ptr<ObjectT> createObject() {
        auto o = std::make_shared<ObjectT>(ObjectT(OMTools::createId()));
        return o;
    }

    template<typename ValueT>
    std::shared_ptr<Property<ValueT> > createProperty(const QString& name, const ValueT& value, bool isMandatory = false, bool useValueAsStorageDefault=false) {
        auto p = std::make_shared<Property<ValueT> >(Property<ValueT>(name, value, isMandatory, useValueAsStorageDefault));
        registerProperty(p);
        return p;
    }

protected:
    void registerProperty(AbstractPropertySP p);
    AbstractPropertySP property(const QString& name) const;

    virtual QString implToString() const = 0;
    virtual QUuid implId() const = 0;
    virtual void implRegisterProperty(AbstractPropertySP p) = 0;
    virtual AbstractPropertySP implProperty(const QString& name) const = 0;
    virtual const AbstractPropertySPV implProperties() const = 0;

};

#endif // ABSTRACTOBJECT_HXX
