//
//  Created by Pratham Shah on 3/8/24.
//

#include <bits/stdc++.h>

using namespace std;


int fibonacci(int n, int arr[]){
    if(arr[n] == -1){
        int temp = fibonacci(n-1, arr) + fibonacci(n-2, arr);
        arr[n] = temp;
        return temp;
    }
    else{
        return arr[n];
    }
}

int main(){
    int n;
    cout<<"Enter a number to find its fibonacci : ";
    cin>>n;
    int arr[n+1];
    memset(arr, -1, sizeof(arr));
    arr[0] = 0;
    arr[1] = 1;
    cout<<"Recursion value is "<<fibonacci(n, arr);
}