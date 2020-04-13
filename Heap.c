#include <stdio.h>
#include <stdlib.h>
struct heap{
    int *dizi;
    int kapasite;
    int ust;//dizideki ilk boþ yeri tutar
};
//-------------------------------------------------------------------------------------//
struct heap* heap_olustur(int kapasite){
    struct heap *yeni=(struct heap*)malloc(sizeof(struct heap));
    yeni->kapasite=kapasite;
    yeni->ust=0;
    yeni->dizi=malloc(sizeof(int)*kapasite);
    int i;
    return yeni;
}
//-------------------------------------------------------------------------------------//
void heap_ekle(struct heap *heapfonk,int sayi){
    if(heapfonk->kapasite <= heapfonk->ust)
        heap_kaparttir(heapfonk);
    heapfonk->dizi[heapfonk->ust]=sayi;
    //sayý eklendikten sonra heap bozuldu mu kontrolü yapýlýr
    int parentindex;
    if((heapfonk->ust)%2==0)//eðer kendi index'i çift sayý ise parent'ýnýn saðýdýr
        parentindex=(heapfonk->ust -2)/2;//saðdaysa 2 çýkarýlýr (i+2)*2'nin tersi
    else
        parentindex=(heapfonk->ust -1)/2;//saðdaysa 1 çýkarýlýr (i+1)*2'nin tersi
    int ust=heapfonk->ust;
    while(1){
        if(heapfonk->dizi[ust]>heapfonk->dizi[parentindex]){//eðer parenttan büyük ise bozukluk vardýr
            //parent ile child'ýn yeri deðiþtirilir
			int temp=heapfonk->dizi[parentindex];
            heapfonk->dizi[parentindex]=heapfonk->dizi[ust];
            heapfonk->dizi[ust]=temp;
            //roota gelinmediði sürece indexler yukarýya taþýnýr
            if(parentindex==0)//parent==root
                break;
            ust=parentindex;
            if((parentindex)%2==0)
                parentindex=(parentindex-2)/2;
            else
                parentindex=(parentindex-1)/2;
        }
        else//bozukluk yoksa döngüden çýkýlýr
            break;
    }
    (heapfonk->ust)++;
}
//-------------------------------------------------------------------------------------//
void heap_yaz(struct heap *heapfonk){
    int i;
    for(i=0;i<heapfonk->ust;i++){
        printf("%d ",heapfonk->dizi[i]);
    }
    printf("\n");
}
//-------------------------------------------------------------------------------------//
void heap_sil(struct heap *heapfonk,int sayi){
    int i=0;
    while(1){//sayi var mi diye bakýlýr. Sayi bulunursa i, sayinin indexidir
        if(i==heapfonk->ust){
            printf("silinmek istenen sayi yok...\n");
            return;
        }
        if(sayi==heapfonk->dizi[i])
            break;
        i++;
    }
    while(1){//silinen düðümün yerine alttan yeni düðüm getirilir.
    	/*Burada 4 ana durum vardýr
    	 *	1.durum için altta eleman kalmadýysa dizinin sonundaki eleman kendisine atanýr ve üst bir azaltýlýr. Bundan sonra heap kontrolü yapýlýr 
    	 *	2.durum için düðümün sadece solu kalmýþsa o yukarý taþýnýr ve heap'in son elemaný olduðundan üst bir azaltýlýr. Bozulma olmadýðýndan kontrole gerek yoktur
    	 *	ilk iki koþul doðru deðilse yukarýya taþýnacak olan düðüm sað veya solundan hangisi büyükse odur.
    	 *	3.durum için sol büyükse
    	 *	4.durum için sað büyükse
    	 *	3. ve 4. durumlardan sonra index aþaðý taþýnýr
		 */ 
        if(i*2+2>heapfonk->ust){//1.durum
            heapfonk->dizi[i]=heapfonk->dizi[heapfonk->ust-1];
            (heapfonk->ust)--;
            //ekle fonksiyonundaki gibi heapify yapýlýr 
            int parentindex;
            if(i%2==0)
                parentindex=(i-2)/2;
            else
                parentindex=(i-1)/2;
            while(1){
                if(heapfonk->dizi[i]>heapfonk->dizi[parentindex]){
                    int temp=heapfonk->dizi[parentindex];
                    heapfonk->dizi[parentindex]=heapfonk->dizi[i];
                    heapfonk->dizi[i]=temp;
                    //roota gelinmediði sürece indexler yukarýya taþýnýr
                    if(parentindex==0)//parent==root
                        break;
                    i=parentindex;
                    if((parentindex)%2==0)
                        parentindex=(parentindex-2)/2;
                    else
                        parentindex=(parentindex-1)/2;
                }
                else
                    break;
            }
            break;
        }
        else if(i*2+2==heapfonk->ust){//2.durum     	
			heapfonk->dizi[i]=heapfonk->dizi[i*2+1];
			(heapfonk->ust)--;
			break;
		}
        else if(heapfonk->dizi[i*2+1] > heapfonk->dizi[i*2+2]){//3.durum
            heapfonk->dizi[i]=heapfonk->dizi[i*2+1];
            i=i*2+1;
        }
        else{//4.durum
            heapfonk->dizi[i]=heapfonk->dizi[i*2+2];
            i=i*2+2;
        }
    }//while biter
}
//-------------------------------------------------------------------------------------//
void heap_kaparttir(struct heap *fonkheap){
    int *dizi=malloc(sizeof(int)*(fonkheap->kapasite*2));
    int i;
    for(i=0;i<fonkheap->ust;i++){//tüm elemanlar yeni diziye atanýr
        dizi[i]=fonkheap->dizi[i];
    }
    fonkheap->dizi=dizi;
    fonkheap->kapasite*=2;
    printf(" kap artti\n");
}
//-------------------------------------------------------------------------------------//
int main()
{
    struct heap *heap1=heap_olustur(5);
    heap_yaz(heap1);
    heap_ekle(heap1,15);
    heap_yaz(heap1);
    heap_ekle(heap1,10);
    heap_yaz(heap1);
    heap_ekle(heap1,5);
    heap_yaz(heap1);
    heap_ekle(heap1,45);
    heap_yaz(heap1);
    heap_ekle(heap1,55);
    heap_yaz(heap1);
    heap_ekle(heap1,65);
    heap_yaz(heap1);
    heap_ekle(heap1,1);
    heap_yaz(heap1);
    heap_ekle(heap1,4);
    heap_yaz(heap1);
    heap_ekle(heap1,3);
    heap_yaz(heap1);
    heap_ekle(heap1,2);
    heap_yaz(heap1);
    heap_sil(heap1,45);
    heap_yaz(heap1);
    return 0;
}
