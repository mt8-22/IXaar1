#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
int comp_by_id_up(const void* a, const void* b);
int comp_by_id_down(const void* a, const void* b);
void print_russia(struct Cars *car, int car_count);
void print_bu_in_chosen_price(struct Cars *car, int car_count, int price_down, int price_up, char *model);
void print_menu();

int main( ) {
  int n;
/*printf("Input cars count: ");
  scanf("%d",&n);*/
  n=9;

/*struct Cars car[n]; 
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
  }*/

  struct Cars car[9] = {
    {
      0, "BMW", "Germany", 10000, "Black", "new", "0", "0"
    },
    {
      1, "Audi", "Germany", 8000, "Yellow", "bu", "7000", "2"
    },
    {
      2, "Toyta", "Japan", 9000, "White", "bu", "1000", "0"
    },
    {
      3, "Hyundai", "South Korea", 7600, "Orange", "bu", "6900", "3"
    },
    {
      4, "Toyta", "Japan", 6500, "Blue", "bu", "10000", "0"
    },
    {
      5, "Ferrari", "Italy", 15000, "Red", "new", "0", "0"
    },
    {
      6, "GAZ", "Russia", 6000, "Black", "new", "0", "0"
    },
    {
      7, "LADA", "Russia", 4900, "Gray", "bu", "10000", "5"
    },
    {
      8, "BMW", "Germany", 7000, "Yellow", "bu", "6500", "0"
    }
    
  };

  int variant;
  int min;
  int max;
  char model[20];
  do{
    print_menu();
    scanf("%d", &variant);
    switch(variant){
      case 1:
        system("clear");
        print_data(car,n);
        printf("Press Enter...");
        break;
      case 2:
        system("clear");
        qsort(car, n, sizeof(struct Cars), comp_by_id_up);
        print_russia(car,n);
        printf("Press Enter...");
        break;
      case 3:
        system("clear");
        qsort(car, n, sizeof(struct Cars), comp_by_id_up);
        print_data(car,n);
        printf("Press Enter...");
        break;
      case 4:
        system("clear");
        qsort(car, n, sizeof(struct Cars), comp_by_id_down);
        print_data(car,n);
        printf("Press Enter...");
        break;
      case 5:
        system("clear");
        qsort(car, n, sizeof(struct Cars), comp_by_state);
        print_data(car,n);
        printf("Press Enter...");
        break;
      case 6:
        system("clear");
        printf("Input min price: ");
        scanf("%d", &min);
        printf("Input max price: ");
        scanf("%d", &max);
        printf("Input model: ");
        scanf("%s", model);
        print_bu_in_chosen_price(car,n,min,max,model);
        printf("Press Enter...");
        break;
      case 7:
        system("clear");
        qsort(car, n, sizeof(struct Cars), comp_by_price_to_up);
        print_data(car,n);
        printf("Press Enter...");
        break;
      case 8:
        system("clear");
        qsort(car, n, sizeof(struct Cars), comp_by_price_to_down);
        print_data(car,n);
        printf("Press Enter...");
        break;
      default:
        if(variant != 9){
          system("clear");
          printf("Incorrect variant\n");
          printf("Press Enter...");
          break;
        } else break; 
    }
    if (variant != 9){
        getchar();
        getchar();
    }
  } while(variant != 9);
  return 0;
}

void print_menu() {
    system("clear");
    printf("What do you want to do?\n");
    printf("1. Print all cars info\n");
    printf("2. Print all russian cars info\n");
    printf("3. Sort by id up\n");
    printf("4. Sort by id down\n");
    printf("5. Set new first\n");
    printf("6. Show bu cars in chosen price\n");
    printf("7. Sort by price up\n");
    printf("8. Sort by price down\n");
    printf("9. Exit\n");
    printf(">");
}

void print_bu_in_chosen_price(struct Cars *car, int car_count, int price_down, int price_up, char *model){
  printf("%15s|%15s|%15s|%15s|%15s|%15s|%15s|%15s\n","ID", "Model", "Country", "Price", "Color","State","Mileage","Repair count");
  for(int i = 0; i < car_count; i++){
    if(strcmp(car[i].state,"bu") == 0 && strcmp(car[i].model, model) == 0 && strcmp(car[i].repairs_count,"0") == 0 && car[i].price >= price_down && car[i].price <= price_up){
      printf("%15d|%15s|%15s|%15d|%15s|%15s|%15s|%15s\n",car[i].id, car[i].model, car[i].country, car[i].price, car[i].color, car[i].state, car[i].mileage, car[i].repairs_count); 
    }
  }
}

void print_russia(struct Cars *car, int car_count){
  printf("Only russian cars:\n");
  printf("%15s|%15s|%15s|%15s|%15s|%15s|%15s|%15s\n","ID", "Model", "Country", "Price", "Color","State","Mileage","Repair count");
  for(int i = 0; i < car_count; i++){
    if(strcmp(car[i].country,"russia") == 0 || strcmp(car[i].country,"Russia") == 0){
    printf("%15d|%15s|%15s|%15d|%15s|%15s|%15s|%15s\n",car[i].id, car[i].model, car[i].country, car[i].price, car[i].color, car[i].state, car[i].mileage, car[i].repairs_count);   
    }
  }
}

int comp_by_id_up(const void* a, const void* b){
  struct Cars *car1 = (struct Cars *)a;
  struct Cars *car2 = (struct Cars *)b;
  return (car1->id - car2->id);  
}

int comp_by_id_down(const void* a, const void* b){
  struct Cars *car1 = (struct Cars *)a;
  struct Cars *car2 = (struct Cars *)b;
  return -(car1->id - car2->id);  
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
  printf("%15s|%15s|%15s|%15s|%15s|%15s|%15s|%15s\n","ID", "Model", "Country", "Price", "Color","State","Mileage","Repair count");
  for(int i = 0; i < car_count; i++){
    printf("%15d|%15s|%15s|%15d|%15s|%15s|%15s|%15s\n",car[i].id, car[i].model, car[i].country, car[i].price, car[i].color, car[i].state, car[i].mileage, car[i].repairs_count);                                                
  }
}
