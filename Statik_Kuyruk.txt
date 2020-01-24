#include <stdio.h>
#include <stdlib.h>
struct kuyruk{
    int *liste;
    int kapasite;
    int ust;
};
//-------------------------------------------------------------------------------//
void stackkaparttir(struct kuyruk *kuy){
    kuy->kapasite=kuy->kapasite *2;
    int *yeniliste;
    yeniliste=(int*)malloc(sizeof(int)* kuy->kapasite);
    int i;
    for(i=0;i<kuy->ust;i++){
        yeniliste[i]=kuy->liste[i];
    }
    kuy->liste=yeniliste;
    printf("Kapasite artik %d\n",kuy->kapasite);
}
//-------------------------------------------------------------------------------//
struct kuyruk* kuyrukyarat(int kapasitegirdi){
    struct kuyruk *kuy;
    kuy=(struct kuyruk*)malloc(sizeof(struct kuyruk));
    kuy->ust=0;
    kuy->kapasite=kapasitegirdi;
    kuy->liste=(int*)malloc(sizeof(int)* kuy->kapasite);
    return kuy;
}
//-------------------------------------------------------------------------------//
void kuyrukpush(struct kuyruk *kuy,int sayi){
    if(kuy->kapasite==kuy->ust){
        stackkaparttir(kuy);
    }
    kuy->liste[kuy->ust]=sayi;
    printf("%d eklendi\n",kuy->liste[kuy->ust]);
    kuy->ust++;
}
//-------------------------------------------------------------------------------//
void kuyrukpop(struct kuyruk *kuy){
    printf("%d silindi\n",kuy->liste[0]);
    int i;
    for(i=0;i<(kuy->ust);i++){
        kuy->liste[i]=kuy->liste[i+1];
    }
    (kuy->ust)--;
}
//-------------------------------------------------------------------------------//
void kuyrukyaz(struct kuyruk *kuy){
    int i;
    for(i=0;i<(kuy->ust);i++){
        printf("%d ",kuy->liste[i]);
    }
    printf("\n");
}
//-------------------------------------------------------------------------------//
int main()
{
    struct kuyruk *kuyruk1=kuyrukyarat(4);
    kuyrukpush(kuyruk1,5);
    kuyrukpush(kuyruk1,10);
    kuyrukpush(kuyruk1,15);
    kuyrukpush(kuyruk1,20);
    kuyrukpush(kuyruk1,25);
    kuyrukpush(kuyruk1,30);
    kuyrukyaz(kuyruk1);
    kuyrukpop(kuyruk1);
    kuyrukpop(kuyruk1);
    kuyrukyaz(kuyruk1);
    kuyrukpush(kuyruk1,5);
    kuyrukpush(kuyruk1,10);
    kuyrukyaz(kuyruk1);
    return 0;
}
