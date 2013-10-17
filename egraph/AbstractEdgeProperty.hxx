#ifndef ABSTRACTEDGEPROPERTY_HXX
#define ABSTRACTEDGEPROPERTY_HXX

#include <AbstractEdgePropertyFwd.hxx>

class AbstractEdgeProperty {
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

BOOST_SERIALIZATION_ASSUME_ABSTRACT(AbstractEdgeProperty)

BOOST_CLASS_VERSION(AbstractEdgeProperty, 1)

#endif // ABSTRACTEDGEPROPERTY_HXX
