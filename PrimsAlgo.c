#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

void main(){
    int num_edges = 7;
    int matrix[7][7] = {
        {0,28,0,0,0,10,0},
        {28,0,16,0,0,0,14},
        {0,16,0,12,0,0,0},
        {0,0,12,0,22,0,18},
        {0,0,0,22,0,25,24},
        {10,0,0,0,25,0,0},
        {0,14,0,18,24,0,0},
    };

    int visited[7] = {-1,-1,-1,-1,-1,-1,-1};
    int i,j,f,k=0,min_cost, e1,e2, final_cost=0;

    while(true){
        f=0;
        for(i=0; i<num_edges; i++){
            if(visited[i] == -1){
                f=1;
                break;
            }
        }
        if(f==0){
            break;
        }
        min_cost = INT_MAX;

        if(k==0){
            for(i=0; i<num_edges; i++){
                for(j=0; j<num_edges; j++){
                    if(matrix[i][j] < min_cost && matrix[i][j] > 0){
                        min_cost = matrix[i][j];
                        e1 = i;
                        e2 = j;
                    }
                }
            }
            visited[e1] = 1;
            visited[e2] = 1;
            final_cost += min_cost;
            printf("%d %d Cost: %d\n", e1+1, e2+1, min_cost);
            k=1;
        }else{
            for(i=0; i<num_edges; i++){
                if(visited[i] == 1){
                    for(j=0; j<num_edges; j++){
                        if(matrix[i][j] < min_cost && matrix[i][j] > 0 && visited[j] == -1){
                            min_cost = matrix[i][j];
                            e1 = i;
                            e2 = j;
                        }
                    }
                }
            }
            visited[e2] = 1;
            final_cost += min_cost;
            printf("%d %d Cost: %d\n", e1+1, e2+1, min_cost);
        }
    }

    printf("\nFinal Cost: %d", final_cost);
}
