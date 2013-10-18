#ifndef FORMATTER_HXX
#define FORMATTER_HXX

#include "AbstractFormater.hxx"

#include "AbstractFormatDialect.hxx"

namespace EGraph  {
template<typename FormaterT>
class Formater: public AbstractFormater {
public:
    explicit Formater()
        : AbstractFormater() {}

    virtual ~Formater() {}

    String present(VertexSP v, EdgeSPV in, EdgeSPV out) {
        return dialect()->present(v, in, out);
    }

protected:
    AbstractFormatDialect* dialect() { return &m_f; }

private:
    FormaterT m_f { FormaterT() };
};
}

#endif // FORMATTER_HXX
