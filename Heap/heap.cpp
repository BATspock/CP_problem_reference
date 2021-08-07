#include<bits/stdc++.h>
#include "heapify.hpp"

int main(){

    std::vector<int> arr {4, 6, 2, 4, 1, 7, 10, 5};

    Heapify obj;
    std::vector<int> a = obj.heapify(arr);

    std::cout<<"\nAfter heapify: \n";

    for (auto c: a){
        std::cout<<c<<'\t';
    }

    return 0;
}