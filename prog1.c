#include<stdio.h>
#include<stdlib.h>

struct car{
int mileage, cars_available, cost_perday;
char *name[15];
};

void calcost(int, int);
void checkavail(int, int);
void rented(int);
void car_returns(int);


int main(){
FILE *fp;
int subs;
int days;

struct car cars[4];
cars[0].name[15] = "Subcompact";
cars[1].name[15] = "Compact";
cars[2].name[15] = "Mini-van";
cars[3].name[15] = "Mid-size";
cars[4].name[15] = "Luxury";

fp = fopen("cars.dat", "r");
while(!feof(fp)){
fscanf(fp, "%d\t%d\t%d\n%d\t%d\t%d\n%d\t%d\t%d\n%d\t%d\t%d\n%d\t%d\t%d", &cars[0].mileage, &cars[0].cost_perday, &cars[0].cars_available,&cars[1].mileage, &cars[1].cost_perday, &cars[1].cars_available, &cars[2].mileage, &cars[2].cost_perday, &cars[2].cars_available, &cars[3].mileage, &cars[3].cost_perday, &cars[3].cars_available, &cars[4].mileage, &cars[4].cost_perday, &cars[4].cars_available);
}

void calcost(int sub, int day){
int cost;
cost = cars[sub - 1].cost_perday * day;
printf("The cost for the rental is %d.\n", cost);
}
void checkavail(int sub, int day){
if(cars[sub - 1].cars_available == 0){
printf("All cars in the category %s are already rented.\n", cars[sub - 1].name[15]);
}
else{
calcost(sub, day);
}
}

void rented(int sub){
cars[sub - 1].cars_available = cars[sub - 1].cars_available - 1;
}

void car_returns(int sub){
cars[sub - 1].cars_available += 1;
}


int uin=0;

do{
printf("Please select the options you want to choose:\n");
printf("1. Display the rental information\n");
printf("2. Rent a car\n");
printf("3. Return a car rented\n");
printf("4. Exit\n");

scanf("%d", &uin);

 
switch(uin){

case 1: 
printf("Car Name\tMileage\tCost/Day\tCars Available\n");
printf("Subcompact\t%d\t%d\t\t%d\n", cars[0].mileage, cars[0].cost_perday, cars[0].cars_available);
printf("Compact\t\t%d\t%d\t\t%d\n", cars[1].mileage, cars[1].cost_perday, cars[1].cars_available);
printf("Mid-Size\t%d\t%d\t\t%d\n", cars[2].mileage, cars[2].cost_perday, cars[2].cars_available);
printf("Mini-Van\t%d\t%d\t\t%d\n", cars[3].mileage, cars[3].cost_perday, cars[3].cars_available);
printf("Luxury\t\t%d\t%d\t\t%d\n", cars[4].mileage, cars[4].cost_perday, cars[4].cars_available);
break;

case 2:
printf("Please enter the type of car you want to rent:\n1. Subcompact\n2. Compact\n3. Mid-size\n4. Mini-van\n5. Luxury\n");
scanf("%d", &subs);
printf("please enter the length of days you want to rent for: ");
scanf("%d", &days);
checkavail(subs, days);
rented(subs);
break;

case 3:
printf("Please enter the type of car you want to return:\n1. Subcompact\n2. Compact\n3. Mid-size\n4. Mini-van\n5. Luxury\n");
scanf("%d", &subs);
printf("Thank you\n");
car_returns(subs);
break;

default:
break;
}

}while(uin!=4);

 
fclose(fp);

FILE *fp1;
fp1 = fopen("cars.dat", "wt");
fprintf(fp1, "%d\t%d\t%d\n%d\t%d\t%d\n%d\t%d\t%d\n%d\t%d\t%d\n%d\t%d\t%d", cars[0].mileage, cars[0].cost_perday, cars[0].cars_available,cars[1].mileage, cars[1].cost_perday, cars[1].cars_available, cars[2].mileage, cars[2].cost_perday, cars[2].cars_available, cars[3].mileage, cars[3].cost_perday, cars[3].cars_available, cars[4].mileage, cars[4].cost_perday, cars[4].cars_available);

return 0;
}



