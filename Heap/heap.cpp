#include<bits/stdc++.h>
#include "heapify.hpp"

class HeapSort{

public:
    std::vector<int> ar;

    HeapSort(std::vector<int> a){
        ar.assign(a.begin(), a.end());
    }

    void print_array(){
        for (auto c: this->ar){
            std::cout<<c<<'\t';
        }
        std::cout<<'\n';
    }
};


int main(){

    std::vector<int> arr {4, 6, 2, 4, 1, 7, 10, 5};

    Heapify obj;
    std::vector<int> a = obj.heapify(arr);

    std::cout<<"\nAfter heapify: \n";

    for (auto c: a){
        std::cout<<c<<'\t';
    }
    std::cout<<'\n';
    HeapSort obj2(a);
    HeapSort obj3(arr);

    obj2.print_array();
    obj3.print_array();


    return 0;
}