/*In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.

For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. These are the only nodes with twins for n = 4.
The twin sum is defined as the sum of a node and its twin.

Given the head of a linked list with even length, return the maximum twin sum of the linked list.

p.s: The input would be given as a comma seperated numbers, make sure you create a single linkedlist out of that first

Input Format

5,4,2,1

Constraints

n(list size) is always even

Output Format

6

Sample Input 0

1,-1,1,-1
Sample Output 0

0*/




#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;
    
    ListNode(int val){
        this->val = val;
        next = nullptr;
    }
};

ListNode* LL(vector<int>& arr) {

    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;

    for (size_t i = 1; i < arr.size(); i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

void maxsum(ListNode* head){
    stack<int> start;
    
    ListNode* slow = head;
    ListNode* fast = head;
    
    while(fast != NULL and fast->next != NULL){
        start.push(slow->val);
        slow = slow->next;
        fast = fast->next->next;
    }
    int maxv = start.top() + slow->val;
    slow = slow->next;
    start.pop();
    while(slow!=NULL){
        maxv = max(maxv, slow->val + start.top());
        slow = slow->next;
        start.pop();
    }
    cout<<maxv;
}

int main() {
    string s;
    cin>>s;
    vector<int> arr;
    string in;
    for(size_t i = 0; i<s.length(); i++){
        if(s[i] == ','){
            if(!in.empty()){
                arr.push_back(stoi(in));
                in.clear();
            }
        }
        else{
            in += s[i];
        }
    }
    
    if (!in.empty()) {
        arr.push_back(stoi(in));
    }

    ListNode* head = LL(arr);
    maxsum(head);
    
    return 0;
}
