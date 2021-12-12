#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// komut değişkeninde şöyle bir şey vardır tekrar merve 3 
//burada komut[0]=tekrar, komut[1]=merve , komut[2]=3 ve hepsi stringtir.
//atoi ile 3 int a çevrilir.
int main(int argc, char *komut[]) {
    int i = 0; 
    //yukarıdaki örn e göre 3 e kadar sürecek döngüye girer.
    while  (i < atoi(komut[2])){
        printf("\n %d. TEKRAR :  %s  \n", i+1 , komut[1]);// 3 kez basar.
      i=i+1;
    }
    // eğer merve ve 3 den biri eksikse mesaj döndürür. 
    //komut[0] a bakmaya gerek yok çünkü o myshell de kontrol edilerek zaten buraya gelir.
    if(komut[1]==NULL || komut[2]==NULL){
    
    printf("\n Eksik veya yanlış sonuç girdiniz .Tekrar deneyiniz ! \n ");
    
    }
    
    return 0;
}
