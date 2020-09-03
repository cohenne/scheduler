#include "SharedPtr.h"

template<class T>
SharedPtr<T>::SharedPtr(SharedPtr& other) : _ptr(other.m_ptr), _count(other.m_count) {
    if(_count) {
       incCount();
    }
}

template <class T>
template <class U>
SharedPtr<T>::SharedPtr(const SharedPtr<U>& other) : _ptr(other._ptr) {
    _count = *(size_t**)((char *)&other + sizeof(T*));
    if(_count) {
        incCount();
    }
}


template<class T>
inline SharedPtr<T>& SharedPtr<T>:: operator=(const SharedPtr& other){
    if(*this != other){
        reset();
        _ptr = other.get();
        _count = other._count;
        incCount();
    }

    return *this;
}

template<class T>
template <class U>
inline SharedPtr<T>& SharedPtr<T>:: operator=(const SharedPtr<U>& other){
    if(*this != other){
        reset();
        _ptr = other.get();
        _count = *(size_t**)((char *)&other + sizeof(T*));
        incCount();
    }

    return *this;
}

template<class T>
void SharedPtr<T>::deallocate() {
    if(*_count == 0 && _ptr) {
        delete _ptr;
        delete _count;
    }
    _ptr = NULL;
    _count = NULL;
}


template<class T>
inline T* SharedPtr<T>::release(){
    T* temp = _ptr;
    _ptr = NULL;
    return temp;
}


template<class T>
void SharedPtr<T>::reset() {
    if(_count) {
        decCount();
        deallocate();
    }
}

template<class T>
void SharedPtr<T>::reset(T *ptr) {
    reset();
    if(ptr) {
        _ptr = ptr;
        _count = new size_t(1);
    }
}