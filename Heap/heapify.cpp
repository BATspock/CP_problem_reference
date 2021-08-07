#include<bits/stdc++.h>
#include "heapify.hpp"

using namespace std;

void Heapify::create_heap(std::vector<int> &a, int index){

    if (2*index+1 >= a.size()) return;
    
    int parent = a[index];
    int left_val = a[2*(index) + 1];
    int right_val = INT_MIN;

    if (2*index + 2 < a.size()) {right_val = a[2*index + 2];}

    int biggest_child = std::max(left_val, right_val);
    int parent_node = std::max(parent, biggest_child);

    if (parent_node == left_val){
        a[2*index +1] = parent;
        a[index] = left_val;
        create_heap(a, 2*index + 1);
    }

    if (parent_node == right_val){
        a[2*index +2] = parent;
        a[index] = right_val;
        create_heap(a, 2*index + 2);
    }

    return;

}

std::vector<int> Heapify::heapify(std::vector<int> arr){
        
    std:: vector<int> ans(arr);
    //complete heapify bottom up 
    for (int i = ans.size()-1;i>=0;i--){

        create_heap(ans,i);            

    }

    

return ans;

}

/*
int main(){
    std::vector<int> arr {4, 6, 2, 4, 1, 7, 10, 5};


    std::cout<<"\nBefore heapify: \n";
    for (auto c: arr){
        std::cout<<c<<'\t';
    }

    Heapify obj;
    std::vector<int> a = obj.heapify(arr);

    std::cout<<"\nAfter heapify: \n";

    for (auto c: a){
        std::cout<<c<<'\t';
    }

    return 0;
}
*/
