#include <stdio.h>
#include <stdlib.h>

int LinkedListMake(int[],int[],int[],int[],int,int,int,int,int);
void Display(int[],int[],int);
int insert(int[],int[],int,int,int);

int main(int argc, char *argv[]) {
	int i,HeadA,HeadB,HeadC,NA,NB,NC,ENO;
	printf("A dizisinin eleman sayisi\n");
	scanf("%d",&NA);
	printf("B dizisinin eleman sayisi\n");
	scanf("%d",&NB);
	NC=NA+NB;
   	int A[NA],B[NB],C[NC],LinkA[NA],LinkB[NB],LinkC[NC];
    printf("HeadA giriniz\n");
	scanf("%d",&HeadA);
	printf("HeadB giriniz\n");
	scanf("%d",&HeadB);
	printf("A dizisini giriniz\n");
	for(i=0;i<NA;i++){
	    scanf("%d",&A[i]);	
	}
	printf("B dizisini giriniz\n");
	for(i=0;i<NB;i++){
	    scanf("%d",&B[i]);	
	}
	printf("LinkA dizisini giriniz\n");
	for(i=0;i<NA;i++){
	    scanf("%d",&LinkA[i]);	
	}
	printf("LinkB dizisini giriniz\n");
	for(i=0;i<NB;i++){
	    scanf("%d",&LinkB[i]);	
	}
    //A ve B dizilerini birleþtirerek C dizisini elde ediyoruz
	for(i=0;i<NA;i++){
		C[i]=A[i];
	}
	int j=0;
	for(i=NA;i<NC;i++){
		C[i]=B[j];
		j++;
	}
	//C dizisinin linked listini oluþturmak için kullandýðým fonksiyon
    HeadC=LinkedListMake(C,LinkA,LinkB,LinkC,NA,NB,NC,HeadA,HeadB);
    
    printf("eklenecek elemani giriniz");
    scanf("%d",&ENO);
    HeadC=insert(C,LinkC,HeadC,NC,ENO);
	
	
    
	
    //C dizisini sýralý bir þekilde ekrana yazdýrmak için kullandýðým fonksiyon
	Display(C,LinkC,HeadC);
  	for(i=0;i<= NC;i++){
  		printf("%d    ",LinkC[i]);
	  }

	return 0;
}
int LinkedListMake(int C[],int LinkA[],int LinkB[],int LinkC[],int NA,int NB,int NC,int HeadA,int HeadB){
    int prevA,prevB,next,HeadC;
	prevA=HeadA;
    prevB=HeadB;
    if( C[prevA] <= C[NA+prevB] ){
        HeadC = prevA;
        prevA = LinkA[prevA];
    }
    else{
        HeadC =NA + prevB;
        prevB = LinkB[prevB];
    }
    next = HeadC;
    while((prevA != -1) && (prevB != -1 )){
        if( C[prevA] <= C[NA+prevB] ){
               printf("karsilastirilan A dizisi indisi:  %d   ve elemani:  %d   \n ",prevA,C[prevA]);
		   printf("karsilastirilan B dizisi indisi:  %d+%d   ve elemani: %d     \n ",NA,prevB,C[NA+prevB]);
		   
		    LinkC[next] = prevA;
            prevA = LinkA[prevA];
    
           printf("linkC deki atanan deðer ve indisi :  %d    %d\n\n ",LinkC[next],next);

		}
    
        else{
                     printf("karsilastirilan A dizisi indisi:  %d   ve elemani:  %d   \n ",prevA,C[prevA]);
		   printf("karsilastirilan B dizisi indisi:  %d+%d   ve elemani: %d     \n ",NA,prevB,C[NA+prevB]);
		   
			
			LinkC[next] =NA + prevB;
            prevB = LinkB[prevB];
            
             printf("linkC deki atanan deger ve indisi : %d   %d\n\n ",LinkC[next],next);
        }
        next = LinkC[next];
    }
    //B dizisi bitince kalan A dizisi için linked list tamamlýyoruz
    while(prevA != -1){
        LinkC[next] = prevA;
		prevA = LinkA[prevA];
        next = LinkC[next];
    }
    //A dizisi bitince kalan B dizisi için linked list tamamlýyoruz
    while(prevB != -1){
		LinkC[next] =NA + prevB;
        prevB = LinkB[prevB];
        next = LinkC[next];
    }
    //En son kalan boþluk için -1 koyuyoruz,böylece linked list tamamlanmýþ oluyor
    LinkC[next] = -1 ;    
    
    return HeadC;
	}
int insert(int C[], int LinkC[],int HeadC,int NC,int ENO){
	int prev,next;
	C[NC]=ENO;
	NC=NC+1;
	if(ENO<=C[HeadC]){
		LinkC[NC-1]=HeadC;
		HeadC=NC-1;
	}
	else{
		prev = HeadC;
		next = LinkC[HeadC];
		while(next!=-1 && C[next]<ENO){
			prev=next;
			next=LinkC[next];
		}
		LinkC[prev]=NC-1;
		LinkC[NC-1]=next;
	}
	return HeadC;
}

void Display(int C[],int LinkC[],int HeadC){
	int next=HeadC;
	printf("Sirali sekilde C dizisi : \n");
	while(next!=-1){
		printf("%d     ",C[next] );
        next=LinkC[next];
    }
}

		
