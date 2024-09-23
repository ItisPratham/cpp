//
// Created by Pratham Shah on 23/9/24
//


#include <iostream>
#include <stack>

using namespace std;

string rev(string& s){
    stack<char> stk;
    for(char c : s){
        stk.push(c);
    }
    string revString;
    while(!stk.empty()){
        revString += stk.top();
        stk.pop();
    }
    return revString;
}

int main(){
    string input;
    cout<<"Enter a string to be reversed: ";
    cin>>input;
    string reversed = rev(input);
    cout<<"Reversed string: "<<reversed<<endl;
    return 0;
}