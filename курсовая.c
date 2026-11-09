#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
int main()
{
	setlocale(LC_ALL, "RUS");
	int n, m, choice, again = 1, k = 0;
	do
	{
		k = 0;
	printf("Введите количество строк:");
	scanf_s("%d", &n);
	printf("Введите количество столбцов:");
	scanf_s("%d", &m);
	if (n <= 0 || m <= 0)
	{
		printf("Размеры массива должны быть больше нуля\n");
		return 1;
	}
	int** a = (int**)calloc(n, sizeof(int*));
	if (a == NULL)
	{
		printf("Память не выделена\n");
		return 1;
	}
	for (int i = 0; i < n; i++)
	{
		a[i] = (int*)malloc(m * sizeof(int));
		if (a[i] == NULL)
		{
			printf("Память не выделена\n");
			return 1;
		}

	}
	printf("Выберите способ заполнения массива:\n");
	printf("1 - Ввод элементов с консоли\n");
	printf("2 - Заполнить случайными числами\n");
	printf("Ваш выбор:");
	scanf_s("%d", &choice);
	if (choice == 1)
	{
		printf("Введите элементы массива:\n");
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				printf("a[%d][%d] = ", i, j);
				scanf_s("%d", &a[i][j]);
			}
		}
	}
	else if (choice == 2)
	{
		printf("Случайное заполнение массива:\n");
		srand(time(NULL));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				a[i][j] = rand() % 100;
			}
		}
	}
	else
	{
		printf("Выбран несуществующий вариант\n");
	}
	printf("\nИсходный массив:\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < n; i++)
	{
		if (i % 2 != 0)
		{
			continue;
		}
		for (int j = 0; j < m; j++)
		{
			a[k][j] = a[i][j];
		}
		k++;
	}
	for (int i = k; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			a[i][j] = 0;
		}
	}
	printf("\nОбработанный массив:\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < n; i++)
	{
		free(a[i]);
	}
	free(a);
	printf("\nХотите попробовать еще раз?\n");
	printf("\n1 - Да\n");
	printf("\n0 - Нет\n");
	scanf_s("%d", &again);
}while (again == 1);

}