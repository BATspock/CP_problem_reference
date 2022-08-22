#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {};
    ListNode(int x): val(x), next(nullptr) {};
    ListNode(int x, ListNode* next) : val(x), next(next) {};
};

class Solution {
    public:
    ListNode *longest_list(ListNode* head){
        int len = 1, maxseen = 1;
        ListNode *first = head;
        ListNode *second = head;
        ListNode *ans = head;
        ListNode *tail = head;

        int comp = first->val;

        while(second->next!= nullptr){
            second = second->next;      
            if (second->val <= comp){
               len++;
               if (len>maxseen){
                    ans = first; 
                    tail = second;
                    maxseen = len;
               }
                 
            }

            else {
                first = second;
                len = 1;
            }


            if (second) comp = second->val;
        }

        if (tail) tail->next = nullptr;

        return ans;
    }
};





int main(){

    ListNode *head = new ListNode(3);
    ListNode *temp = new ListNode(2);
    ListNode *temp2 = new ListNode(1);
    ListNode *temp3 = new ListNode(4);
    head->next = temp;
    temp->next = temp2;
    temp2->next = temp3;

    Solution object;

    ListNode *start = object.longest_list(head);

    while (head != nullptr){
        cout<<head->val <<" ";
        head = head->next;
    }

    return 0;
}