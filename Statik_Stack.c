#include <stdio.h>
#include <stdlib.h>
struct stack{
    int *liste;
    int kapasite;
    int ust;//stack içindeki ilk boþ yeri gösterir
};
//---------------------------------------------------------------------//
void stackkaparttir(struct stack *stc){
    stc->kapasite=stc->kapasite *2;
    int *yeniliste;
    yeniliste=(int*)malloc(sizeof(int)* stc->kapasite);
    int i;
    for(i=0;i<stc->ust;i++){//eski dizinin elemanlarý yeni oluþturulan diziye atýlýr
        yeniliste[i]=stc->liste[i];
    }
    stc->liste=yeniliste;
    printf("Kapasite artik %d\n",stc->kapasite);
}
//---------------------------------------------------------------------//
struct stack* stackyarat(int kapasitegirdi){
    struct stack *stc;
    stc=(struct stack*)malloc(sizeof(struct stack));
    stc->ust=0;
    stc->kapasite=kapasitegirdi;
    stc->liste=(int*)malloc(sizeof(int)* stc->kapasite);
    return stc;
}
//---------------------------------------------------------------------//
void stackpush(struct stack *stc,int sayi){
    if(stc->kapasite==stc->ust)
        stackkaparttir(stc);
    stc->liste[stc->ust]=sayi;
    stc->ust++;
}
//---------------------------------------------------------------------//
void stackpop(struct stack *stc){
    printf("%d silindi\n",stc->liste[stc->ust-1]);
    //stc->liste[stc->ust-1]=0;
    stc->ust--;
}
//---------------------------------------------------------------------//
void stackyaz(struct stack *stc){
    int i;
    for(i=(stc->ust)-1;i>-1;i--){
        printf("%d ",stc->liste[i]);
    }
    printf("\n");
}
//---------------------------------------------------------------------//
int main()
{
	//stackyarat fonksiyonu ilk durum için çaðrýlmalýdýr
    struct stack *stack1=stackyarat(4);//4 elemanlý diziyi tutan stack yapýsý oluþur
    stackpush(stack1,5);
    stackpush(stack1,10);
    stackpush(stack1,15);
    stackpush(stack1,20);
    stackpush(stack1,25);
    stackpush(stack1,30);
    stackyaz(stack1);
    stackpop(stack1);
    stackpop(stack1);
    stackyaz(stack1);
    stackpush(stack1,25);
    stackpush(stack1,30);
    stackyaz(stack1);
    return 0;
}
