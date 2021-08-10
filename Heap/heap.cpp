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

    std::vector<int> heapifyarray(){
        Heapify obj;
        this->ar =  obj.heapify(this->ar);
        return this->ar;
    }

    int delete_top_and_return(){

        int var = this->ar.front();
        int last = this->ar[this->ar.size()-1];
        this->ar[0] = last;
        this->ar.erase(this->ar.begin()+(this->ar.size()-1));
        this->print_array();
        Heapify obj;
        this->ar = obj.heapify(this->ar);
        return var;

    }
};


int main(){

    std::vector<int> arr {4, 6, 2, 14, 1, 7, 10, 5};

    HeapSort obj(arr);
    

    std::vector<int> a = obj.heapifyarray();

    obj.print_array();

    for (int i = 0;i<arr.size();i++){
        std::cout<<"iteration: "<<i+1<<'\t'<<"array: ";
        int junk = obj.delete_top_and_return();
        obj.print_array();
        //std::cout<<junk<<'\n';
    }
    
    return 0;
}