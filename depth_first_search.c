#include<stdio.h>
#include<conio.h>
int a[20][20],visited[20],n;
void dfs(int v)
{
  int i;
  printf("%d ",v);
  visited[v]=1;
 for(i=1;i<=n;i++)
   if(a[v][i]==1 && !visited[i])
   {
       dfs(i);
   }

}
int main()
{
int i,v,j;
printf("Enter the no of vertices:");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
 visited[i]=0;
}
printf("\nEnter graph data in matrix form:\n");
for(i=1;i<=n;i++)
 for(j=1;j<=n;j++)
  scanf("%d",&a[i][j]);
// printf("\nEnter the starting vertex:");
// scanf("%d",&v);
// visited[v]=1;
// printf("%d",v);
dfs(1);
return 0;

}
