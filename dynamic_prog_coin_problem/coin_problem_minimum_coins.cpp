#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int> v){
    for (int i =0;i<v.size();i++){
        cout<< v[i] << " ";
    }
    cout<<"\n";
}

int returnMinimumNumberofCoins(int N, vector<int> coins){
    vector<int> numberofcoins(N+1);
    numberofcoins.assign(N+1,INT_MAX);
    numberofcoins[0]=0;

    for(int i = 0; i<coins.size();i++){
        for (int j =0;j<numberofcoins.size();j++){
            if(j>=coins[i]){
                numberofcoins[j] = min(numberofcoins[j], 1 + numberofcoins[j-coins[i]]);
                //ways[j]+=ways[j - coins[i]];
            }
        }
        printArray(numberofcoins);
    }
    return numberofcoins[N];

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

cout << returnMinimumNumberofCoins(N, coins);
return 0;

}