#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int visited[MAX];

void dfs(int **graph, int n, int start){
    visited[start] = 1;
    printf("%d ", start);
    for(int i=0;i<n;i++){
        if(graph[start][i] && !visited[i]) dfs(graph,n,i);
    }
}

int main(){
    int n = 4;
    int *graph[MAX];
    for(int i=0;i<n;i++) graph[i]=(int*)calloc(n,sizeof(int));
    graph[0][1]=1; graph[0][2]=1; graph[1][2]=1; graph[2][0]=1; graph[2][3]=1; graph[3][3]=1;

    for(int i=0;i<n;i++) visited[i]=0;
    dfs(graph,n,2);

    for(int i=0;i<n;i++) free(graph[i]);
    return 0;
}
