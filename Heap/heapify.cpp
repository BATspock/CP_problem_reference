#include<bits/stdc++.h>

class Heapify{

    public:
    std::vector<int> heapify(std::vector<int> arr){
        std:: vector<int> ans;

        //complete heapify bottom up 

    return ans;

    }
};

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
