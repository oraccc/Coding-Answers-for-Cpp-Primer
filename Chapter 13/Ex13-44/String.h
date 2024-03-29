#ifndef STRING_H
#define STRING_H

#include <initializer_list>
#include <memory>
#include <string>

using namespace std;

class String 
{
public:
    typedef size_t size_type;
    typedef char *iterator;
    typedef const char *const_iterator;
    typedef char &reference;
    typedef const char &const_reference;

    String() : first_elem(nullptr), first_free(nullptr), cap(nullptr) { }
    String(const_iterator);
    String(initializer_list<char>);

    String(const String &);
    ~String();
    String &operator=(const String &);
    String &operator=(const_iterator);

    void push_back(const_reference);
    void pop_back();

    void reserve(size_type);
    void resize(size_type, const_reference = char());

    bool empty() const { return cbegin() == cend(); }
    size_type size() const { return first_free - first_elem; }
    size_type capacity() const { return cap - first_elem; }

    iterator begin() { return first_elem; }
    iterator end() { return first_free; }
    const_iterator begin() const { return first_elem; }
    const_iterator end() const { return first_free; }
    const_iterator cbegin() const { return begin(); }
    const_iterator cend() const { return end(); }

    string str() const;

private:
    static allocator<char> alloc;

    iterator first_elem;
    iterator first_free;
    iterator cap;

    void reallocate(size_type);
    void free();
};

#endif