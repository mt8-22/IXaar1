#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fort.h"

struct Cars{
  int id;
  char model[100];
  char country[100];
  char price[100];
  char color[100];
  char state[100];
  char mileage[100];
  char repairs_count[100];
};

void print_data(struct Cars *car, int car_count);
int main( ) {
  int n;
  printf("Введите кол-во машин: ");
  scanf("%d",&n);


  struct Cars car[n];
  for(int i = 0; i < n; i++){
    car[i].id = i;
    printf("Введите информацио о %d машине:\n",i+1);
    printf("Введите модель: ");
    scanf("%s", car[i].model);
    printf("Введите страну: ");
    scanf("%s", car[i].country);
    printf("Введите цену: ");
    scanf("%s", car[i].price);
    printf("Введите цвет: ");
    scanf("%s", car[i].color);
    printf("Введите состояние (БУ/Новый): ");
    scanf("%s", car[i].state);
    printf("Введите пробег: ");
    scanf("%s", car[i].mileage);
    printf("Введите кол-во ремонтов: ");
    scanf("%s", car[i].repairs_count);
  }

  print_data(car,n);


  return 0;
}

void print_data(struct Cars *car, int car_count){
  ft_table_t *table = ft_create_table();
  ft_set_cell_prop(table, 0, FT_ANY_COLUMN, FT_CPROP_ROW_TYPE, FT_ROW_HEADER);
  ft_write_ln(table, "ID", "Model", "Country", "Price", "Color","State","Mileage","Repair count");
  for(int i = 0; i < car_count; i++){
    char buffer[20];
    sprintf(buffer, "%d" ,i);
    const char *line[] = {buffer,car[i].model,car[i].country,car[i].price,car[i].color,car[i].state,car[i].mileage,car[i].repairs_count};
    ft_row_write_ln(table, 8, line);                                                
  }
    printf("%s\n", ft_to_string(table));
    ft_destroy_table(table);
}
    