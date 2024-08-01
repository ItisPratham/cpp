//
//  Created by Pratham Shah on 1/8/24.
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

void PrintLinkedlist(Node* head){
    Node* temp = head;
    while (temp != NULL) {
        cout<<temp->data<<"\t";
        temp = temp->next;
    }
    cout<<endl;
}

void InsertAtBeginning(Node* head, int data){
    Node* n = new Node(data);
    n->next = head;
    head = n;
    PrintLinkedlist(head);
}

void InsertAtEnd(Node* head, int data){
    Node* n = new Node(data);
    if (head != NULL){
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = n;
    }
    else {
        head = n;
    }
    PrintLinkedlist(head);
}

void InsertInTheMiddle(Node* head, int data, int index){
    int t = 0;
    if (index >= 0){
        Node* n = new Node(data);
        Node* temp = head;
        for(int count = 0; count < index-1; count++){
            if(temp != NULL){
                temp = temp->next;
            }
            else {
                cout<<"List Index Out of Range"<<endl;
                t = 1;
                break;
            }
        }
        if (temp != NULL){
            Node* temp2 = temp->next;
            temp->next = n;
            n->next = temp2;
        }
        else{
            temp = n;
        }
    }
    else{
        cout<<"Enter a Non-Negative Index Number"<<endl;
        t = 1;
    }
    if(t==0){
        cout<<"New List is "<<endl;
        PrintLinkedlist(head);
    }

}

void AppendTwoList(Node* head1, Node* head2){
    if (head1 != NULL){
        Node* temp = head1;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = head2;
    }
    else {
        head1 = head2;
    }
    PrintLinkedlist(head1);
}

void SumofLinkedList(Node* head){
    int sum = 0;
    Node* temp = head;
    while(temp!=NULL){
        sum += temp->data;
        temp = temp->next;
    }
    cout<<"The sum is "<<sum<<endl;
}

void IsSameList(Node* head1, Node* head2){
    Node* temp1 = head1;
    Node* temp2 = head2;
    int t = 0;
    while(temp1 != NULL and temp2 != NULL){
        if (temp1->data != temp2->data){
            t = 1;
            break;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    if(t == 0 && temp1 == NULL && temp2 == NULL){
        cout<<"The lists are same"<<endl;
    }
    else{
        cout<<"The lists are not same"<<endl;
    }
}

int main() {
    Node* head1 = NULL;
    InsertAtEnd(head1, 2);
    InsertAtEnd(head1, 3);
    InsertAtBeginning(head1, 0);
    InsertInTheMiddle(head1, 4, 2);
    
    Node* head2 = new Node(1);
    InsertAtEnd(head2, 2);
    InsertAtEnd(head2, 3);
    
    AppendTwoList(head1, head2);
    SumofLinkedList(head1);
    IsSameList(head1, head2);

    return 0;
}