#ifndef OBJECT_HXX
#define OBJECT_HXX

#include <obj/AbstractObject.hxx>

class Object : public AbstractObject
{
public:
    explicit Object(const QUuid& id = OMTools::invalidId());
    virtual ~Object();

protected:
    QString implToString() const override;
    QUuid implId() const override;

private:
    QUuid m_id { OMTools::invalidId() };
};

#endif // OBJECT_HXX
