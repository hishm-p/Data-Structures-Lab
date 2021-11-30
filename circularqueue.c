#include<stdio.h>
#define MAX 6
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
   printf("Enter the value to enqueue:- ");
   scanf("%d",&item);
  if(front==(rear+1)%MAX)
   {
     printf("\nThe Queue is full\n");
   }
  else
  { 
    if(front==-1 && rear==-1)
       {
        front=0;
	rear=0;
        queue[rear]=item;
       }
   else if(rear==MAX-1 && front!=0)
       {
        rear=0;
	queue[rear]=item;
       } 
    else
       {
        rear=(rear+1)%MAX;
        queue[rear]=item;
       }
  }
    display();
 }
 
void dequeue()
  {
    int value;
    if(front==-1 && rear==-1)
      {
       printf("\nUnderflow\n");
      }
    else
     {
       value=queue[front];
       if(front==rear)
         {
          printf("%d was deleted successfully",value);
          front=-1;
	  rear=-1;
         }
       else if(front==MAX-1)
         {
	  printf("%d was deleted successfully",value);
          front=0;
         }
       else
         {
          printf("%d was deleted successfully",value);
          front=(front+1)%MAX;
         }	
      }   
    display();
  }  

void display() 
  {
   if(front==-1)
     {
       printf("\nThe Queue is Empty\n");
     }
   else if(front>rear)
     { 
       printf("\nThe Queue is:- ");
       for(int i=front;i<MAX;i++)
         {
           printf("%d  ",queue[i]);
         }
       for(int i=0;i<=rear;i++)
         {
           printf("%d  ",queue[i]);
         }
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
