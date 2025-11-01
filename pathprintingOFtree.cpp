//q->print the path of root to the leaf node

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node*left;
    Node*right;
    Node(int val){
        data = val;
        left = right = nullptr;
    }
};
void printpath(Node*root , vector<int>&v){
    if(root == nullptr) return;
    v.push_back(root->data);
    if(root->left == nullptr && root->right == nullptr){
        for(int i= 0 ; i<v.size() ; i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    printpath(root->left,v);
        printpath(root->right,v);
        v.pop_back();
}

Node*insert(Node*root , int val){
    if (root == nullptr){
        return new Node(val);
    }
    if(val <root->data){
        root->left = insert(root->left , val);
    }
     else{
        root->right = insert(root->right , val);
    }
    return root;

}

int main(){
    vector<int>values;
    vector<int>v;
    int n;
    cout<<"enter the number of nodes";
    cin>>n;
    cout<<"enter n value";
    for(int i = 0 ;i<n ; i++){
        int val;
        cin>>val;
        values.push_back(val);
    }
    Node*root = nullptr;
    for(int val : values){
        root = insert(root , val);
    }
    printpath(root ,v);

}