#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fort.h"

struct Cars{
  int id;
  char model[100];
  char country[100];
  int price;
  char color[100];
  char state[100];
  char mileage[100];
  char repairs_count[100];
};

void print_data(struct Cars *car, int car_count);
int comp_by_price_to_up(const void* a, const void* b);
int comp_by_price_to_down(const void* a, const void* b);
int comp_by_state(const void* a, const void* b);
void print_russia(struct Cars *car, int car_count);
void print_bu_in_chosen_price(struct Cars *car, int car_count, int price_down, int price_up, char *model);

int main( ) {
  int n;
  printf("Input cars count: ");
  scanf("%d",&n);

  struct Cars car[n]; 
  for(int i = 0; i < n; i++){
    car[i].id = i;
    printf("Input car %d info:\n",i+1);
    printf("Input model: ");
    scanf("%s", car[i].model);
    printf("Input country: ");
    scanf("%s", car[i].country);
    printf("Input price: ");
    scanf("%d", &car[i].price);
    printf("Input color: ");
    scanf("%s", car[i].color);
    printf("input state(bu/new): ");
    scanf("%s", car[i].state);
    printf("Input mileage: ");
    scanf("%s", car[i].mileage);
    printf("Input repairs count: ");
    scanf("%s", car[i].repairs_count);
  } 

  print_data(car,n);
  qsort(car, n, sizeof(struct Cars), comp_by_price_to_up);
  print_data(car,n);
  qsort(car, n, sizeof(struct Cars), comp_by_price_to_down);
  print_data(car,n);
  qsort(car, n, sizeof(struct Cars), comp_by_state);
  print_data(car,n);
  print_russia(car,n);

  int min;
  int max;
  char model[20];
  printf("Input min price: ");
  scanf("%d", &min);
  printf("Input max price: ");
  scanf("%d", &max);
  printf("Input model: ");
  scanf("%s", model);
  print_bu_in_chosen_price(car,n,min,max,model);
  return 0;
}

void print_bu_in_chosen_price(struct Cars *car, int car_count, int price_down, int price_up, char *model){
  ft_table_t *table = ft_create_table();
  ft_set_cell_prop(table, 0, FT_ANY_COLUMN, FT_CPROP_ROW_TYPE, FT_ROW_HEADER);
  ft_write_ln(table, "Search result","");
  for(int i = 0; i < car_count; i++){
    if(strcmp(car[i].state,"bu") == 0 && strcmp(car[i].model, model) == 0 && strcmp(car[i].repairs_count,"0") == 0 && car[i].price > price_down && car[i].price < price_up){
      char buffer1[20];
      sprintf(buffer1, "%d" ,car[i].id);
      char buffer2[20];
      sprintf(buffer2, "%d" ,car[i].price);
      const char *line[] = {buffer1,car[i].model,car[i].country,buffer2,car[i].color,car[i].state,car[i].mileage,car[i].repairs_count};
      ft_row_write_ln(table, 8, line); 
    }
  }
  ft_set_cell_span(table, 0, 0, 8);
  ft_set_cell_prop(table,0,0,FT_CPROP_TEXT_ALIGN,FT_ALIGNED_CENTER);
  printf("%s\n", ft_to_string(table));
  ft_destroy_table(table);
}

void print_russia(struct Cars *car, int car_count){
  ft_table_t *table = ft_create_table();
  ft_set_cell_prop(table, 0, FT_ANY_COLUMN, FT_CPROP_ROW_TYPE, FT_ROW_HEADER);
  ft_write_ln(table, "Only Russian cars","");
  ft_write_ln(table, "ID", "Model", "Country", "Price", "Color","State","Mileage","Repair count");
  ft_add_separator(table);
  for(int i = 0; i < car_count; i++){
    if(strcmp(car[i].country,"russia") == 0 || strcmp(car[i].country,"Russia") == 0){
    char buffer1[20];
    sprintf(buffer1, "%d" ,car[i].id);
    char buffer2[20];
    sprintf(buffer2, "%d" ,car[i].price);
    const char *line[] = {buffer1,car[i].model,car[i].country,buffer2,car[i].color,car[i].state,car[i].mileage,car[i].repairs_count};
    ft_row_write_ln(table, 8, line);  
    }
  }
  ft_set_cell_span(table, 0, 0, 8);
  ft_set_cell_prop(table,0,0,FT_CPROP_TEXT_ALIGN,FT_ALIGNED_CENTER);
  printf("%s\n", ft_to_string(table));
  ft_destroy_table(table);
}

int comp_by_state(const void* a, const void* b){
  struct Cars *car1 = (struct Cars *)a;
  struct Cars *car2 = (struct Cars *)b;
  if (strcmp(car1->state , car2->state) == 0){
    return (car1->id - car2->id);
    } 
  else{
    return -strcmp(car1->state , car2->state);
  }
}

int comp_by_price_to_up(const void* a, const void* b){
  struct Cars *car1 = (struct Cars *)a;
  struct Cars *car2 = (struct Cars *)b;
  if (car1->price == car2->price){
    return (car1->id - car2->id);
    } 
  else{
    return car1->price - car2->price;
  }
}

int comp_by_price_to_down(const void* a, const void* b){
  struct Cars *car1 = (struct Cars *)a;
  struct Cars *car2 = (struct Cars *)b;
  if (car1->price == car2->price){
    return car1->id - car2->id;
    } 
  else{
    return -(car1->price - car2->price);
  }
}


void print_data(struct Cars *car, int car_count){
  ft_table_t *table = ft_create_table();
  ft_set_cell_prop(table, 0, FT_ANY_COLUMN, FT_CPROP_ROW_TYPE, FT_ROW_HEADER);
  ft_write_ln(table, "ID", "Model", "Country", "Price", "Color","State","Mileage","Repair count");
  for(int i = 0; i < car_count; i++){
    char buffer1[20];
    sprintf(buffer1, "%d" ,car[i].id);
    char buffer2[20];
    sprintf(buffer2, "%d" ,car[i].price);
    const char *line[] = {buffer1,car[i].model,car[i].country,buffer2,car[i].color,car[i].state,car[i].mileage,car[i].repairs_count};
    ft_row_write_ln(table, 8, line);                                                
  }
  printf("%s\n", ft_to_string(table));
  ft_destroy_table(table);
}
    