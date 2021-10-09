//
// Created by 裴沛东 on 2021/10/8.
//
#include "Heap.h"

int main() {
    Heap<int> heap([](int &x1,int &x2) {
        return x1 > x2;
    });

    for(int i=0;i<10;++i) {
        heap.push(i);
    }
    heap.show();
    heap.pop();
    heap.show();
    std::cout<<heap.top()<<std::endl;
    Heap<int> heap1({9,10,5,3,4,2,1,8,7,6,0},[](int &x1,int &x2) {
        return x1 > x2;
    });
    heap1.show();
    std::cout<<heap1.top()<<std::endl;
    Heap<int> heap2;
    try{
        std::cout<<heap2.top();
    }
    catch(exception &e) {
        std::cout<<e.what()<<std::endl;
    }
}