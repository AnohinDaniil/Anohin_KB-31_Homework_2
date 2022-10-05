#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <unistd.h>

struct Point{
  int x;
  int y;
  int size;
  int weight;
};

struct Point* init()
{
  srand(time(NULL));
  struct Point *mas;
  int N;
  printf("Введите количество точек: ");
  scanf("%d", &N);
  mas = (struct Point*) malloc (N * sizeof(struct Point));
  mas->size = N;
  int i;
  for(i = 0; i < N; i++)
  {
    (mas + i)->x = rand() % 25;
    (mas + i)->y = rand() % 25;
    (mas + i)->weight = (rand() % 98) + 1;  
  }    
  return mas;
}

void out_point(struct Point* mas)
{
  int i; 
  for (i = 0; i < mas->size; i++)
  {
    printf("Точка №%2d (%2d, %2d), вес = %d\n", i, (mas + i)->x, (mas + i)->y, (mas + i)->weight);
  }
  printf("\n");  
}

struct Point* del_point(struct Point** mas, int index){
  struct Point* temp = (*mas + index);
  int i;
  for (i = index; i <= (*mas)->size; i++)
  {
    ((*mas) + i)->x = ((*mas) + i + 1)->x;
    ((*mas) + i)->y = ((*mas) + i + 1)->y;
    ((*mas) + i)->weight = ((*mas) + i + 1)->weight;
  }
  (*mas)->size--;
  //mas = (struct Point**) realloc (*mas, (*mas)->size * sizeof(struct Point));
  return temp;
}

struct Point* search_min_weight(struct Point* mas){
  struct Point* min_weight = (mas + 0);
  int i, index = 0, id = 0;
  for (i = 1; i < mas->size; i++)
  {
    if(min_weight->weight > (mas + i)->weight)
    {
    	min_weight = (mas + i);
    	index = i;
	}
  }
  
  printf("\nМинимальный вес имеет: Точка №%2d (%2d, %2d), вес = %d\n", index, (mas + index)->x, (mas + index)->y, (mas + index)->weight);
  double dist, min_dist = 99999999;
  for (i = 1; i < mas->size; i++)
  {
  	dist = (((mas+i)->x-(mas+index)->x)*((mas+i)->x-(mas+index)->x)) + (((mas+i)->y-(mas+index)->y)*((mas+i)->y-(mas+index)->y));
    if(min_dist > dist && dist != 0)
    {
    	min_dist = dist;
    	id = i;
	}
  }
  printf("Минимальное расстояние с: Точка №%2d (%2d, %2d), вес = %d\n", id, (mas + id)->x, (mas + id)->y, (mas + id)->weight);
  (mas + id)->weight = (mas + id)->weight + (mas + index)->weight;
  printf("Удаляем Точку №%2d и добавляем её вес к Точке №%2d\n\n", index, id);

  del_point(&mas, index);
  return min_weight;
}

int main(){
	setlocale(LC_ALL, "Rus");
    int i; 
    struct Point *mas = init();
    while(mas->size > 1)
    {
    	out_point(mas);
  	search_min_weight(mas);
        sleep(4);
        system("clear");
    }
    printf("\nОставшаяся последняя точка: \n");
    out_point(mas);
    return 0; 
}
