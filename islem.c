#include  <string.h>
#include  <stdio.h>
#include  <stdlib.h>
// Gelen komut değişkeninde şöyle bir değer var islem topla 1 2 
int main(int argc, char *komut[]){

     int *c[3];
     
     c[0] = komut[2];// yukarıdaki verdiğim örnekte 1 i tutuyor
     c[1] = komut[3];// buda 2 yi tutuyor ve atıyor aynı zamanda string olarak.
     c[2] = NULL;
     if(komut [2] == NULL || komut [3] == NULL){
     // eğer 1 veya 2 eksikse aşşağıdaki mesajı verir. 
     
     printf("\n Eksik veya Hatalı bir komut girdininiz.Tekrar Deneyiniz!.\n");
     }
    
    int m;

    m = execv(komut[1] , c);
    //komut[1] ise topla değişkenini tutuyor. eğer cikar ise execv ile çikar a yolluyor. 
    
    return 0;
}
