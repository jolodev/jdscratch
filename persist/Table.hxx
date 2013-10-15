#ifndef TABLE_HXX
#define TABLE_HXX

#include <InSchemaNode.hxx>

#include <TableFwd.hxx>

class Table : public InSchemaNode
{
public:
    static QString staticSingular();

    explicit Table(AbstractNodeP p = nullptr, const QString& n = "", const QString& c = "");
    virtual ~Table();

protected:
    QString implSingular() const override;
};

#endif // TABLE_HXX
