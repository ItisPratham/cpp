//
//  Created by Pratham Shah on 28/07/24.
//

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void printLL(Node* head){
    Node* temp = head;
    while (temp != NULL) {
        cout<<temp->data<<"\t";
        temp = temp->next;
    }
}

int main() {
    int n,d;
    cout<<"Enter number of elements of linked list : ";
    cin>>n;
    Node* head = NULL;
    Node* temp = NULL;
    while (n>0) {
        cout<<"Enter a num: ";
        cin>>d;
        if (head == NULL){
            Node* n1 = new Node(d);
            head = n1;
            temp = head;
        }
        else{
            temp->next = new Node(d);
            temp = temp->next;
        }
        n--;
    }
    printLL(head);
}