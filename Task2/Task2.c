#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int* init(int *n)
{
  int *mas;
  printf("Введите размер массива:");
  scanf("%d", n);
  srand(time(NULL));
  mas = (int*) malloc (*n * sizeof(int));
  int i;
  for (i = 0; i < *n; i++)
  {
    mas[i] = (rand() % 18) - 9;  
  }
  return mas;
}

void output_mas(int *mas, int n)
{
  int i;
  printf("Ваш массив:|");
  for (i = 0; i < n; i++)
  {
    printf("%2d |", mas[i]);
  }
  printf("\n");
}

int Func_one(int *mas, int n)
{
	int i, count = 0;
  	double average, sum = 0;
  	for (i = 0; i < n; i++)
	{
    	sum += mas[i];
  	}
  	average = sum / n;
  	printf("Среднее значение в массиве = %.3f", average);
  	for (i = 0; i < n; i++)
	{
    	if(mas[i] > average)
    	{
    		count++;
		}
  	}
  	return count;
}

int Func_two(int *mas, int n)
{
  int sum = 0;
  int i, id = 0;
  for (i = 0; i < n; i++)
  {
    if(id == 1)
	{
      sum += abs(mas[i]);
    }
    if (mas[i] < 0)
	{
    	id = 1; 
	}  
  }
  return sum ;
}

int main(){
	setlocale(LC_ALL, "Rus");
  	int size;
  	int *mas = init(&size);
  	output_mas(mas, size);
  	printf("\n1. Количество єлементов массива больше среднего: %d ", Func_one(mas, size));
  	printf("\n2. Сумма модулей элементов массива после первого отрицательного = %d\n", Func_two(mas, size));
  	return 0;
}