#ifndef NODEPAYLOAD_HXX
#define NODEPAYLOAD_HXX

#include <AbstractNodePayload.hxx>

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

    virtual String implName() const override;
    virtual String implComment() const override;

private:
    AbstractNode* m_n { nullptr };
    String m_name;
    String m_comment;
};

#endif // NODEPAYLOAD_HXX
