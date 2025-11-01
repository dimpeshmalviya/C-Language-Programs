//string streamclass treats all the strings present in astring as a string
//for example print aa the words in a string sepaartely in different lines

//step1->take a temp string
//step->2 put the value of string str in stringstream ss
//step->3 use a while loop where we insert the value the string stream in temp string

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
      string str ="the weather is great today.";

      stringstream ss(str);
      string temp;

      while(ss>>temp){
        cout<<temp<<endl;
      }
}