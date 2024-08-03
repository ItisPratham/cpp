#include <bits/stdc++.h>

using namespace std;

void recursion(int arr[], int index, int n){
    if(n > 1){
        n--;
        cout<<arr[index]<<"\t";
        recursion(arr, index+1, n);
    }
    else{
        cout<<arr[index];
    }
}

void sumoftheArray(int arr[], int n, int *sum){
    if(n > 1){
        n--;
        *sum += arr[n];
        sumoftheArray(arr, n, sum);
    }
    else{
        *sum += arr[0];
    }
}

int main(){
    int arr[5] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 0;
    recursion(arr, 0, n);
    sumoftheArray(arr, n, &sum);
    cout<<"\nSum of the array is "<<sum;
    return 0;
}