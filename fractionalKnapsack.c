#include <stdio.h>
int main ()
{
    int n;
    float capacity;
    printf ("Enter weight capacity of bag:");
    scanf ("%f", &capacity);
    printf ("Enter number of weights you want:");
    scanf ("%d", &n);
    
    int weight[n], profit[n];
    float ratio[n];
    float totalValue=0.0;

    for (int i = 0; i < n; i++)
	{
        printf ("Enter weight %d: ", (i + 1));
        scanf ("%d", &weight[i]);
        printf ("Enter profit of weight %d: ", (i + 1));
        scanf ("%d", &profit[i]);
        ratio[i] = (float)profit[i] /(float) weight[i];
	}
	for (int i = 0; i < n; i++)
	{
        for (int j = 0; j < n - i - 1; j++)
        {
            if (ratio[j] < ratio[j + 1])
            {
                int temp = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = temp;
                
                temp = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = temp;
                
                float tempf = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = tempf;
            }
        }
	}
	for(int i=0; i<n; i++)
	{
	    if(capacity >= weight[i])
	    {
	        capacity = capacity - weight[i];
	        totalValue += profit[i];
	    }
	    else if(capacity > 0)
	    {
	        totalValue += ratio[i]*capacity;
	        capacity = 0;
	    }
	}
	printf("Maximum profit achievable is: %f", totalValue);
	return 0;
}