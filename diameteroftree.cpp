//Q-> calculate the diameter of a tree 
#include<iostream>
using namespace std;

struct Node{
    int  data;
    Node*left;
    Node*right;
    Node(int val){
      data =  val;
      left = right = nullptr;
    }
};

int height(Node*root){
    int x = height(root->left);
     int y= height(root->right);
     return max(x,y)+1 ;
}

int diameter(Node*root){
    int x = height(root->left);
     int y= height(root->right);
    int dia = x + y +2;
     int p = diameter(root->left);
     int q = diameter(root->right);

     return max(dia , max(p,q));
}