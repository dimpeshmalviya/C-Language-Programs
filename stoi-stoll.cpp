//stoi is a built in function used to convert the string to integer
//stol is a built in function used to convert the string to long long 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    string str1 = "12345";
    int x = stoi(str1);
    cout<<x+1<<endl;

    string str2 = "1234567898656";
    long long y = stoll(str2);
    cout<<y+1;
}