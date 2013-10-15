#ifndef INTABLENODE_HXX
#define INTABLENODE_HXX

#include <Node.hxx>

#include <TableFwd.hxx>

class InTableNode : public Node
{
public:
    explicit InTableNode(AbstractNodeP p = nullptr, const QString& n = "", const QString& c = "");
    virtual ~InTableNode();

    TableP table() const;
};

#endif // INTABLENODE_HXX
