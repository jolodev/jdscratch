#include "Mapper.hxx"

Mapper::Mapper()
{
}

Mapper::~Mapper()
{
}

Mapper *Mapper::instance()
{
    static auto i = new Mapper();
    return i;
}
