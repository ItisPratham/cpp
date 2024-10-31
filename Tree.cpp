//
// Created Pratham Shah on 29/9/24
//

#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* right;
    Node* left;

    Node(int data){
        this->data = data;
        this->right = nullptr;
        this->left = nullptr;
    }
};

class Tree{
private:
    Node* root;

    Node* findNode(Node* node, int data){
        if(node == nullptr){
            return nullptr;
        }
        if(node->data == data){
            return node;
        }
        Node* leftnew = findNode(node->left, data);
        if(leftnew != nullptr){
            return leftnew;
        }
        return findNode(node->right, data);
    }

    void inorderTraversal(Node* node) {
        if (node != nullptr) {
            inorderTraversal(node->left);
            cout<<node->data<<" ";
            inorderTraversal(node->right);
        }
    }

    void preorderTraversal(Node* node){
        if(node!= nullptr){
            cout<<node->data<<" ";
            preorderTraversal(node->left);
            preorderTraversal(node->right);
        }
    }

    void postorderTraversal(Node* node){
        if(node!= nullptr){
            postorderTraversal(node->left);
            postorderTraversal(node->right);
            cout<<node->data<<" ";
        }
    }

    void levelorderTraversal(Node* node) {
        if (node == nullptr) return;

        queue<Node*> q;
        q.push(node);

        while (!q.empty()) {
            Node* current = q.front();
            cout << current->data << " ";
            q.pop();

            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }
    }

public:
    Tree(int data){
        root = new Node(data);
    }

    void insertLeftChild(int parentData, int childData){
        Node* parent = findNode(root, parentData);
        if(parent != nullptr){
            if(parent->left == nullptr){
                parent->left = new Node(childData);
                cout<<"Data inserted successfully"<<endl;
            }
            else{
                cout<<"Left child is already present"<<endl;
            }
            return;
        }
        cout<<"Parent node not found"<<endl;
        return;
    }

    void insertRightChild(int parentData, int childData){
        Node* parent = findNode(root, parentData);
        if(parent != nullptr){
            if(parent->right == nullptr){
                parent->right = new Node(childData);
                cout<<"Data inserted successfully"<<endl;
            }
            else{
                cout<<"Right child is already present"<<endl;
            }
            return;
        }
        cout<<"Parent node not found"<<endl;
        return;
    }

    void displayInorder() {
        cout<<"Inorder traversal: ";
        inorderTraversal(root);
        cout<<endl;
    }

    void displayPreorder(){
        cout<<"Preorder traversal: ";
        preorderTraversal(root);
        cout<<endl;
    }

    void displayPostorder(){
        cout<<"Postorder traversal: ";
        postorderTraversal(root);
        cout<<endl;
    }

    void displayLevelorder(){
        cout<<"Levelorder traversal: ";
        levelorderTraversal(root);
        cout<<endl;
    }
};

int main() {
    Tree* t = new Tree(10);
    t->insertLeftChild(10, 8);
    t->insertLeftChild(8, 7);
    t->insertLeftChild(7, 6);
    t->insertRightChild(8, 9);
    t->insertRightChild(10, 11);
    t->insertRightChild(11, 12);

    t->displayInorder();
    t->displayPostorder();
    t->displayPreorder();
    t->displayLevelorder();

    return 0;
}