#include<conio.h>
#include<stdio.h>
#include<limits.h>

#define max_houses 100

void floydWarshall(int graph[max_houses][max_houses],int num_houses)
{
    int dist[max_houses][max_houses];
    for (int i=0 ; i<num_houses ; i++){
        for (int j=0 ; j<num_houses ; j++){
            dist[i][j]=graph[i][j];
        }
    }

    for (int k=0 ; k<num_houses ; k++){
        for (int i=0; i<num_houses ; i++){
            for (int j=0 ; j<num_houses ; j++){
                if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX && dist[i][j]>dist[i][k]+dist[k][j])
                {
                    dist[i][j]= dist[i][k]+dist[k][j];
                }
            }
        }
    }

    printf("Shortest Travel Time between houses: \n");
    for (int i=0 ; i<num_houses; i++){
        for (int j=0 ; j<num_houses; j++){
            if(dist[i][j]==INT_MAX)
            {
                printf("-1 ");
            }
            else
            {
                printf("%d ",dist[i][j]);
            }
        }
        printf("\n");
    }

}


int main()
{
    int num_houses, graph[max_houses][max_houses];
    printf("\nEnter the total number of houses: ");
    scanf("%d", &num_houses);
    printf("\nEnter travlling time between houses ");
    printf("\nPut -1 if unreachable\n");
    for (int i = 0; i < num_houses; i++){
        for (int j = 0; j < num_houses; j++){
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == -1)
            {
                graph[i][j] = INT_MAX;
            }
        }
    }
    floydWarshall(graph, num_houses);
    return 0;
}






















    // /* Let us create the following weighted graph
    //         10
    //    (0)------->(3)
    //     |         /|\ /
    //   5 |          |
    //     |          | 1
    //    \|/         |
    //    (1)------->(2)
    //         3           */
    // int graph[V][V] = { { 0, 5, INF, 10 },
    //                     { INF, 0, 3, INF },
    //                     { INF, INF, 0, 1 },
    //                     { INF, INF, INF, 0 } };