//q->to check if the given string is an anagram or not
//step-1 make sure to make all the alphates to upper case or lowercase 
//step->2 sort the string 1 and string 2
//step->3 compare them if equal then anagram if not then not
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s1 = "leetcode";
    string s2 = "codeleet";
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    if(s1==s2){
        cout<<"it is anagram";
    }
    else{
        cout<<"it is not an anagram";
    }
}