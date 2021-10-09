//
// Created by 裴沛东 on 2021/10/8.
//

#ifndef HEAP_HEAP_H
#define HEAP_HEAP_H
#include <vector>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <exception>
using std::vector;
using std::function;
using std::initializer_list;
using std::exception;
template<typename T>
class Heap {
public:
    Heap():_size(0),fun(std::greater<T>()){};
    Heap(function<bool(T&,T&)> fun);
    Heap(initializer_list<T> list, function<bool(T &, T &)> func);
    Heap(const Heap<T> &heap)  = delete;
    void operator=(const Heap<T> &heap) = delete;
    unsigned int size();
    bool empty();
    T top();
    void pop();
    void push(T value);
    void show();
private:
    unsigned int _size;
    vector<T> _data;
    function<bool(T&,T&)> fun;
    void HeapifyDown(int index);
    void Swap(int index1,int index2);
    void HeapifyUp(int index);

};

template<typename T>
Heap<T>::Heap(function<bool(T &, T &)> fun):_size(0) {
    this->fun = fun;
}
template<typename T>
Heap<T>::Heap(initializer_list<T> list, function<bool(T &, T &)> func):_size(list.size()),_data(list),fun(func) {
    for(int i=0;i<_size;++i) {
        HeapifyDown(i);

    }
    for(int index=0;index<_size;++index) {
        HeapifyUp(index);
    }

}
template<typename T>
unsigned int Heap<T>::size() {
    return _size;
}

template<typename T>
bool Heap<T>::empty() {
    return _size==0? true: false;
}
template<typename T>
T Heap<T>::top(){
    if(!empty()) {
        return _data[0];
    }else {
        std::cout<<"null"<<std::endl;
        throw std::out_of_range("the Heap is empty!!!!");
    }


}
template<typename T>
void Heap<T>::push(T value) {
    _data.push_back(value);
    ++_size;
    int index = _size-1;
    HeapifyUp(index);
}
template<typename T>
void Heap<T>::pop() {
    _data[0] = _data[_size-1];
    --_size;
    _data.pop_back();
    HeapifyDown(0);
}
template<typename T>
void Heap<T>::HeapifyDown(int index) {
    int left = index*2+1;
    while(left<_size) {
        int maxValue  = left+1 < _size && fun(_data[left+1],_data[left]) ? left+1:left;
        maxValue = fun(_data[index],_data[maxValue]) ? index:maxValue;
        if(maxValue == index) {
            break;
        }
        Swap(maxValue,index);
        index = maxValue;
        left = index*2+1;
    }


}
template<typename T>
void Heap<T>::HeapifyUp(int index) {
    while (_data[index] > _data[(index - 1) / 2]) {
        Swap(index, (index - 1) / 2);
        index = (index - 1) / 2;
    }

}
template<typename T>
void Heap<T>::Swap(int index1, int index2) {
    T temp = _data[index1];
    _data[index1] = _data[index2];
    _data[index2] = temp;
}
template<typename T>
void Heap<T>::show() {
    std::cout<<"heap size is:"<<_size<<std::endl;
    for(auto &i:_data) {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}


#endif //HEAP_HEAP_H
