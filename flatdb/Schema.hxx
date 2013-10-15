#ifndef SCHEMA_HXX
#define SCHEMA_HXX

#include <InDatabaseNode.hxx>

#include <SchemaFwd.hxx>

class Schema : public InDatabaseNode
{
public:
    static QString staticSingular();
    static QString staticPlural();

    explicit Schema(DatabaseP db = nullptr, const Id& parentId = Id(), const Id& id = Id(), const QString& n = "", const QString& c = "");
    virtual ~Schema();

protected:
    QString implSingular() const override;
    QString implPlural() const override;
};

#endif // SCHEMA_HXX
