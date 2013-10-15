#ifndef ABSTRACTNODE_HXX
#define ABSTRACTNODE_HXX

#include <DatabaseFwd.hxx>

#include <AbstractNodeFwd.hxx>

class AbstractNode
{
public:
    explicit AbstractNode();
    virtual ~AbstractNode();

    QString singular() const;
    QString plural() const;

    DatabaseP database() const;

    Id parentId() const;
    Id id() const;
    QString name() const;
    QString qualifiedName() const;
    QString comment() const;

    QString toString() const;

protected:
    virtual QString implSingular() const = 0;
    virtual QString implPlural() const = 0;

    virtual DatabaseP implDatabase() const = 0;

    virtual Id implParentId() const = 0;
    virtual Id implId() const = 0;
    virtual QString implName() const = 0;
    virtual QString implQualifiedName() const = 0;
    virtual QString implComment() const = 0;

    virtual QString implToString() const = 0;
};

#endif // ABSTRACTNODE_HXX
