#include "Tools.hxx"


Id invalidId()
{
    return 0;
}

Id createNodeId()
{
    static Id id = 0;
    return ++id;
}

bool isValidId(const Id &id)
{
    return (createNodeId() != id);
}

Id createEdgeId()
{
    static Id id = 0;
    return ++id;
}
