#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <unistd.h>

int size_mas = 0;
int *mas = NULL;

void add(int item)
{
	mas = (int*) realloc(mas, (size_mas+1) * sizeof(int));
	mas[size_mas] = item;
    size_mas++;
    printf("\nЭлемент добавлен!\n");
}

void insert(int index, int item)
{
	int i;
	mas = (int*) realloc(mas, (++size_mas) * sizeof(int));
	for(i = size_mas; i >= index; i--)
	{
		mas[i] = mas[i-1];
	}
	mas[index] = item;
    printf("\nЭлемент добавлен!\n");
}
	
int size()
{
	return size_mas;
}

int Remove(int index)
{
	int i, elem;
	elem = mas[index];
	for(i = index; i < size_mas; i++)
	{
		mas[i] = mas[i+1];
	}
	mas = (int*) realloc(mas, (--size_mas) * sizeof(int));
	printf("\nЭлемент удален!\n");
	return elem;
}

void set(int index, int item)
{
	mas[index] = item;
	printf("\nЭлемент изменен!\n");
}

int get(int index)
{
	return mas[index];
}

void output()
{
	int i;
	for(i = 0; i < size_mas; i++)
	{
		printf("mas[%d] = %d\n", i, (mas[i])); 
	}
}

int main()
{
  setlocale(LC_ALL, "Rus");
  int item, index;
  while(1)
 {
          printf("\n1. Добавить элемент массива в конец списка.\n");
          printf("2. Вставка элемента в середину списка.\n");
          printf("3. Количество элементов в массиве.\n");
          printf("4. Удалить элемент по индексу.\n");
          printf("5. Изменить значение существующего элемента.\n");
          printf("6. Получение значения заданого элемента.\n");
          printf("7. Вывод элементов массива.\n");
          printf("8. Выход из программы.\n");
          int menu;
          printf("Ваш выбор: ");
          scanf("%d",&menu);
          switch(menu)
          {
            case 8: printf("\nЗавершение программы"); return 0;
            case 1: {
            	printf("Введите элемент: ");
    			scanf("%d", &item);
    			add(item);
			} break;
            case 2: {
            	printf("Введите индекс от 0 до %d: ", size_mas);
    			scanf("%d", &index);
    			if(index >= 0 && index <= size_mas)
    			{
    				printf("Введите элемент: ");
    				scanf("%d", &item);
					insert(index, item);
				}
    			else printf("Неверный индекс!");
			}break;
            case 3: {
            	printf("Количество єлементов в массиве: %d", size());
			} break;
			case 4: {
            	printf("Введите индекс от 0 до %d: ", size_mas-1);
            	scanf("%d", &index);
            	if(index >= 0 && index < size_mas)
            	{
            		Remove(index);
				}
				else printf("Неверный индекс!");
			} break;
			case 5: {
            	printf("Введите индекс от 0 до %d: ", size_mas-1);
            	scanf("%d", &index);
            	if(index >= 0 && index < size_mas)
            	{
            		printf("Введите новое значение: ");
    				scanf("%d", &item);
            		set(index, item);
				}
				else printf("Неверный индекс!");
			} break;
			case 6: {
            	printf("Введите индекс от 0 до %d: ", size_mas-1);
            	scanf("%d", &index);
            	if(index >= 0 && index < size_mas)
            	{
            		printf("Полученный элемент: %d", get(index));
				}
				else printf("Неверный индекс!");
				
			} break;
			case 7: {
                system("clear");
            	output();
                sleep(4);
			} break;
            default: printf("Выбран несуществующий вариант. Повторить ввод\n");
          }
          sleep(1);
           system("clear"); 
           continue;
         }
}
