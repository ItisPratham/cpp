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

class Stack {
private:
    Node* head;
    Node* top;
    int s;
public:
    Stack(){
        head = NULL;
        top = head;
        s = 0;
    }

    void push(int val){
        Node* n = new Node(val);
        if(top == NULL){
            head = n;
            top = n;
        }
        else{
            top->next = n;
            n->prev = top;
            top = n;
        }
        s++;
    }
    int pop(){
        if(top == NULL){
            cout<<"Underflow"<<endl;
            return -1;
        }
        Node* temp = top;
        top = temp->prev;
        top->next = NULL;
        int a = temp->data;
        delete(temp);
        if(top == NULL){
            head = NULL;
        }
        s--;
        return a;
    }
    void topele(){
        cout<<top->data<<endl;
    }
    void size(){
        cout<<"Size is "<<s<<endl;
    }
};

int main(){
    Stack* s = new Stack();
    s->push(1);
    s->push(2);
    s->topele();
    s->push(3);
    s->size();
    int val = s->pop();
    cout<<val<<endl;
}