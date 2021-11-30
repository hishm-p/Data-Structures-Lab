#include<stdio.h>
#define MAX 50
int stack[MAX],top=-1;
void push();
void pop();
void display();
void main()
 {
  int choice =0;  
  do     
    {   
        printf("\nChoose the desired operation for your stack:- \n");  
        printf("\n===============================================\n");  
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");  
        printf("\nEnter your choice?\n");         
        scanf("\n%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            push();      
            break;  
            case 2:  
            pop();         
            break;  
            case 3:  
            display();       
            break;
	}
    }while(choice != 4);
 }
 
void push()
 {
  int item;
  if(top==MAX)
   {
     printf("\nThe Stack is full\n");
   }
  else
  {
    printf("Enter the value to push:- ");
    scanf("%d",&item);
    top++;
    stack[top]=item;
  }
   display();
 }
 
void pop()
  {
    int data;
    if(top==-1)
      {
       printf("\nUnderflow\n");
      }
    else
     {
       data=stack[top];
       top--;
      }
     printf("%d was deleted successfully",data);   
     display();
  }  

void display() 
  {
   if(top==-1)
     {
       printf("\nThe Stack is Empty\n");
     }
   else
     {
      printf("\nThe Stack is:- ");
      for(int i=0;i<=top;i++)
        {
         printf("%d  ",stack[i]);
        }
     }
  }
