#include <stdio.h>
#include <stdlib.h>
struct stack{
    int veri;
    struct stack *link;
};
//---------------------------------------------------------------------------------------------//
struct stack* stackyarat(int sayi){
    struct stack *yeni=(struct stack*)malloc(sizeof(struct stack));
    yeni->veri=sayi;
    yeni->link=NULL;
    return yeni;
}
//---------------------------------------------------------------------------------------------//
void stackpush(struct stack **listebasi,int sayi){
    if(*listebasi==NULL){
        *listebasi=stackyarat(sayi);
        (*listebasi)->link=NULL;
        return;
    }
    else{
    	struct stack *yeni;
        yeni=stackyarat(sayi);
        yeni->link=*listebasi;
        *listebasi=yeni;
    }
}
//---------------------------------------------------------------------------------------------//
void stackyaz(struct stack *listebasi){
	if(listebasi==NULL)
	    printf("stack bos");
	while(listebasi!=NULL){
            printf("%d ",listebasi->veri);
            listebasi=listebasi->link;
	}
	printf("\n");
}
//---------------------------------------------------------------------------------------------//
void stackpop(struct stack **listebasi){//
    struct stack *silinecek=*listebasi;
    *listebasi=(*listebasi)->link;
    printf("%d silindi\n",silinecek->veri);
    free(silinecek);
}
//---------------------------------------------------------------------------------------------//
int main()
{
    struct stack *stc1=NULL;
    stackpush(&stc1,10);
    stackpush(&stc1,15);
    stackpush(&stc1,25);
    stackpush(&stc1,35);
    stackyaz(stc1);
    stackpop(&stc1);
    stackpop(&stc1);
    stackyaz(stc1);
    struct stack *stc2=NULL;
    stackpush(&stc2,1);
    stackpush(&stc2,2);
    stackpush(&stc2,3);
    stackyaz(stc2);
    stackpop(&stc2);
    stackpop(&stc2);
    stackpop(&stc2);
    stackyaz(stc2);
    return 0;
}
