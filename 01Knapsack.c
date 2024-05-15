#include <stdio.h>
int max(int a,int b){
    return (a>b)?a:b;
}

int knapSack(int W,int wt[],int val[],int n){
    int i,j;
    int table[n+1][W+1];
    for(i=0;i<=n;i++){
        for(j=0;j<=W;j++){
            if(i==0||j==0){
                table[i][j]=0;
            }
            else if(wt[i-1]<=j){
                table[i][j]=max(val[i-1]+table[i-1][j-wt[i-1]],table[i-1][j]);
            }
            else{
                table[i][j]=table[i-1][j];
            }
        }
    }
    return table[n][W];
}

int main(){
    int W,n;
    printf("Enter total weight of knapsack: ");
    scanf("%d",&W);
    printf("Enter the number of weights: ");
    scanf("%d",&n);
    int weight[n],profit[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter the weight %d: ",i+1);
        scanf("%d",&weight[i]);
        printf("Enter the profit of weight %d: ",i+1);
        scanf("%d",&profit[i]);
    }  
    printf("maximum profit:%d",knapSack(W,weight,profit,n));
    return 0;
}
