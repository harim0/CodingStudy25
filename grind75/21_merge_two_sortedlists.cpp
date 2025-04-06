// 21. Merge Two Sorted Lists
// https://leetcode.com/problems/merge-two-sorted-lists/description/

#include <iostream>
#include <vector>

using namespace std; 

// Definition for singly-linked list.

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode merged;
        ListNode* temp = &merged;
            while(list1&&list2){
                if(list1->val<=list2->val){
                    temp->next = new ListNode(list1->val);
                    list1 = list1->next;
                }else{
                    temp->next = new ListNode(list2->val);
                    list2 = list2->next;
                }
                temp = temp->next;
            }
            while(list1){
                temp->next = new ListNode(list1->val);
                list1 = list1->next;
                temp = temp->next;
            }
            while(list2){
                temp->next = new ListNode(list2->val);
                list2 = list2->next;
                temp = temp->next;
            }
        return merged.next;
    }
};

int main(){
    Solution* sol = new Solution();
    ListNode* l1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode* l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode* result = sol->mergeTwoLists(l1, l2);
    while(result!=nullptr){
        cout<<result->val<<" ";
        result = result->next;
    }
    cout<<endl;
}