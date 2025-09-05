#ifndef E4FA0010_69C0_4578_B987_FC912156F7D5
#define E4FA0010_69C0_4578_B987_FC912156F7D5

template<typename T>
class Collection {
private:
    private:
    T* arr;          // Pointer to dynamic array
    int capacity;    // Maximum size
    int size;        // Current size
    void resize();

public:
    Collection();
    Collection(int cap);

    ~Collection();

    bool isEmpty() const;

    void makeEmpty();

    void insert(const T& x);

    void remove(const T& x);

    bool contains(const T& x) const;

    void display() const;
};

#include "collection.tpp"

#endif /* E4FA0010_69C0_4578_B987_FC912156F7D5 */

