#ifndef HTMLFORMAT_HXX
#define HTMLFORMAT_HXX

#include "AbstractFormatDialect.hxx"

namespace EGraph {
class HtmlFormat : public AbstractFormatDialect
{
public:
    const String Show { "show" };
    const String Edit { "edit" };
    const String Delete { "delete" };
    const String Export { "export" };
    const String Create { "create" };

    explicit HtmlFormat();
    virtual ~HtmlFormat();

protected:
    virtual String implPresent(VertexSP v) const;

private:
    String css() const;
    virtual String createPropertyTable(VertexSP v) const;
    virtual String createEdgesTable(EdgeSPV v) const;

    String createLink(VertexSP v, const String& action) const;
};
}

#endif // HTMLFORMAT_HXX
