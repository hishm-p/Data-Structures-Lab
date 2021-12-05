#include<stdio.h>
#include<stdlib.h>

struct node
{
 int data;
 struct node *link;
};
struct node *head=NULL;

void beginsert();
void lastinsert();
void randominsert();
void display();
void begdelete();
void randomdelete();
void lastdelete();

int count = 0;

void main()
{
 int op=0;
 printf("\n\t\t\t\tInsertion and Deletion in Linked List");
 printf("\n\t\t\t\t-------------------------------------");
 do
 {
 printf("\n\nEnter your choice\n1.Insert at beginnning \n2.Insert at last \n3.Insert at specific location \n4.Deletion from the beginning \n5.Deletion from a specific position \n6.Deletiom from the end \n7.Display \n8.Exit \n");
 scanf("%d",&op);
 
 switch(op)
 {
  case 1 : printf("\nInsertion at begin operation");
           beginsert();
           break;

  case 2 : printf("\nInsertion at last operation");
           lastinsert();   
           break;

  case 3 : printf("\nInsertion at a specific position");
           randominsert();
           break;

  case 4 : printf("\nDeletion at the beginning");
           begdelete();
           break;         
 
  case 5 : printf("\nDeletion after a specific position");
           randomdelete();
           break;

  case 6 : printf("\nDeletion from the end");
           lastdelete();
           break;         

  case 7 : printf("\nDisplaying the elements of linked list");
           display();
           break;

  case 8 : printf("\nExiting.......");
           exit(0);
           break;
          
  default : printf("\nInvalid input");
           break; 
 }
 
 }while(op!=8);

}

void beginsert()
{
 struct node *ptr;
 int item;
 printf("\nEnter the item to be inserted : ");
 scanf("%d",&item);
 ptr = (struct node*)malloc(sizeof(struct node*));
 ptr->data = item;
 ptr->link = head;
 head = ptr;
 printf("\nNode inserted");
count=count+1;
}

void lastinsert()
{
 struct node *ptr,*temp;
 int item;
 ptr = (struct node*)malloc(sizeof(struct node*));
 printf("\nEnter the item to be inserted : ");
 scanf("%d",&item);
 ptr->data = item;
 if(head==NULL)
 {
   ptr->link = NULL;
   head = ptr;
   printf("\nNode inserted"); 
   count=count+1;
 }
 else
 {
  temp=head;
  while(temp->link!=NULL)
  {
   temp = temp->link;
  }
  temp->link = ptr;
  ptr->link = NULL; 
  printf("\nNode inserted"); 
  count=count+1;
 }

}
void randominsert()
{
    struct node *ptr,*temp;
    int item,loc;
    ptr = (struct node*)malloc(sizeof(struct node*));  
    printf("\nEnter the location to be inserted : ");
    scanf("%d",&loc);
    printf("\nEnter the item  to be inserted : ");
    scanf("%d",&item);
    ptr->data=item;
    temp = head;
    for(int i=2;i<loc;i++)
    {
      temp = temp->link;
    }  
      ptr->link=temp->link;
      temp->link = ptr;
      printf("\nNode inserted");
      count = count +1;
}
 void display()
{ 
    struct node *temp;
    temp = head;
    if(head == NULL)
     {
         printf("\nThe List is empty!");
     }
    else
     {
        int i=1;
        printf("\n\nThe Linked list is:-  ");
        for(temp=head;temp!=NULL;temp=temp->link)
        { 
        printf("%d\t",temp->data);
        i=i+1;
        } 
     } 

}


void begdelete()
 {
    int val; 
    struct node* temp;
    if(head == NULL)
     {
         printf("\nThe List is empty!\n");
     }
    temp=head;
    val=temp->data;
    head=temp->link;
    free(temp);
    printf("\n%d was deleted\n",val);
 }

void randomdelete()
{
    struct node *ptrbefore,*ptr;
    int pos,val;
    printf("\nEnter the position after which you want to delete : ");
    scanf("%d",&pos);
    if(pos>count)
    {
      printf("Invalid position. Enter the position again : "); 
      scanf("%d",&pos);
    } 
    ptr = head;
    for(int i=0;i<pos;i++)
    {
      ptrbefore = ptr;
      ptr = ptr->link; 
    }
    val=ptr->data;
    ptrbefore->link = ptr->link;
    free(ptr);
    printf("\n%d was deleted succussfully\n",val);
    count=count-1;
}

void lastdelete()
 {
     int val;
     struct node *temp,*temp1;
     if(head == NULL)
     {
         printf("\nThe List is empty!\n");
     }
     else
     {
        temp=head;
        while(temp->link != 0)
        {
            temp1=temp;
            temp=temp->link;
        }
            val=temp->data;
            temp1->link=NULL;
            free(temp);
            printf("\n%d was deleted\n",val);
        }
 }   