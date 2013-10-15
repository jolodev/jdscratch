#ifndef DATATYPE_HXX
#define DATATYPE_HXX

#include <InDatabaseNode.hxx>

class DataType : public InDatabaseNode
{
public:
    static QString staticSingular();
    static QString staticPlural();

    explicit DataType(DatabaseP db = nullptr, const Id& parentId = Id(), const Id& id = Id(), const QString& n = "", const QString& c = "");
    virtual ~DataType();

protected:
    QString implSingular() const override;
    QString implPlural() const override;
};

#endif // DATATYPE_HXX
