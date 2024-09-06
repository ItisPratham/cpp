//
// Created Pratham Shah on 4/9/24
//

#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};


class DoubleLL {
private:
    Node* head;

public:
    DoubleLL(){
        head = NULL;
    }

    void display(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<"\t";
            temp = temp->next;
        }
        cout<<endl;
    }

    void count(){
        Node* temp = head;
        int count = 0;
        while(temp!=NULL){
            count+=1;
            temp = temp->next;
        }
        cout<<"Count is "<<count<<endl;
    }

    void insertAtBeginning(int data){
        Node* n = new Node(data);
        if(head != NULL){
            head->prev = n;
        }
        n->next = head;
        head = n;
    }

    void insertAtEnd(int data){
        Node* n = new Node(data);
        if (head == NULL){
            head = n;
        }
        else{
            Node* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            n->prev = temp;
            temp->next = n;
        }
    }

    void insertAtMiddle(int data, int index){
        if(index<0){
            cout<<"Enter a non negative index"<<endl;
            return;
        }
        if(index == 0){
            insertAtBeginning(data);
            return;
        }
        Node* temp = head;
        for(int i = 0; i<index-1; i++){
            if(temp == NULL){
                cout<<"Index out of range"<<endl;
                return;
            }
            else{
                temp = temp->next;
            }
        }
        if(temp == NULL){
            cout<<"Index out of range2"<<endl;
            return;
        }
        Node* n = new Node(data);
        if(temp->next!= NULL){
            n->next = temp->next;
            temp->next->prev = n;
        }
        temp->next = n;
        n->prev = temp;
    }

    void SumofLinkedList(){
        int sum = 0;
        Node* temp = head;
        while(temp!=NULL){
            sum += temp->data;
            temp = temp->next;
        }
        cout<<"The sum is "<<sum<<endl;
    }
};

int main(){
    DoubleLL* a = new DoubleLL();
    a->insertAtBeginning(1);
    a->insertAtBeginning(5);
    a->insertAtEnd(2);
    a->insertAtMiddle(10, 2);
//    a->insertAtBeginning(4);
    a->display();
//    a->count();
    a->insertAtEnd(9);
    a->display();
    a->insertAtMiddle(99, 5);
    a->display();
    a->SumofLinkedList();
//    a->count();
}