#include<stdio.h>
#define MAX 50
int queue[MAX],rear=-1,front=-1;
void enqueue();
void dequeue();
void display();
void main()
 {
  int choice =0;  
  do     
    {   
        printf("\nChoose the desired operation for your Queue:- \n");  
        printf("\n===============================================\n");  
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");  
        printf("\nEnter your choice?\n");         
        scanf("\n%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            enqueue();      
            break;  
            case 2:  
            dequeue();         
            break;  
            case 3:  
            display();       
            break;
	}
    }while(choice != 4);
 }
 
void enqueue()
 {
  int item;
  if(rear==MAX-1)
   {
     printf("\nThe Queue is full\n");
   }
  else
  { 
    if(front==-1)
       front=0;
    printf("Enter the value to enqueue:- ");
    scanf("%d",&item);
    rear=rear+1;
    queue[rear]=item;
  }
   display();
 }
 
void dequeue()
  {
    int value;
    if(front==-1 || front>rear)
      {
       printf("\nUnderflow\n");
      }
    else
     {
       value=queue[front];
       front=front+1;
       printf("%d was deleted successfully",value);
      }   
     display();
  }  

void display() 
  {
   if(front==-1 || front>rear)
     {
       printf("\nThe Queue is Empty\n");
     }
   else
     {
      printf("\nThe Queue is:- ");
      for(int i=front;i<=rear;i++)
        {
         printf("%d  ",queue[i]);
        }
     }
  }
