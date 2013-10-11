#ifndef OBJECT_HXX
#define OBJECT_HXX

#include <obj/AbstractObject.hxx>

class Object : public AbstractObject
{
public:
    static QString idPropertyName();

    explicit Object(const QUuid& id = OMTools::invalidId());
    virtual ~Object();

protected:
    QString implToString() const override;
    QUuid implId() const override;
    void implRegisterProperty(AbstractPropertySP p) override;
    AbstractPropertySP implProperty(const QString &name) const override;
    const AbstractPropertySPV implProperties() const override;

private:
    AbstractPropertySPV m_propertyV;
    AbstractPropertySPM m_propertyM;
};

#endif // OBJECT_HXX
