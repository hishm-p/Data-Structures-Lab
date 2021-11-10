#include<stdio.h>
void insert(int n,int *a)
{
 int pos,val;
 printf("Enter the position at which value is to be inserted:- ");
 scanf("%d",&pos);
 printf("enter the value to be inserted:- ");
 scanf("%d",&val);
 for(int i=n;i>=pos;i--)
  {
    a[i]=a[i-1];
  }
  a[pos-1]=val;
 n++;
 printf("Element entered successfully!!\n");
 for(int i=0;i<n;i++)
     {
      printf("%d  ",a[i]);
     }
}

void display(int n,int *a)
  {
    printf("The Array is:- \n");
    for(int i=0;i<n;i++)
       {
        printf("%d  ",a[i]);
       }     
 }

void search(int n,int *a)
{
 int item,flag=0;
 printf("Enter a number to check its position in the array: ");
 scanf("%d",&item);
 for(int i=0;i<n;i++)
   {
     if(a[i]==item)
        {
         printf("%d is at %d th position\n",item,i+1);
         flag=1;
        }
   }
      if(flag==0)
        {
         printf("\nElement not present in array\n");
	}
}

void delete(int n,int *a)
{	
 int del;
 printf("Enter the element to be deleted: ");
 scanf("%d",&del);
 for(int i=0;i<n;i++)
   {
    if(a[i]==del)
      {
       for(int j=i;j<n-1;j++)
       {
        a[j]=a[j+1];
       }
      }
   }
   printf("Element deleted successfully!");
}

void update(int n,int *a)
{
 int oldel,newel,flag=0;
 printf("Enter a the number to be updated: ");
 scanf("%d",&oldel);
 printf("Enter a the new number: ");
 scanf("%d",&newel);
 for(int i=0;i<n;i++)
   {
     if(a[i]==oldel)
        {
         a[i]=newel;
         flag=1;
        }
   }
      if(flag==0)
        {
         printf("\nElement not present in array\n");
	}
      else
         printf("\nElement updated successfully\n");
}


void main()
{
  int a[10],ch,n,i;
  printf("Enter the number of elements to be inserted:-");
  scanf("%d",&n);
  printf("Enter the elements:- \n");
  for(i=0;i<n;i++)
     {
      scanf("%d",(a+i));
     }

do{
  printf("\nEnter your choice:-\n1:display\n2:insert\n3:search\n4:delete\n5:Update\n6:Exit\n");
  scanf("%d",&ch);
  switch(ch)
	{ 
	  case 1: display(n,a);
   	  break;
	  case 2: insert(n,a);
		  n++;
	  break;
	  case 3: search(n,a);
	  break; 
	  case 4: delete(n,a);
		  n--;
	  break;
          case 5: update(n,a);
 	  break;
	/*  default:
	  printf("Invalid entry!!");   */ 
	} 
  }while(ch!=6);
   
}



   
