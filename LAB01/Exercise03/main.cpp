#include "collection.hpp"
using namespace std;

int main() {
    Collection<int> c;

    c.insert(10);
    c.insert(20);
    c.insert(30);

    cout << "The collection elements are: ";
    c.display();

    cout << "Does the collection contains 10?" << (c.contains(10) ? " Yes" : " No") << endl;

    c.remove(10);
    cout << "Element" << 10 << "is removed" << endl;
    cout << "Does the collection contains 10?" << (c.contains(10) ? " Yes" : " No") << endl;

    c.makeEmpty();
    cout << "Is the collection empty? " << (c.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
