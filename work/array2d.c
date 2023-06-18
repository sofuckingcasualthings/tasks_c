#include <stdio.h>
#include <stdlib.h>
#include <time.h> // подкл риал рандом

// объявление и вывод двумерного массива, заполненного случайными числами от 1 до 100

int main(void)
{
    srand(time(NULL));
    int aarr[3][7]; // двумерный массив, сначала строки, потом столбцы

    for (int str = 0; str < 3; str++) // цикл перебирает строки
    {
        for (int col = 0; col < 8; col++) // цикл перебирает столбцы
        {
            aarr[str][col] = rand() % 100;
            printf("%d\t", aarr[str][col]);
        }
        printf("\n");
    }
    return 0;
}