#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
int main()
{
    setlocale(LC_ALL, "Russian"); 
    int a[100][100];
    int b[100][100];
    int n, m, i, j, k, choice, again;
    srand(time(NULL));
    do
    {
        printf("Введите количество строк: ");
        scanf_s("%d", &n);
        printf("Введите количество столбцов: ");
        scanf_s("%d", &m);
        printf("\nВыберите способ заполнения массива:\n");
        printf("1 - Ввод с консоли\n");
        printf("2 - Ввод случайных чисел\n");
        scanf_s("%d", &choice);
        if (choice == 1)
        {
            printf("\nВведите элементы массива:\n");
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < m; j++)
                {
                    scanf_s("%d", &a[i][j]);
                }
            }
        }
        else
        {
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < m; j++)
                {
                    a[i][j] = rand() % 100;
                }
            }
        }
        printf("\nИсходный массив:\n");
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                printf("%4d", a[i][j]);
            }
            printf("\n");
        }
        k = 0;
        for (i = 0; i < n; i += 2)
        {
            for (j = 0; j < m; j++)
            {
                b[k][j] = a[i][j];
            }
            k++;
        }
        for (i = k; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                b[i][j] = 0;
            }
        }
        printf("\nПреобразованный массив:\n");
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                printf("%4d", b[i][j]);
            }
            printf("\n");
        }
        printf("\nРезультат:\n");
        printf("\nХотите продолжить работу?\n");
        printf("1 - Да\n");
        printf("0 - Нет\n");
        scanf_s("%d", &again);
    }
    while (again == 1);
    printf("\nПрограмма завершена.\n");
    return 0;
}