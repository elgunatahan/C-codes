#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
typedef struct tree {
	int No;
	char Ad[100];
	char Soyad[100];
    int arkadaslar[100];
	struct tree *left;
	struct tree *right;
	
}tree;
tree * insertNewUser(tree *,int ,char[],char[]); //Her girilen yeni elemani eklemektedir,ald��� parametreler agac�m�z numara ad soyadd�r,ve d�n�� de�eri agac�m�z�n adresidir(struct agac�m�z)
void printInOrder(tree *);    //Left Node Right olacak �ekilde erkana s�ral� bir �ekilde agac� yazd�rmakta,ald��� parametre agac�m�z�n adresi
void contains(tree *,int );    //girilen degerin agacta olup olmad���n� kontrol etmektedir,var ise ad�n� soyad�n� yazd�r�yor. Ald��� parametreler agac�m�z�n adresi ve aranacak eleman
tree * Roam(tree *,int );   //girilen degerin agactaki yerini bulup adresini geri g�ndermektedir. Ald�g� parametreler agac�m�z�n adresi ve aranacak eleman
void Friends(tree *,int );   //Verilen bir degerin arkada�lar�n� agacta olup olmamas�na g�re yazd�rmaktad�r.Adl��� de�erler agac�m�z�n adresi ve eleman
int size(tree *,int );    //Agacta ka� eleman oldu�unu bulur.Aldugu de�erler agac�m�z�n adresi ve size . D�n�� de�eri eleman sayisi
tree * max(tree *);       //Agac�n solun en b�y���n� bulmaktad�r.d�n�� de�eri agac�n adresi
tree * min(tree *);       //Agac�n sa��n en k�����n� bulmaktad�r.d�n�� de�eri agac�n adresi
tree * aradegersag(tree *,tree *); //Agac�n solun en k�����n�n bir �ncesini bulmaktad�r.d�n�� de�eri agac�n adresi
tree * aradegersol(tree *,tree *); //Agac�n solun en b�y���n�n bir �ncesini bulmaktad�r.d�n�� de�eri agac�n adresi
tree * deleteUser(tree *,int );    //Girilen eleman� a�actan silmekte ve yeni agac�n adresini geri g�ndermektedir
void printNext(tree *agac , int );  //Girilen numaray� Roam fonksiyonu vas�tas�yla adresini bulmakta ve sonra alt�ndakileri ekrana yazd�rmaktad�r.girdileri agac�m�z�n adresi ve degerimiz
void printGreater(tree * ,int );    //Girilen de�erden agactaki b�y�k elemanlar� ekrana yazd�rmakta. Girdileri agac�m�z�n adresi ve degerimiz
tree * readFromFile(tree *);   // Txt dosyas�ndan numara ad soyad agacama y�klememizi sa�lar.girdileri agac�m�z�n adresi.D�n�� de�eri yeni agac�m�z�n adresi



int main(int argc, char *argv[]) {
	int eNo,aNo,sNo,menu,sayi=0;
	char Ad[100],Soyad[100];
	tree *agac = NULL;
	do{
	
		printf(" For insertNewUser press 1\n ");
		printf(" For deleteUser press 2\n ");
		printf(" For contains press 3\n ");
		printf(" For Friends press 4\n ");
		printf(" For size press 5\n ");
		printf(" For printNext press 6\n ");
		printf(" For printGreater press 7\n ");
		printf(" For printInOrder press 8\n ");
		printf(" For Reading txt file press 9\n ");
		printf(" For Exit press 0\n ");
		scanf("%d",&menu);
		switch (menu){
			case 1 :
				printf("Kimlik numarasi,Ad ve Soyad giriniz :");
				scanf("%d\n%s\n%s",&eNo,Ad,Soyad);
				agac=insertNewUser(agac,eNo,Ad,Soyad);
				system("cls");
				break;
		    case 2 :
		    	printf("Silinecek elemanin numarasini giriniz :");
		    	scanf("%d",&sNo);
		    	agac=deleteUser(agac,sNo);
		    	system("cls");
		    	break;
		    case 3 :
		    	printf("Aranacak elemanin numarasini giriniz :");
		    	scanf("%d",&aNo);
		    	contains(agac,aNo);
		        break;
		    case 4 :
		    	printf("Hangi elemanin arkadaslarini ariyorsunuz :");
		    	scanf("%d",&aNo);
		    	Friends(agac,aNo);
                break;
		    case 5 :
		        sayi=size(agac,sayi);
		    	printf("Agactaki eleman sayisi %d \n ",sayi);
		    	break;
		    case 6 :
		    	printf("hangi dugumun alt agacini istiyorsunuz ");
		    	scanf("%d",&aNo);
		    	printNext(agac,aNo);
		    	break;
		    case 7 :
		    	printf("hangi elemandan buyuklerini yazdirmak istiyorsunuz ");
		    	scanf("%d",&aNo);
		    	printGreater(agac,aNo);
		    	break;
		    case 8 :
		    	printInOrder(agac);
		    	break;
		    case 9 :
		    	agac=readFromFile(agac);
		    	system("cls");
		    	break;
		}
		
	}while(menu!=0);

	return 0;
}
tree * insertNewUser(tree *agac,int eNo,char Ad[],char Soyad[]){	
    int i,sayi;
	if(agac == NULL){
		tree *root =(tree*)malloc(sizeof(tree));
	    root->No=eNo;
	    root->left=NULL;
	    root->right=NULL;
        strcpy(root->Ad,Ad);
        strcpy(root->Soyad,Soyad);
        printf("arkadas sayisini giriniz\n");
        scanf("%d",&sayi);
        for(i=0;i<sayi;i++){
       	    printf("[%d] arkadasin numarasini giriniz",i+1	);
       	    scanf("%d",&root->arkadaslar[i]);
	    }
	    root->arkadaslar[i]='\0';
	    return root;
	}
	if(eNo<agac->No){
		agac->left=insertNewUser(agac->left,eNo,Ad,Soyad);
	}
	else if(eNo>=agac->No){
		agac->right=insertNewUser(agac->right,eNo,Ad,Soyad);
	}
	return agac;
}
void printInOrder(tree *agac){
	if(agac == NULL)
	    return;
	printInOrder(agac->left);
	printf("%d %s %s\n",agac->No,agac->Ad,agac->Soyad);
	printInOrder(agac->right);
}

void contains(tree *agac,int aNo){
	if(agac==NULL){
	    printf("Eleman agacta yok");
    }
	else if(agac->No==aNo){
		printf("Karsilatirilan elemanlar %d ve %d 'dir\n ",agac->No,aNo);
        printf ("Adi:%s Ve Soyadi:%s\n",agac->Ad,agac->Soyad);
    }
    
	else if(agac->No>aNo){
		printf("Karsilatirilan elemanlar %d ve %d 'dir\n ",agac->No,aNo);
		contains(agac->left,aNo);
    }
	else if(agac->No<aNo){
		printf("Karsilatirilan elemanlar %d ve %d 'dir\n ",agac->No,aNo);
		contains(agac->right,aNo);
    }
}

void Friends(tree *agac,int aNo){
  int i = 0 ;
  while(Roam(agac,aNo)->arkadaslar[i] != 0){
    contains(agac,Roam(agac,aNo)->arkadaslar[i]);
    i++;
  }
}

int size(tree *agac,int sayi){
	if(agac == NULL)
	    return sayi;
    sayi=size(agac->left,sayi);
	sayi=sayi +1;
	sayi=size(agac->right,sayi);
	return sayi;
}
tree * max(tree *agac){
	while(agac->right!=NULL)
	    agac=agac->right;
	return agac;
}
tree * min(tree *agac){
	while(agac->left!=NULL)
	    agac=agac->left;
	return agac;
}

tree * aradegersag(tree *agac,tree *temp2){
	while(agac->left!=NULL){
        temp2=agac;	
	    agac=agac->left;
    }
    return temp2;
}
tree * aradegersol(tree *agac,tree *temp2){
	while(agac->right!=NULL){
        temp2=agac;	
	    agac=agac->right;
    }
    return temp2;
}
tree * deleteUser(tree *agac,int sNo){
	tree *temp ,*temp2;
	
	if(agac == NULL)
	    return NULL;
	if(agac->No == sNo){
		if(agac->left == NULL && agac->right == NULL)
	        return NULL;
	    if(agac->right!=NULL){
	    	if(agac->right->left==NULL){
				temp=min(agac->right);
			    temp->left=agac->left;
			    return temp;
		    }
	    	else{
			    temp = min(agac->right);
	    	    temp2=aradegersag(agac->right,temp2);
	    	    temp2->left=temp->right;
	    	    temp->left=agac->left;
	    	    temp->right=agac->right;
	    	    return temp;
	        }
		}
		else if(agac->left!=NULL){
		    if(agac->left->right==NULL){
				temp=max(agac->left);
			    temp->right=agac->right;
		        return temp;
			}
		    else{
				temp = max(agac->left);
		        temp2=aradegersol(agac->left,temp2);
		        temp2->right = temp->left;
	    	    temp->left=agac->left;
	    	    temp->right=agac->right;
		        return temp;
            }
		}
	}
	if(agac->No<sNo){
		agac->right = deleteUser(agac->right,sNo);
		return agac;
	}
	agac->left = deleteUser(agac->left,sNo);
	return agac;
}

tree * Roam(tree *agac ,int aNo){
  if(agac == NULL)
    return NULL;
  else if(agac->No == aNo)
    return agac;
  else if(agac->No < aNo)
    return Roam(agac->right,aNo);
  else
    return Roam(agac->left,aNo);
}

void printNext(tree *agac , int aNo){
  printInOrder(Roam(agac,aNo)->left);
  printInOrder(Roam(agac,aNo)->right);
}

void printGreater(tree *agac ,int aNo){
    if(agac == NULL)
    return;
	
	else if(agac->No == aNo){
    	 printInOrder(agac->right);
    }
    else if(agac->No < aNo){
    printGreater(agac->right,aNo);
    }
    else{
       printf("%d %s %s \n",agac->No,agac->Ad,agac->Soyad);
       printInOrder(agac->right);
       printGreater(agac->left,aNo);
	}
}

tree * readFromFile(tree *agac){
    FILE *infile;
    int i,j,No;
    char Ad[100];
    char Soyad[100];
    infile = fopen("infile.txt","r");
    if(!infile){
        printf(" Dosya bulunamadi \n");
        return;
    }
    while(!feof(infile)){	
	    fscanf(infile,"%d%s%s",&No,Ad,Soyad);
        agac=insertNewUser(agac,No,Ad,Soyad);
    }
    fclose(infile);
    return agac;
}

