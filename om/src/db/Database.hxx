#ifndef DATABASE_HXX
#define DATABASE_HXX

#include <db/AbstractDbNode.hxx>

#include <obj/AbstractObject.hxx>
#include <obj/AbstractProperty.hxx>

class Database : public AbstractDbNode
{
public:
    static QString dataSchemaName();
    static QString auditSchemaName();

    explicit Database(const QString& name);
    virtual ~Database();

protected:
    AbstractDbNode* implParent() const override;
    QString implName() const override;
    QString implQualifiedName() const override;

private:
    QString m_name;
};

#endif // DATABASE_HXX
