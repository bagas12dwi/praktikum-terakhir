 //Bagas Dwi Sulistyo
//20051397076
//MIB 2020

#include <stdio.h>
#include <stdlib.h>
int prima(int n, int i){
 if(n%i==0)
 return 0;
 if(i==2)
 return 1;
 prima(n, i-1);
}
int main()
{
 int i,n, output;
 printf("BAGAS DWI SULISTYO\n");
 printf("20051397076\n");
 printf("MIB2020\n");
 printf("Input bilangan : ");
scanf("%d", &n);
 i=n-1;
 if(n!=1){
 if(prima(n, i) || n==2){
 puts("Bilangan tersebut prima");
 }
 else{
 puts("Bilangan tersebut bukan prima");
 }
 }
 else{
 puts("Bilangan tersebut bukan prima");
 }
 return 0;
}

 //Bagas Dwi Sulistyo
//20051397076
//MIB 2020