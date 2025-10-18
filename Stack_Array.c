/*EXPERIMENT : 06
Name : Shrusti Moon
Roll no : UEC2024145

Expt 6 : Develop  a program to model an array as stack.
*/

#include<stdio.h>
#define MAX 10

struct stack {
   int stk[MAX];
   int top;
};

// Display function :
void display (struct stack st) {
if (st.top == -1) {
printf("Stack is Empty\n");
}
    else {
printf("Stack elements: ");
for(int i = st.top; i>=0; i--) {
printf("%d ",st.stk[i]);
}
printf("\n");
}
}


int main() {
struct stack st;
st.top = -1;
int choice, num ;

while (choice!=3) {
printf("STACK MENU :\n");
printf("1. PUSH\n");
printf("2. POP\n");
printf("3. EXIT\n");
printf("Enter your choice: ");
scanf("%d",&choice);

switch(choice) {
case 1 : // Push
            if(st.top == MAX-1) {
               printf("Stack is Full !");
}
            else {
               printf("Enter the element to push: ");
  scanf("%d",&num);
               st.top ++;
               st.stk[st.top] = num ;
               printf("\nStack elements : ");
               display(st);
}
            break;

        case 2 : //Pop
           if(st.top == -1) {
              printf("Stack is Empty !");
           }
           else {
  num = st.stk[st.top];
  st.top--;
  printf("Popped element : %d",num);
  printf("Stack elements : ");
  display(st);
  }
  break;
 
case 3: //Exit
  printf("Exiting program...\n");
  break ;

        default :
           printf("Invalid choice! Try Again.\n") ;
}
}
return 0;
}

/* OUTPUT :
STACK MENU :
1. PUSH
2. POP
3. EXIT
Enter your choice: 1
Enter the element to push: 2

Stack elements : Stack elements: 2
STACK MENU :
1. PUSH
2. POP
3. EXIT
Enter your choice: 1
Enter the element to push: 5

Stack elements : Stack elements: 5 2
STACK MENU :
1. PUSH
2. POP
3. EXIT
Enter your choice: 1
Enter the element to push: 3

Stack elements : Stack elements: 3 5 2
STACK MENU :
1. PUSH
2. POP
3. EXIT
Enter your choice: 1
Enter the element to push: 6

Stack elements : Stack elements: 6 3 5 2
STACK MENU :
1. PUSH
2. POP
3. EXIT
Enter your choice: 1
Enter the element to push: 7

Stack elements : Stack elements: 7 6 3 5 2
STACK MENU :
1. PUSH
2. POP
3. EXIT
Enter your choice: 1
Enter the element to push: 4

Stack elements : Stack elements: 4 7 6 3 5 2
STACK MENU :
1. PUSH
2. POP
3. EXIT
Enter your choice: 1
Enter the element to push: 2

Stack elements : Stack elements: 2 4 7 6 3 5 2
STACK MENU :
1. PUSH
2. POP
3. EXIT
Enter your choice: 2
Popped element : 2Stack elements : Stack elements: 4 7 6 3 5 2
STACK MENU :
1. PUSH
2. POP
3. EXIT
Enter your choice: 2
Popped element : 4Stack elements : Stack elements: 7 6 3 5 2
STACK MENU :
1. PUSH
2. POP
3. EXIT
Enter your choice: 3
Exiting program...
*/

 