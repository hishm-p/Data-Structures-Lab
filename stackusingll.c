#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};

struct node* top=NULL;

void push(int val);
void pop();
void display();

void main()
 {
    int ch,val;
    printf("\t\t\t\tStack using Linked List\n");
    printf("\t\t\t\t-----------------------\n");
    do
     {
        printf("\nEnter your choice:\n1:Push\n2:Pop\n3:Display\n4:Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("\nEnter the value you want to push onto the stack:");
                    scanf("%d",&val);
                    push(val);
                    break;
            case 2:pop();
                   break;
            case 3:display();
                   break;
            case 4:exit(1);

            default : printf("Invalid Entry!");
                      break;
        }
     }while(ch!=5);
 }

void push(int val)
   {
       struct node* newnode;
       newnode=(struct node*)malloc(sizeof(struct node));
       newnode->data=val;
       newnode->link=NULL;

       newnode->link=top;
       top=newnode;
   }

void pop()
   {
       int val;
       struct node* temp;
       temp=(struct node*)malloc(sizeof(struct node));
       if(top == NULL)
        {
            printf("Stack Underflow");
        }
       else
       {
           val=top->data;
           temp=top;
           top=top->link;
           free(temp);
           printf("%d is popped",val);
       }
   }  

void display()
  {
      struct node* temp;
      if(top == NULL)
        {
            printf("The Stack is Empty!");
        }
      else
        {
            temp=top;
            printf("\nThe Stack Elements are:  ");
            while(temp != NULL)
            {
                printf("%d\t",temp->data);
                temp=temp->link;
            }
            printf("\n");
        }  
  }
