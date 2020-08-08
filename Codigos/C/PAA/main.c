#include <knapsack.h>

int main()
{
    int w = 1500;



    loadData();

    printf("VALUE = %d\n", knapSackPD(w));
    knapSackBacktracking(w);

	return 0;
}
