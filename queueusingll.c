#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};

struct node* front=NULL;
struct node* rear=NULL;

void enque(int val);
void deque();
void display();

void main()
 {
    int ch,val;
    printf("\t\t\t\tQueue using Linked List\n");
    printf("\t\t\t\t-----------------------\n");
    do
     {
        printf("\nEnter your choice:\n1:Enque\n2:Deque\n3:Display\n4:Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("\nEnter the value you want to push onto the queue:");
                    scanf("%d",&val);
                    enque(val);
                    break;
            case 2:deque();
                   break;
            case 3:display();
                   break;
            case 4:exit(1);

            default : printf("Invalid Entry!");
                      break;
        }
     }while(ch!=5);
 }

 void enque(int val)
   {
       struct node* newnode;
       newnode=(struct node*)malloc(sizeof(struct node));
       newnode->data=val;
       newnode->link=NULL;
       if(front == NULL && rear == NULL)
       {
           front=rear=newnode;
       }
       else
       {
           rear->link=newnode;
           rear=newnode;
       }
   }

void display()
  {
      struct node* temp;
      if(front == NULL)
        {
            printf("The Queue is Empty!");
        }
      else
        {
            temp=front;
            printf("\nThe Queue Elements are:  ");
            while(temp != NULL)
            {
                printf("%d\t",temp->data);
                temp=temp->link;
            }
            printf("\n");
        }  
  }

void deque()
  {
      int value;
      struct node* temp;
      temp=front;
      if(front == NULL)
        {
            printf("Queue Underflow");
        }
      else
        {
            value=front->data;
            front=front->link;
            free(temp);
            printf("\n%d was dequed.\n",value);
        }  
  }  
