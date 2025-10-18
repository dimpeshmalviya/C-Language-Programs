#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;//itna hoga chip
    int top; // kon chips dal re 
    int * arr ; // ek chips ke baad ek saja dere h
};

int isEmpty(struct stack * ptr){
    if (ptr->top == -1)
    {
        return 1;
    }
    else{
        return 0;
    }
    
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1) //  size is 5 but index is from 0 to 4
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(){
    struct stack *s;
    s->size = 50;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
  // pushing element just now 
  s->arr[0] =2;
  s->top++;

  s->arr[1] = 3;
  s->top++;

  // Check if stack is empty
  if (isEmpty(s))
  {
      printf("The stack is empty");
  }
    else
    {
        printf("The stack is not empty");
    }

    return 0;
}
