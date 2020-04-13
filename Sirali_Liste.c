#include <stdio.h>
#include <stdlib.h>
struct liste{
	int veri;
	struct liste *link;
};
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct liste* olustur(int sayi){
	struct liste *yeni=(struct liste*)malloc(sizeof(struct liste));
	yeni->link=NULL;
	yeni->veri=sayi;
	return yeni;
}
//-------------------------------------------------------------------------------//
struct liste* siraliekle(struct liste *list,int sayi){
	struct liste *kok=list;
	if(list==NULL){
		return olustur(sayi);
	}
	struct liste *geri=NULL;
	while(list!=NULL && list->veri < sayi){
		geri=list;
		list=list->link;
	}
	if(list==NULL){//sona ekleme durumu
		geri->link=olustur(sayi);
		return kok;
	}
	if(list->veri==sayi){//aynı sayı durumu
		printf("sayi zaten var..\n");
		return kok;
	}
	if(kok==list){//basa ekleme durumu
		struct liste *yeni=olustur(sayi);
		yeni->link=kok;
		return yeni;
	}
	//normal ekleme durumu
	geri->link=olustur(sayi);
	geri->link->link=list;
	return kok;
}
//-------------------------------------------------------------------------------//
struct liste* sil(struct liste *list,int sayi){
	if(list==NULL)	return NULL;
	struct liste *listebasi=list;
	struct liste *geri=NULL;
	while(list !=NULL && list->veri!=sayi){
		geri=list;
		list=list->link;
	}
	if(list==NULL){//sayi yoksa
		printf("silinmek istenen sayi yok..\n");
		return listebasi;
	}
	if(list==listebasi){//ilk eleman siliniyorsa
		list=list->link;
		free(listebasi);
		return list;
	}//normal durum
	geri->link=list->link;
	free(list);
	return listebasi;
}
//-------------------------------------------------------------------------------//
void yazdir(struct liste *list){
	while(list!=NULL){
		printf("%d ",list->veri);
		list=list->link;
	}
	printf("\n");
}
//-------------------------------------------------------------------------------//
int main(int argc, char *argv[]) {
	struct liste *liste1=NULL;
	liste1=siraliekle(liste1,5);
	liste1=siraliekle(liste1,10);
	liste1=siraliekle(liste1,15);
	liste1=siraliekle(liste1,12);
	liste1=siraliekle(liste1,9);
	liste1=siraliekle(liste1,3);
	liste1=siraliekle(liste1,4);
	liste1=siraliekle(liste1,3);
	yazdir(liste1);
	liste1=sil(liste1,3);
	yazdir(liste1);
	liste1=sil(liste1,9);
	liste1=sil(liste1,4);
	yazdir(liste1);
	return 0;
}
