 //Bagas Dwi Sulistyo
//20051397076
//MIB 2020 

#include <stdio.h>
#include <stdlib.h>

void urutan();
int main()
{
 int n, x=0;
 
 printf("BAGAS DWI SULISTYO\n");
 printf("20051397076\n");
 printf("MIB2020\n");
 printf("Input n : ");scanf("%d", &n);
 urutan();
 return 0;
}

void urutan(int x,int n){
 printf("%d\n", x);
 if(x==n)
 return;
 urutan(x+1,n);
}


//Bagas Dwi Sulistyo
//20051397076
//MIB 2020