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

void Mapper::createColumn(TableSP t, AbstractPropertySP p) {
    auto c = t->create<TableColumn, Table>(t, t->schema()->database()->makeIdentifier(p->name()));
    c->setTypeName(p->sqlTypeName());
    c->setNotNull(p->isMandatory());
    c->setRoles(p->roles());

    if (p->useValueAsStorageDefault()) {
        c->setDefaultExpression(QString("'%1'::%2").arg(p->valueToString()).arg(c->typeName()));
    }

    if (p->hasRole(PropertyRole::Version)) {
        c->setDefaultExpression("0");
    }

    if (p->hasRole(PropertyRole::Creation)) {
        c->setDefaultExpression("CURRENT_TIMESTAMP");
    }

    if (p->hasRole(PropertyRole::LastModification)) {
        c->setDefaultExpression("CURRENT_TIMESTAMP");
    }
}
