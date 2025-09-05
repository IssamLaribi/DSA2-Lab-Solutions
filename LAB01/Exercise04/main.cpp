#include "ordered_collection.hpp"
using namespace std;

int main() {
    OrderedCollection<int> c;

    c.insert(10);
    c.insert(20);
    c.insert(30);
    c.insert(15); 

    cout << "The collection elements are: ";
    c.display();

    cout << "Does the collection contain 10?" 
         << (c.contains(10) ? " Yes" : " No") << endl;

    c.remove(10);
    cout << "Element " << 10 << " is removed" << endl;
    cout << "Does the collection contain 10?" 
         << (c.contains(10) ? " Yes" : " No") << endl;

    try {
        cout << "Min element is: " << c.findMin() << endl;
        cout << "Max element is: " << c.findMax() << endl;
    } catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }

    c.makeEmpty();
    cout << "Is the collection empty? " 
         << (c.isEmpty() ? "Yes" : "No") << endl;

    // Try min/max on empty collection
    try {
        cout << "Min element is: " << c.findMin() << endl;
    } catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }

    try {
        cout << "Max element is: " << c.findMax() << endl;
    } catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}

