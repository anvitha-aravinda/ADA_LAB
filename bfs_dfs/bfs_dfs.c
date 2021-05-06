#include<stdio.h>
#include<conio.h>
int a[20][20],q[20],visited[20],n,i,j,f=0,r=-1,reach[20],ch,v;
void bfs(int v)
{
for(i=1;i<=n;i++)
if(a[v][i] && !visited[i])
q[++r]=i;
if(f<=r)
{
visited[q[f]]=1;
bfs(q[f++]);
}
}
void dfs(int v)
{
int i;
reach[v]=1;
for(i=1;i<=n;i++)
if(a[v][i] && !reach[i])
{
printf("%d->%d\n",v,i);
dfs(i);
}
}
void main()
{
int i,j,count=0;
printf("Enter number of vertices:\n");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
reach[i]=0;
}
for(i=1;i<=n;i++)
{
q[i]=0;
visited[i]=0;
}
printf("Enter the adjacency matrix:\n");
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
scanf("%d",&a[i][j]);
printf("matrix is:\n");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
printf("%d",a[i][j]);
printf("\n");
}
do{
printf("1.Print all the nodes reachable from a given starting node in a digraph using BFS method.\n");
printf("2.Check whether a given graph is connected or not using DFS method.\n");
printf("enter the choice\n");
scanf("%d",&ch);
if(ch==2)
{
dfs(1);
printf("\n");
for(i=1;i<=n;i++)
{
if(reach[i])
count++;
}
if(count==n)
printf("Graph is connected\n");
else
printf("Graph is not connected\n");
}
if(ch==1)
{
printf("\n Enter the starting vertex:");
scanf("%d",&v);
bfs(v);
printf("The node which are reachable are:\n");
for(i=1;i<=n;i++)
if(visited[i])
printf("%d\t",i);
}
printf("\n");
printf("enter 0 to continue\n");
scanf("%d",&ch);
}while(ch==0);
}
