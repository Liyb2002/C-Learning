#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int cmpfunc (const void * a, const void * b)
{
   return  *(double*)a > *(double*)b ? 1:-1;
}

int main(void){
   int numOfPacks;
   double totalMoney;
   double *stopPoint=(double*)malloc(sizeof(double) * numOfPacks);

    printf("Enter the amount of packages");
   while (scanf ("%d", &numOfPacks )!=1 || numOfPacks<1 || numOfPacks>100){
       printf("Enter again");
       fflush(stdin);
   }
  // printf("%d",numOfPacks);

printf("Enter the amount of money");
  scanf("%lf", &totalMoney);

//Initialize srand
  srand((unsigned)time(NULL));

  //Algo
  double *startPrt=stopPoint;
for( int i=0; i<numOfPacks-1; i++ ){
    
    *stopPoint=rand()%(int)(totalMoney*100)/100.00;
    stopPoint++;
}

qsort(startPrt, numOfPacks-1, sizeof(double), cmpfunc);

//print out what is in the array
/*
stopPoint=startPrt;
for( int i=0; i<numOfPacks-1; i++ ){
    printf("%lf\n",*stopPoint);
    stopPoint++;
}*/

stopPoint=startPrt;
//Start to print money of each person
printf("Person 1 gets %lf\n",*stopPoint);

//Others except the last one
for(int i=2;i<numOfPacks;i++){
double tempt=*stopPoint;
stopPoint++;
double money=*stopPoint-tempt;
printf("Person %d gets %lf\n",i, money);
}
printf("Person %d gets %lf\n",numOfPacks, totalMoney-*stopPoint);

}