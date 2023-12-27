#include<stdio.h>
 #include<string.h>
struct Book{
	char name[50];
	char yazar[50];
	int sayfasayisi;
	int tarih;
	int sayi;
};
void listele(struct Book kitaplar[],int kitapsay);
void kayitekle(struct Book kitaplar[],int* kitapsay);
void kayitsil(struct Book kitaplar[],int *kitapsay);
int menu();
int main(){
	struct Book kitaplar[50];
	int kitapsay=0,a;
do {
	int secim=menu();
	switch(secim){
		case 1:
			kayitekle(kitaplar,&kitapsay);
			break;
		case 2:
			kayitsil(kitaplar,&kitapsay);
			break;
		case 3:
			listele(kitaplar,kitapsay);
			break;
	}
	printf("durdurmak için 0 a basin\n");scanf("%d",&a);
	}while(a!=0);
	
	
}
int menu(){
	int secim;
	printf("****menu****\n");
	printf("1-kayit ekleme\n2-kayit sil\n3-listele\n");
	printf("yapmak istediginiz islemin numarasini giriniz\n");scanf("%d",&secim);
	return secim; 
}
void kayitekle(struct Book kitaplar[],int* kitapsay){
	int secim;
	
			printf("kitap adi:\n");getchar("%c",kitaplar[*kitapsay].name);
	        printf("yazar adi:\n");getchar("%c",kitaplar[*kitapsay].yazar);
    	    printf("yayin tarihi:\n");scanf("%d",&kitaplar[*kitapsay].tarih);
    	    printf("sayfa sayisi:\n");scanf("%d",&kitaplar[*kitapsay].sayfasayisi);
    	    printf("kac adet:\n");scanf("%d",&kitaplar[*kitapsay].sayi);
		   (*kitapsay)++;
		    }
			
	
void listele(struct Book kitaplar[], int kitapsay) {
    int i;
    printf("\nKitap Listesi:\n");
    for (i = 0; i < kitapsay; i++) {
        printf("%d. Kitap:\n", i + 1);
        printf("Adi: %s\n", kitaplar[i].name);
        printf("Yazari: %s\n", kitaplar[i].yazar);
        printf("Yayin Tarihi: %d\n", kitaplar[i].tarih);
        printf("Sayfa Sayisi: %d\n\n", kitaplar[i].sayfasayisi);
    }
}
void kayitsil(struct Book kitaplar[],int *kitapsay){
	int sonuc,i;
	int x=-2; 
	char name[100];
	printf("silinecek kitabın adi:");scanf("%s",name);
	for(i=0;i<*kitapsay;i++){
		sonuc= strcmp (name,kitaplar[i].name);
		if(sonuc==0){
			x=i;
			for(i=x;i<*kitapsay-1;i++){
				kitaplar[i]=kitaplar[i+1];
			}
			(*kitapsay)--;
			
			
		}
		else{
			printf("boyle bir kitap bulunamadi\n");
		}
	}
}

