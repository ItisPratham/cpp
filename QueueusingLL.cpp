//
//
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

class Queue {
private:
    Node* front;
    Node* rear;
public:
    bool isEmpty(){
        if(front == NULL){
            return true;
        }
        else{
            return false;
        }
    }
    void Enqueue(int data){
        Node* n = new Node(data);
        if(isEmpty()){
            front = n;
            rear = n;
        }
        else{
            rear->next = n;
            rear = rear->next;
        }
    }
    void dequeue(){
        if(isEmpty()){
            cout<<"Underflow"<<endl;
            return;
        }
        else{
            Node* temp = front;
            front = front->next;
            temp->next = NULL;
            cout<<temp->data<<" Data removed"<<endl;
            delete(temp);
        }
    }
    void peek(){
        if(isEmpty()){
            cout<<"No value in the queue"<<endl;
            return;
        }
        cout<<"Front most value is "<<front->data<<endl;
    }
    void size(){
        int count = 0;
        Node* temp = front;
        while(temp!= NULL){
            count++;
            temp = temp->next;
        }
        cout<<"Size of Queue is "<<count<<endl;
    }
    void display(){
        Node* temp = front;
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
            return;
        }
        while(temp!= NULL){
            cout<<temp->data<<"\t";
            temp=temp->next;
        }
        cout<<endl;
    }

};

int main(){
    Queue* q = new Queue();
    q->display();
    q->dequeue();
    q->Enqueue(1);
    q->peek();
    q->Enqueue(2);
    q->Enqueue(3);
    q->display();
    q->dequeue();
    q->size();
}