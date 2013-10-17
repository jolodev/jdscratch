#ifndef NODEPAYLOAD_HXX
#define NODEPAYLOAD_HXX

#include <AbstractNodePayload.hxx>

#include <Tools.hxx>

class NodePayload : public AbstractNodePayload
{
public:
    static String singular() { return "Node Payload"; }

    explicit NodePayload(AbstractNode* n = nullptr);
    virtual ~NodePayload();

protected:
    AbstractNode* implNode() const override;

    virtual void implSetName(const String& n) override;
    virtual void implSetComment(const String& c) override;

    virtual Id implId() const override;
    virtual String implName() const override;
    virtual String implComment() const override;
    virtual String implToString() const override;

private:
    AbstractNode* m_n { nullptr };
    Id m_id { invalidId() };
    String m_name;
    String m_comment;
};

#endif // NODEPAYLOAD_HXX
