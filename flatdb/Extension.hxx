#ifndef EXTENSION_HXX
#define EXTENSION_HXX

#include <InSchemaNode.hxx>

class Extension : public InSchemaNode
{
public:
    static QString staticSingular();
    static QString staticPlural();

    explicit Extension(DatabaseP db = nullptr, const Id& parentId = Id(), const Id& id = Id(), const QString& n = "", const QString& c = "");
    virtual ~Extension();

protected:
    QString implSingular() const override;
    QString implPlural() const override;
};

#endif // EXTENSION_HXX
