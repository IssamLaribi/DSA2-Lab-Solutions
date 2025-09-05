#ifndef E4AB4CA7_94EA_4F95_8972_39D6C09E9C60
#define E4AB4CA7_94EA_4F95_8972_39D6C09E9C60

#include <vector>
using namespace std;

template <typename Comparable>
class OrderedCollection {
private: 
    vector<Comparable> data;
public: 
    OrderedCollection();

    bool isEmpty() const;
    void makeEmpty();
    void insert(const Comparable &x);
    void remove(const Comparable &x);

    Comparable& findMin(const Comparable &x);
    Comparable& findMax(const Comparable &x);

    bool contains(const Comparable& x) const;
    void display() const;
};

#include "ordered_collection.tpp"

#endif /* E4AB4CA7_94EA_4F95_8972_39D6C09E9C60 */

