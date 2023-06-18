#include <stdio.h>
#include <math.h>

int main(void)
{
    int l, min = 999, max = 0;
    scanf("%d", &l);
    int arr[l];

    for (int i = 0; i < l; i++)
    {
        scanf("%d", &arr[i]);

        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    for (int i = 0; i < l; i++)
    {
        if (arr[i] == min)
        {
            printf("%d ", max);
        }
        if (arr[i] == max)
        {
            printf("%d ", min);
        }
        else
        {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}