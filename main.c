#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_NUMS 100
#define NUM_PRODUCTS 5
//////////////////////////////////////
//* Read floating point tempratures until -99 is entered.Calculate
//* the average of the tempreratures and print out all of the temperatures
//* that are less than the average
int main()
{
    int ar1[5];

    int ar2[] = {4, 2};
    int ar3[3] = {0};

    ar1[0] = 1;
    ar1[1] = 6;

    printf("ar1[0]=%d, ar1[1]=%d\n", ar1[0], ar1[1]);

    printf("ar2[0]=%d, ar2[1]=%d\n", ar2[0], ar2[1]);

    printf("ar3[0]=%d, ar3[1]=%d, ar[2]=%d\n", ar3[0], ar3[1], ar3[2]);

    double temps[MAX_NUMS];
    double sum = 0, avg, n;
    int a, nTemps = 0, keepGoing = 1;

    do
    {
        printf("Enter a temprature (-99 to stop):");
        scanf("%lf", &n);
        if (n != -99.0)
        {
            sum += n;
            temps[nTemps++] = n;
        }
        else
        {
            keepGoing = 0;
        }
    } while (keepGoing);

    avg = sum / nTemps;
    printf("The avreage of %d temperatures is %.2lf\n", nTemps, avg);
    for (a = 0; a < nTemps; a++)
    {
        if (temps[a] < avg)
        {
            printf("%.2lf is below average\n", temps[a]);
        }
    }
    //* Product ID & price parallel arrays
    int sku[NUM_PRODUCTS] = {285, 496, 371, 485, 142};
    double price[NUM_PRODUCTS] = {1.98, 4.37, 7.99, 2.24, 4.48};

    int productId, posn, i, keepLocking;
    double total = 0.0;

    do
    {
        printf("Enter product to purchase {0 to stop}");
        scanf("%d", &productId);
        if (productId > 0)
        {
            posn = i;
            keepLocking = 0;
            //* linear search to find position of product in sku array
            for (i = 0; i < NUM_PRODUCTS && keepLocking; i++)
            {
                if (productId == sku[i])
                {
                    posn = i;
                    keepLocking = 0;
                }
            }
        }

        //* if product ID found, add price on to total
        if (posn >= 0)
        {
            total += price[posn];
        }
        else
        {
            printf("Product ID %c not found\n", productId);
        }
    } while (productId > 0);
    printf("Total = %.2lf\n", total);

    return 0;
}