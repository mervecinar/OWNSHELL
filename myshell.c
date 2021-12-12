#include  <string.h>
#include  <stdio.h>
#include  <stdlib.h>

#define BOYUT 500//sabit boyut belirliyorum her seferinde yazmamak için 
//aşşağıdaki 2 satır benim kullanacağım fonksiyonların imzaları onları tanımlıyorum.
void temel();
void ownshell(char **x);
 
int main(void){

   while(1){
   // devamlıve akışkan bir terminal olması adına sonsuz döngü oluşturuyorum.
        printf("Myshell>>");//benim terminalimde olduğu müddetce başa bu yazacak.
        temel(); //ana fonk. cağırıyor.
    }
    return 0;
}

 void temel(){
   char x[BOYUT];
   fgets(x,BOYUT,stdin);
   // kullanıcıdan devamlı olarak değer alınır sonsuz döngüde olduğu için 

      if(strncmp(x,"exit",4)==0) { //eğer girilen ilk 4 haneli kelime exit ise çıkış yapılır.
      printf("\n !! CIKIS YAPILIYOR !! \n");//cıkıstan önceki msj.
      exit(0);
      
    }
    else{
      char **yeni =((char **) malloc (BOYUT*sizeof(char**)));
    x[strlen(x)-1] = NULL;//yapmazsam eğer hata alıyorum.

  
    int i=0;
    //bosluklara kadar bölünmüş değerler bosluk da kalır 
    char ** bosluk = strtok(x, " ");
    while( bosluk != NULL ) { 
        yeni[i] = (char**) malloc((strlen(bosluk)) * sizeof(char **));
        strcpy(yeni[i],bosluk);  //değerler yeniye kopyalanıyor.
        bosluk = strtok(NULL, " ");    
        i=i+1;
    }
    // boşlukda boşluk lara kadar olan değerler ayrılır strtok fonk yardımı ile ardından bir 
    //döngü ile değerler yeni ye atanır.
   
    int sayac = 0;// boşlukların sayısını burada tutuyorum.
    while(yeni[sayac]!=NULL){
        sayac=sayac+1;
    }
        for(int i=0;i<sayac;i++){ 
               if(i=sayac-1){
        // tekrar 3 merve de hepsi bitince yanideğerlerin hepsi gelince ownshell cagrılır.
               ownshell(yeni);
                
        }  

    }
}
}
void ownshell(char ** x){

    int sayac = 0;
    while(x[sayac]!=NULL){
        sayac++;
    }
    // sayac burada boşluk tutuyor
   
int k=0;
char **y=((char **) malloc (BOYUT*sizeof(char**)));
// aşşağıdaki for döngüsü | yazıldığında yazılan tüm islemleri gerçekleştirmek adına yapıldı.
// zaten | yazılmadıysa temel()  fonk. sonundaki for dan direk bu fonk geliyor ve aşşağıdaki
//islemler ile işini halledip gidiyor.

for (int i=0; i<sayac; i++){
/*
örn elimizde  tekrar merve  3 | islem topla 3 4 oslun.
| öncesi için bu loop da hiç bir şey yapamaz bu yüzden o x de kalır ve aşşağıda gerekli işlem yapılır. | geldiğinde ise bundan sonraki string yeni bir pointer olan y ye tektek boşluklar ile ayrılarak atılır  yani y[k]da =islem,topla,3,4 vardır.
*/
            if(strcmp(x[i],"|")==0){// | var ise dönüye girer
            while ( i<sayac-1 || x[i+1]!=NULL){// x sayac bitene ve null olana kadar devam
            y[k]=x[i+1];// islem topla 3 4 tek tek y ye atanıyor.
            k++;
            i++;
            }
            ownshell(y);// atama bittiğinde // ile bu fonksiyon tekrar cağırılıyor.
//burada | sonraki pointer cağrıldığı için ilk | sonrası yapılıyor islem bitiyor v

//e | öncesi için aşşğıda devam ediliyor.
                }
}
    pid_t forka;//process_id türü pid_t .
    int v;
    int n;
    
    // ilk haneler yazılan stringe eşit ise caseler için değer atanıyor.
    if(strncmp(x[0],"tekrar",6)==0){ 
    n=1;
    }
    else if (strcmp(x[0],"islem")==0){ 
     n=2; 
    }

    else if(strncmp(x[0],"bash",4)==0){
       n=3;
    }
    else if(strncmp(x[0],"cat",3)==0){
       n=4;
    }
        else if(strncmp(x[0],"clear",5)==0){
       n=5;
    }
       else if(strncmp(x[0],"ls",2)==0){
       n=6;
    }
    
    switch(n)
    {
    case 1://tekrar
    // tekrar için fork child oluşturur ve  bu birebir parentin aynısıdır. 
            forka = fork();
            if(forka == 0){ // childe ise;
              v = execve("tekrar",x,NULL);//process içinde ayrı process cağırma.
            }
            else{
              wait(&v); 
  //cağırılan program yarıda kalmasın sorun olmasın diye onun bitirmesini bekliyoruz
        }
           break;
     case 2://islem
            forka = fork(); 
            if(forka== 0){ 
                v = execve("islem",x,NULL);
            }
            else{
                wait(&v); 
            
             }   
             break;
       case 3:// bin sys deki bin i calıştıtıır.cıktığında benim myshellime gelir.
             system("/bin/bash");
             break;
       case 4:// cat yazılanları olduğu gibi ekrana getirir.
             printf("\n cat : %s \n", x[1]);
             break;
       case 5://sayfayı temizler.
             system("clear");
             break;
       case 6:// o dosyadaki soyaları gösterir.
             system("/bin/ls");
             break;
             
       default:// eğer hiçbiri olmadıysa default aşşağıdaki msj döndüür.
       
       printf("! Eksik veya yanlış bir komut girdiniz .Tekrar Deneyiniz!");
       break;    
    }
    }
