#include <stdio.h>
#include <stdlib.h>
struct agac{
    int deger;
    struct agac *sol;
    struct agac *sag;
};
//--------------------------------------------------------------------------------------------------//
int solmu;
struct agac *yeni,*gecici,*silinecek,*geri;
struct agac * AgacOlustur(int eleman){
    struct agac *root;
    root=(struct agac*)malloc(sizeof(struct agac));
    root->sol=NULL;
    root->sag=NULL;
    root->deger=eleman;
    return root;
}
//--------------------------------------------------------------------------------------------------//
struct agac* AgacaElemanEkle(struct agac *root,int eleman){//verilen sayıyı, verilen kökün ağacına ekler
    if(root==NULL){
    	return AgacOlustur(eleman);
	}
	else if(eleman > root->deger){
		root->sag=AgacaElemanEkle(root->sag,eleman);
	}
	else if(eleman < root->deger){
		root->sol=AgacaElemanEkle(root->sol,eleman);
	}
	else{
		printf("eleman zaten var..\n");
	}
	return root;
}
//--------------------------------------------------------------------------------------------------//
void AgacYazdir(struct agac *root){//PreOrder
    if(root==NULL) return;
    printf("%d ",root->deger);
    AgacYazdir(root->sol);
    AgacYazdir(root->sag);
}
//--------------------------------------------------------------------------------------------------//
struct agac* AgactanSil(struct agac *root,int eleman){//verilen kökün ağacındaki bir elemanı bulup siler, ağacın kopan elemanlarını bağlar
    if(root==NULL)
        return NULL;
    if(eleman==root->deger){
        struct agac *iter=root;
        struct agac *geri;
        if(root->sol==NULL && root->sag==NULL)//eleman yapraksa çağrıldığı yere null döndürülerek koparılır
            return NULL;
        if(root->sag!=NULL){//burdan if'in bitimine kadar işlemler sağ taraf üzerinden yapılır eğer if'e girilmez ise alt tarafta sola göre yapılır
            //sağın en soluna gidilir
			geri=iter;
            iter=iter->sag;
            while(iter->sol!=NULL){
            	geri=iter;
                iter=iter->sol;
			}
			//sağın en solu silinecek yere yazılır ve gidilen yer silinmek üzere fonksiyonu yollanır
            root->deger=iter->deger;
            if(iter->sag!=NULL){//bu blok eğer sağın en soluna gidildiğinde onun da sağı varsa kullanılır
            	if(root==geri)
            		geri->sag=iter->sag;
            	else
                	geri->sol=iter->sag;
        		iter->sag=NULL;
			}
            root->sag=AgactanSil(root->sag,iter->deger);
            return root;
        }//sola göre aynı işlemler
        	geri=iter;
            iter=iter->sol;
            while(iter->sag!=NULL){
            	geri=iter;
				iter=iter->sag;
			}
            root->deger=iter->deger;
            if(iter->sol!=NULL){//bu blok eğer sağın en soluna gidildiğinde onun da sağı varsa kullanılır
            	if(root==geri)//sol child ise
            		geri->sol=iter->sag;
            	else//sağ child ise
                	geri->sag=iter->sag;
                iter->sol=NULL;
    		}//solun en sağı yaprak olur
            root->sol=AgactanSil(root->sol,iter->deger);
            return root;
    }
	//elemanı bulamazsa sağ veya sola bakılır
    if(eleman> root->deger){
        root->sag=AgactanSil(root->sag,eleman);
        return root;
    }
    root->sol=AgactanSil(root->sol,eleman);
    return root;
}
//--------------------------------------------------------------------------------------------------//
int main()
{
    struct agac *kok1=NULL;
    kok1=AgacOlustur(12);
    kok1=AgacaElemanEkle(kok1,35);
    kok1=AgacaElemanEkle(kok1,10);
    kok1=AgacaElemanEkle(kok1,25);
    kok1=AgacaElemanEkle(kok1,5);
    kok1=AgacaElemanEkle(kok1,11);
    kok1=AgacaElemanEkle(kok1,40);
    kok1=AgacaElemanEkle(kok1,45);
    AgacYazdir(kok1);
    printf("\n");
    kok1=AgactanSil(kok1,35);
    AgacYazdir(kok1);
    printf("\n");
    kok1=AgactanSil(kok1,12);
    AgacYazdir(kok1);
    printf("\n");
    kok1=AgactanSil(kok1,10);
    AgacYazdir(kok1);
    printf("\n");
    kok1=AgactanSil(kok1,5);
    AgacYazdir(kok1);
    printf("\n");
    kok1=AgactanSil(kok1,11);
    AgacYazdir(kok1);
    printf("\n");
    return 0;
}
