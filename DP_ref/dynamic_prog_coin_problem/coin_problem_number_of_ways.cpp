#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int> v){
    for (int i =0;i<v.size();i++){
        cout<< v[i] << " ";
    }
    cout<<"\n";
}

int returnNumberofWays(int N, vector<int> coins){
    vector<int> ways(N+1);
    ways[0]=1;

    for(int i = 0; i<coins.size();i++){
        for (int j =0;j<ways.size();j++){
            if(j>=coins[i]){
                ways[j]+=ways[j - coins[i]];
            }
        }
        printArray(ways);
    }
    return ways[N];

}

int main(){
vector<int> coins;
int N = 10;
int c[] = {1,5,10};
int len = sizeof(c)/sizeof(c[0]);
for (int i =0;i<len;i++){
    coins.push_back(c[i]);
}
//coins =  {1,5,10};  

cout << returnNumberofWays(N, coins);
return 0;

}