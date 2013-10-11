#ifndef ABSTRACTPROPERTY_HXX
#define ABSTRACTPROPERTY_HXX

#include <obj/AbstractPropertyFwd.hxx>

class AbstractProperty
{
public:
    explicit AbstractProperty();
    virtual ~AbstractProperty();

    void setName(const QString& n);

    QString name() const;
    QString valueToString() const;
    QString toString() const;

protected:
    virtual QString implName() const = 0;
    virtual QString implValueToString() const = 0;
    virtual QString implToString() const = 0;
};

#endif // ABSTRACTPROPERTY_HXX
