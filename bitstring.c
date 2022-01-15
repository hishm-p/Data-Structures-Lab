#include<stdio.h>
#include<stdlib.h>
//Univeral Set is {1,2,3,4,5,6,7,8,9}
void input();
void output();
void setunion();
void intersection();
void difference();
int a[]={0,0,0,0,0,0,0,0,0},b[]={0,0,0,0,0,0,0,0,0};
int main()
{
  int n=0;
  while(n!=5)
  {
   printf("\nBit Operations\n");
   printf("--------------\n");
   printf("\nEnter the operation 1.Input 2.Union 3.Intersection 4.Difference 5.Exit \n");
   scanf("%d",&n);
   switch(n)
   {
    case 1 : input();
             break;
    case 2 : setunion();
             break;
    case 3 : intersection();
             break;
    case 4 : difference();
             break;
    case 5 : exit(0);
             break;
    default : printf("Invalid input");
              break;
   }
  }
}

void input()
{
 int n,x,i;
 printf("Enter the size of the 1st set : ");
 scanf("%d",&n);
 printf("Enter the elements : \n");
 for(i=0;i<n;i++)
 {
  scanf("%d",&x);
  a[x-1]=1;
 }
 printf("Enter the size of 2nd set : ");
 scanf("%d",&n);
 printf("Enter the elements : \n");
 for(i=0;i<n;i++)
 {
  scanf("%d",&x);
  b[x-1]=1;
 }
 printf("\n1st set \n");
 for(i=0;i<9;i++)
 {
  printf("%d",a[i]);
 }

 printf("\n2nd set \n");
 for(i=0;i<9;i++)
 {
  printf("%d",b[i]);
 }
 printf("\n");
}

void output(int c[])
{
 int i;
 printf("\nSet is ");
 for(i=0;i<9;i++)
 {
  if(c[i]!=0)
   printf("%d ",i+1);
 } printf("\n");
}

void setunion()
{
 int i,c[10];
 for(i=0;i<9;i++)
 {
  if(a[i]!=b[i])
   c[i]=1;
  else
   c[i]=a[i];
 }
 for(i=0;i<9;i++)
 {
  printf("%d",c[i]);
 }

 output(c);

}

void intersection()
{
 int i,c[10];
 for(i=0;i<9;i++)
 {
  if(a[i]==b[i])
   c[i]=a[i];
  else
   c[i]=0;
 }
 for(i=0;i<9;i++)
 {
  printf("%d",c[i]);
 }
 output(c);

}

void difference()
{
 int i,c[10];
 for(i=0;i<9;i++)
 {
  if(a[i]==1&&b[i]==0)
   c[i]=1;
  else
   c[i]=0;
 }
 for(i=0;i<9;i++)
 {
  printf("%d",c[i]);
 }
 output(c);

}
