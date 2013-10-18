#include "HtmlFormat.hxx"

#include <Graph.hxx>
#include <Vertex.hxx>
#include <Edge.hxx>
#include <VertexProperty.hxx>
#include <EdgeProperty.hxx>

using namespace EGraph;

HtmlFormat::HtmlFormat()
    : AbstractFormatDialect()
{
}

HtmlFormat::~HtmlFormat()
{

}

String HtmlFormat::implPresent(VertexSP v) const
{
    StringStream s;
    s << "<html>" << std::endl;
    s << "<head>" << std::endl;
    s << css();
    s << "<title>" << v->label() << " " << v->type()  << "</title>" << std::endl;
    s << "</head>" << std::endl;
    s << "<body>" << std::endl;
    s << "<h1>" << v->type() << " " << v->label() << " ";
    s << "<small>" << createLink(v, HtmlFormat::Show) << "/";
    s << createLink(v, HtmlFormat::Edit) << "/";
    s << createLink(v, HtmlFormat::Export) << "/";
    s << createLink(v, HtmlFormat::Delete) << "/";
    s << createLink(v, HtmlFormat::Create) << "</small>";
    s << "</h1>" << std::endl;
    s << "<h2>Properties</h2>" << std::endl;
    s << createPropertyTable(v);
    s << "<h2>Outbound Edges</h2>" << std::endl;
    s << createEdgesTable(v->graph()->edges(v, EdgeDirections::Out));
    s << "<h2>Inbound Edges</h2>" << std::endl;
    s << createEdgesTable(v->graph()->edges(v, EdgeDirections::In));
    s << "</body>" << std::endl;
    s << "</html>" << std::endl;

    return s.str();
}

String HtmlFormat::createPropertyTable(VertexSP v) const
{
    StringStream s;
    s << "<table border=\"1\">" << std::endl;
    s << "<tr><th>Property</th><th>Value</th></tr>" << std::endl;
    for (auto p : v->properties()) {
        s << "<tr><td>" << p->name() << "</td><td>" << p->valueToString() << "</td></tr>" << std::endl;
    }
    s << "</table>" << std::endl;

    return s.str();
}

String HtmlFormat::createEdgesTable(EdgeSPV v) const
{
    StringStream s;

    s << "<table border=\"1\">" << std::endl;
    s << "<tr><th>Left Vertex</th><th>Role</th><th>Right Vertex</th></tr>" << std::endl;

    for (auto e : v) {
        auto l = e->leftVertex();
        auto r = e->rightVertex();

        s << "<tr>";
        s << "<td>" << l->label() << " ";
        s << "<small>" << createLink(l, HtmlFormat::Show) << "/";
        s << createLink(l, HtmlFormat::Edit) << "/";
        s << createLink(l, HtmlFormat::Export) << "/";
        s << createLink(l, HtmlFormat::Delete) << "/";
        s << createLink(l, HtmlFormat::Create) << "</small>";
        s << "</td>";

        s << "<td>" << e->role() << "</td>";

        s << "<td>" << r->label() <<  " ";
        s << "<small>" << createLink(r, HtmlFormat::Show) << "/";
        s << createLink(r, HtmlFormat::Edit) << "/";
        s << createLink(r, HtmlFormat::Export) << "/";
        s << createLink(r, HtmlFormat::Delete) << "/";
        s << createLink(r, HtmlFormat::Create) << "</small>";
        s << "</td>";
        s << "</tr>" << std::endl;
    }

    s << "</table>" << std::endl;

    return s.str();
}

String HtmlFormat::createLink(VertexSP v, const String &action) const
{
    StringStream s;
    s << "<a href=\"egraph:///egraph?vertex_id=" << v->id() << "&action=" << action << "\">" << action << "</a>";
    return s.str();
}

String HtmlFormat::css() const {
    StringStream s;

    s << "<style type=\"text/css\">";
    s << "h1 {font-size:14px;color:#333333;}";
    s << "h2 {font-size:12px;color:#333333;}";
    s << "h3 {font-size:10px;color:#333333;}";
    s << "table {font-size:12px;color:#333333;border-width: 1px;border-color: #729ea5;border-collapse: collapse;}";
    s << "table th {font-size:12px;background-color:#acc8cc;border-width: 1px;padding: 8px;border-style: solid;border-color: #729ea5;text-align:left;}";
    s << "table tr {background-color:#d4e3e5;}";
    s << "table td {font-size:12px;border-width: 1px;padding: 8px;border-style: solid;border-color: #729ea5;}";
    s << "</style>";

    return s.str();
}
