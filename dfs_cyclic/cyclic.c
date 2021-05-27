#include<stdio.h>
#include<stdlib.h>

#define MAX 100

#define initial 1
#define visited 2
#define finished 3

int n,i,j;    
int adj[MAX][MAX];
int state[MAX];

void DF_Traversal();
void DFS(int v);

int main()
{
printf("Enter number of vertices:\n");
scanf("%d",&n);
printf("Enter the adjacency matrix:\n");
for(i=0;i<n;i++)
for(j=0;j<n;j++)
scanf("%d",&adj[i][j]);
printf("matrix is:\n");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
printf("%d",adj[i][j]);
printf("\n");
}
DF_Traversal();
return 0;
}

void DF_Traversal()
{
        int v;

        for(v=0; v<n; v++)
                state[v] = initial;

        DFS(0);/*start DFS from vertex 0*/

        for(v=0; v<n; v++)
        {
                if(state[v]==initial)
                        DFS(v);
        }
        printf("\nGraph is Acyclic\n");
}

void DFS(int v)
{
        int i;
        state[v] = visited;

        for(i=0; i<n; i++)
        {
                if(adj[v][i]==1)
                {
                        if(state[i]==initial)
                                DFS(i);
                        else if(state[i]==visited)
                        {
                                printf("\nBack edge  (%d,%d) found\n", v, i);
                                printf("\nGraph is cyclic\n");
                                exit(1);
                        }
                }
        }
        state[v] = finished;
}
