#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
int max = 0;
string s = "hello";
for(int i = 0 ;i<s.length();i++){
    int count = 1;
    for(int j = i+1 ; j<s.length() ;j++){
        if(s[j] == s[i])count++;
        if(max<count) max = count;
    }
}
cout<<max;
}