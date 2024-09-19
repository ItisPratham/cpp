// https://www.hackerrank.com/contests/foundation-test-p-n/challenges/fraction-subtraction

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void stringfrac(string &s, int &num, int &den){
    string in;
    for(size_t i = 0; i < s.length(); i++){
        if(s[i] == '/'){
            num = stoi(in);
            in.clear();
        }
        else{
            in += s[i];
        }
    }
    if(!in.empty()){
        den = stoi(in);
    }
    else{
        den = 1;
    }
}

int gcd(int a, int b){
    while(b != 0){
        int temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}

void subtract(int num1, int den1, int num2, int den2){
    int num = num1*den2 - num2*den1;
    int den = den1*den2;
    int div = gcd(abs(num), abs(den));
    num /= div;
    den /= div;
    if(num == 0){
        cout<<"0"<<endl;
        return;
    }
    else if(den == 1){
        cout<<to_string(num)<<endl;
        return;
    }
    else{
        cout<<to_string(num)+'/'+to_string(den)<<endl;
    }
}

int main() {
    string a,b;
    cin>>a>>b;
    int an, bn, ad, bd;
    stringfrac(a, an, ad);
    stringfrac(b, bn, bd);
    subtract(an, ad, bn, bd);
    return 0;
}