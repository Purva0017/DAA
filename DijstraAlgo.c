#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 6

int minDist(int dist[],bool sptSet[]){
    int min=INT_MAX,min_value;
    for(int v=0;v<V;v++){
        if(sptSet[v]==false && dist[v]<=min){
            min=dist[v];
            min_value=v;
        }
    }
    return min_value;
}

int printS(int dist[]){
    printf("Vertex\tDistance from source\n");
    for(int i=0;i<V;i++){
        if(dist[i]==INT_MAX)
        {
            printf("%d\tINF\n",i);
        }
        else{
            printf("%d\t%d\n",i,dist[i]);
        }
    }
}

void dijkstras(int graph[V][V],int src){
    int dist[V];
    bool sptSet[V];
    
    for(int i=0;i<V;i++){
        dist[i]=INT_MAX;
        sptSet[i]=false;
    }
    
    dist[src]=0;
    
    for(int count=0;count<V-1;count++){
        int u=minDist(dist,sptSet);
        sptSet[u]=true;
        
        for(int v=0;v<V;v++){
            if(!sptSet[v] && graph[u][v] && dist[u]!=INT_MAX && dist[u]+graph[u][v]<dist[v]){
                dist[v]=dist[u]+graph[u][v];
            }
        }
    }
    printS(dist);
}

int main(){
    int graph[V][V] = { 
        {0,50,45,10,0,0},
        {0,0,10,15,0,0},
        {0,0,0,0,30,0},
        {10,0,0,0,15,0},
        {0,20,35,0,0,0},
        {0,0,0,0,3,0}
     };
    dijkstras(graph,0);
    return 0;
}
