//  Add two large numbers with the help of string.
//
//  Created by Pratham Shah on 15/07/24.
//

#include <bits/stdc++.h>
using namespace std;

string add(string num1, string num2){
    if (num1.size() < num2.size()) {
        add(num2, num1);
    }
    string result;
    int la = num1.size();
    int lb = num2.size();
    int diff = la - lb;
    int x = 0, z;
    for(int i = la-1; i >= 0; i--){
        if (i-diff >= 0){
            z = num1[i] + num2[i-diff] -  2*'0' + x;
        }
        else{
            z = num1[i] - '0' + x;
        }
        result += z%10 + '0';
        x = z/10;
    }
    if(x == 1)
    {
        result += x+'0';
    }
    reverse(result.begin(), result.end());
    return result;
}

int main(){
    string num1, num2;
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;

    string result = add(num1, num2);
    printf("\n\nResult is : %s", result.c_str());
}