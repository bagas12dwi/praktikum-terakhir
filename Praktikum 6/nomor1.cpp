 //Bagas Dwi Sulistyo
//20051397076
//MIB 2020

#include <stdio.h>
#include <stdlib.h>
void urutan();
int main()
{
 int n;
 printf("BAGAS DWI SULISTYO\n");
 printf("20051397076\n");
 printf("MIB2020\n");
 printf("Input n : ");scanf("%d", &n);
 urutan();
 return 0;
}
void urutan(int i){
 printf("%d\n", i);
 if(i==0)
 return;
 urutan(i-1);
}

 //Bagas Dwi Sulistyo
//20051397076
//MIB 2020