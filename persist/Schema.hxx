#ifndef SCHEMA_HXX
#define SCHEMA_HXX

#include <InDatabaseNode.hxx>

#include <SchemaFwd.hxx>
#include <TableFwd.hxx>

class Schema : public InDatabaseNode
{
public:
    static QString staticSingular();

    explicit Schema(AbstractNodeP p = nullptr, const QString& n = "", const QString& c = "");
    virtual ~Schema();

    TableSP createValueTable(const QString& n, const QString& c);

protected:
    QString implSingular() const override;
};

#endif // SCHEMA_HXX
