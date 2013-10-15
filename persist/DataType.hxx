#ifndef DATATYPE_HXX
#define DATATYPE_HXX

#include <InDatabaseNode.hxx>

#include <DataTypeFwd.hxx>

class DataType : public InDatabaseNode
{
public:
    static QString staticSingular();

    explicit DataType(AbstractNodeP p = nullptr, const QString& n = "", const QString& c = "");
    virtual ~DataType();

protected:
    QString implSingular() const override;
};

#endif // DATATYPE_HXX
