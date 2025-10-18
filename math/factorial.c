/*
Program Name: Factorial of a number
Problem Statement: To find the factorial of a given non-negative integer.

Input Example:
Enter number: 7

Output Example:
Recursive is: 5040
Iterative is: 5040
*/

#include <stdio.h>

// For Iterative
// Time Complexity: O(n)
// Space Complexity: O(1) 

int iterative(int n){
    int fact = 1;
    for(int i=1; i<=n; i++){
        fact *= i;
    }
    return fact;
}

// For Recursive
// Time Complexity: O(n)
// Space Complexity: O(n) 

int recursive(int n){
    if(n==0 || n==1) return 1;
    return n * recursive(n-1);
}


int main(){
    int num;
    printf("Enter number: ");
    scanf("%d",&num);
    printf("Iterative is: %d\n",iterative(num)); 
    printf("Recursive is: %d",recursive(num));
    return 0;
}
