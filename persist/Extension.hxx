#ifndef EXTENSION_HXX
#define EXTENSION_HXX

#include <InSchemaNode.hxx>

#include <ExtensionFwd.hxx>

class Extension : public InSchemaNode
{
public:
    static QString staticSingular();

    explicit Extension(AbstractNodeP p = nullptr, const QString& n = "", const QString& c = "");
    virtual ~Extension();

protected:
    QString implSingular() const;
};

#endif // EXTENSION_HXX
