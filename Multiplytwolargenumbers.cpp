//
//  main.cpp
//  Multiplication of two large numbers[Stored in a string].
//
//  Created by Pratham Shah on 21/07/24.
//

#include <bits/stdc++.h>
using namespace std;

string add(string num1, string num2){
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

string mul(string num, char m){
    int l = num.size();
    int a = m - '0';
    int z;
    int x = 0;
    string result;
    for(int i = 0; i<l; i++){
        z = (num[l-i-1] - '0') * a + x;
        result += z%10 + '0' ;
        x = z/10;
    }
    if(x > 0){
        result += x + '0';
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
    
    int l2 = num2.size();
    string resultarray[l2];
    for(int i = 0; i < l2; i++){
        resultarray[i] = mul(num1, num2[l2-i-1]) + string(i, '0');
    }
    string ans = "0";
    for(int i = 0; i < l2; i++){
        ans = add(resultarray[i], ans);

    }
    cout<<ans<<"\n";
}