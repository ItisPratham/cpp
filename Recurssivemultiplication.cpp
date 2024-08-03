//using recursion for reduced time complexity for multiplication.

#include <bits/stdc++.h>

using namespace std;

int recursion(int x, int n, int *count){
    *count += 1;
    if(n > 1){
        if(n%2 == 0){
            int s = recursion(x, n/2, count);
            return s*s;
            //return recursion(x, n/2, count)*recursion(x, n/2, count);
        }
        else{
            int s = recursion(x, n/2, count);
            return s*s*x;
            //return recursion(x, n/2, count)*recursion(x, n/2, count)*x;
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
    int count = 0;
    cout<<"Exponential "<<recursion(x, n, &count)<<"\nRecursion count is "<<count;
}