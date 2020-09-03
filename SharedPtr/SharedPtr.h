
#ifndef SMART_POINTERS_SHAREDPTR_H
#define SMART_POINTERS_SHAREDPTR_H

#include <iostream>


template<class T/*, class D = DefualtDelete<T>*/ >
class SharedPtr{
public:

    SharedPtr<T>():_ptr(NULL), _count(NULL){}
    explicit SharedPtr<T>(T* ptr):_ptr(ptr), _count(new size_t(1)){}
    ~SharedPtr() {reset();}

    SharedPtr (SharedPtr& other);
    template <class U>
    SharedPtr(const SharedPtr<U>& other);


    SharedPtr<T>& operator=(const SharedPtr& other);
    template <typename U>
    SharedPtr<T>& operator=(const SharedPtr<U>& other);

    T* get()        const {return _ptr;}
    T& operator* () const {return *_ptr;}
    T* operator->() const {return _ptr;}
    explicit operator bool() const { return _ptr;}


    size_t* getCount() const{ return _count;}

    bool operator==(const SharedPtr<T>& other)const{return _ptr == other._ptr;}
    bool operator!=(const SharedPtr<T>& other)const{return _ptr != other._ptr;}

    T* release();
    void reset();
    void reset (T* ptr);

    bool unique()const{ return _count && 1 == *_count;}


private:
    T* _ptr;
    size_t* _count;

    void deallocate();
    void decCount(){--(*_count);}
    void incCount(){++(*_count);}
};


#include "SharedPtr.hpp"


#endif //SMART_POINTERS_SHAREDPTR_H
