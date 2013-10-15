#ifndef DATABASE_HXX
#define DATABASE_HXX

#include <Node.hxx>

class Database : public Node
{
public:
    static QString staticSingular();

    explicit Database(const QString& n, const QString& c);
    virtual ~Database();

private:
    QString implSingular() const override;
};

#endif // DATABASE_HXX
