#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Edge{
    int s,d,w;
};

struct Graph{
    int V,E;
    struct Edge *edge;
};

struct Graph *createGraph(int VC,int EC){
    struct Graph *graph=(struct Graph*)malloc(sizeof(struct Graph));
    graph->V=VC;
    graph->E=EC;
    graph->edge=(struct Edge*)malloc(graph->E*sizeof(struct Edge));
    
    return graph;
}

void print(int dist[],int n){
    printf("Vertex distance from source \n");
    for(int i=0;i<n;++i){
        printf("%d\t %d \n",i,dist[i]);
    }
}

void bellmanFord(struct Graph *graph,int src){
    int VC=graph->V;
    int EC=graph->E;
    int *dist=(int *)malloc(sizeof(int)*VC);
    
    for(int i=0;i<VC;i++){
        dist[i]=INT_MAX;
    }
    
    dist[src]=0;
    
    for(int i=1;i<=VC-1;i++){
        for (int j=0;j<EC;j++){
            int u=graph->edge[j].s;
            int v=graph->edge[j].d;
            int weight=graph->edge[j].w;
            
            if(dist[u]!=INT_MAX && dist[u]+weight<dist[v]){
                dist[v]=dist[u]+weight;
            }
        }    
    }
    
     for (int i=0;i<EC;i++){
            int u=graph->edge[i].s;
            int v=graph->edge[i].d;
            int weight=graph->edge[i].w;
            
            if(dist[u]!=INT_MAX && dist[u]+weight<dist[v]){
                printf("Graph contains negative cycle.");
            }
    } 
    print(dist,VC);   
}

int main()
{
    int V = 5; 
    int E = 8; 
    struct Graph* graph = createGraph(V, E);

    graph->edge[0].s = 0;
    graph->edge[0].d = 1;
    graph->edge[0].w = -1;

    graph->edge[1].s = 0;
    graph->edge[1].d = 2;
    graph->edge[1].w = 4;

    graph->edge[2].s = 1;
    graph->edge[2].d = 2;
    graph->edge[2].w = 3;

    graph->edge[3].s = 1;
    graph->edge[3].d = 3;
    graph->edge[3].w = 2;

    graph->edge[4].s = 1;
    graph->edge[4].d = 4;
    graph->edge[4].w = 2;

    graph->edge[5].s = 3;
    graph->edge[5].d = 2;
    graph->edge[5].w = 5;


    graph->edge[6].s = 3;
    graph->edge[6].d = 1;
    graph->edge[6].w = 1;

    graph->edge[7].s = 4;
    graph->edge[7].d = 3;
    graph->edge[7].w = -3;
    
    bellmanFord(graph, 0);

    return 0;
}
