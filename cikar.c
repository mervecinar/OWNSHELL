#include  <string.h>
#include  <stdio.h>
#include  <stdlib.h>

// komut değerinde 1 ve 2 gibi değerler vardır fakat stringtir atoi ile bunlar int olur.

int main(int argc, char *komut[]){

    int d = atoi(komut[0]);
    
    int e = atoi(komut[1]);
    
    int z = d - e ; // fark sonucu d de tutulur.
    
    // son olarak kullanıcıya gözükecek mesaj basılır.
    printf("\n CIKARTMA : %d  -  %d  =  %d  \n\n", d , e , z );
    
    return 0;
}
