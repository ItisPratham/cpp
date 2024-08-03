//using recursion for reduced time complexity for multiplication.

#include <bits/stdc++.h>

using namespace std;

int recursion(int x, int n){
    if(n > 1){
        if(n%2 == 0){
            int s = recursion(x, n/2);
            return s*s;
        }
        else{
            int s = recursion(x, n/2);
            return s*s*x;
        }
    }
    else{
        return x;
    }
}



int main(){
    int x, n;
    cout<<"Enter base : ";
    cin>>x;
    cout<<"Enter exponential : ";
    cin>>n;
    cout<<"Exponential "<<recursion(x, n);
}