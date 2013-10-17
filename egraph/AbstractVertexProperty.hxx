#ifndef ABSTRACTVERTEXPROPERTY_HXX
#define ABSTRACTVERTEXPROPERTY_HXX

#include <AbstractVertexPropertyFwd.hxx>

class AbstractVertexProperty {
public:
    String name() const { return implName(); }
    String toString() const { return implToString(); }

protected:
    virtual String implName() const = 0;
    virtual String implToString() const = 0;

private:
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive& a, const unsigned int v)
    {
        (void) a;
        (void) v;
    }
};

BOOST_SERIALIZATION_ASSUME_ABSTRACT(AbstractVertexProperty)

BOOST_CLASS_VERSION(AbstractVertexProperty, 1)

#endif // ABSTRACTVERTEXPROPERTY_HXX
