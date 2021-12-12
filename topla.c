#include  <string.h>
#include  <stdio.h>
#include  <stdlib.h>

//Burada komutta 1 ve 2 gibi bir değer vardır atio ile bunlar int olur ve z değerinde sonuç vardır.

int main(int argc, char *komut[]){

    int a = atoi(komut[0]);
    
    int b = atoi(komut[1]);
    
    int z = a + b;
    
    printf("\n TOPLAMA : %d  +  %d  =  %d  \n\n", a , b , z );
 // birint ile girilen değerler ve toplam basılır.
    return 0;
}
