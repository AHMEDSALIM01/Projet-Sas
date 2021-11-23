#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct insertc
 {
 	char CIN[10];
 	char Prenom[20];
 	char Nom[20];
 	long anc_montant;
 	long nov_montant;
 	};
 struct insertc i;

 int search(char CINCH[]){
 	FILE *FI;
 	strupr(CINCH);
 	FI=fopen("gestion_bancaire.txt","r");
 	do
 	{
 		fscanf(FI,"%s |%s |%s |%ld |%ld \n",&i.CIN,&i.Prenom,&i.Nom,&i.anc_montant,&i.nov_montant);

 		if(strcmp(i.CIN,CINCH)==0)
 	    	{fclose(FI);
 			return 0;}
 	}while(!feof(FI));
 		fclose(FI);
 		return 1;
 	}

 void insert_cmp(){
 	FILE *FI;
 	FI=fopen("gestion_bancaire.txt","a");
 	char CIN[10];
 	strupr(CIN);
 	printf("entrer le CIN :");
 	scanf("%s",&CIN);
 	while(search(CIN)==0){
 		printf("ce CIN: %s existe deja\n",CIN);
 		printf("entrer le CIN :");
 		scanf("%s",&CIN);
 		}
 	strcpy(i.CIN,CIN);
 	printf("Prenom: ");scanf("%s",&i.Prenom);
 	printf("Nom: ");scanf("%s",&i.Nom);
 	printf("nov_Montant: ");scanf("%ld",&i.nov_montant);
 	fprintf(FI,"%s |%s |%s |%ld |%ld \n",i.CIN,i.Prenom,i.Nom,i.anc_montant,i.nov_montant);
 	fflush(stdin);
 	fclose(FI);
 	printf("*****le compte a ete creer avec succees*****\n");
 	}

 void insert_ncmp(){
 	FILE *FI;
 	FI=fopen("gestion_bancaire.txt","a");
 	char CIN[10];
 	int j,n;
 	printf("combien de compte que vous devrez creer :");
 	scanf("%d",&n);
 	while(n>0){printf("veuillez entrer le nombre des fois different a 0 :");
 		scanf("%d",&n);
 		}
 	for(j=0;j<n;j++){
 	printf("entrer le CIN :");
 	scanf("%s",&CIN);
 	while(search(CIN)==0){
 		printf("ce CIN: %s existe deja\n",CIN);
 		printf("entrer le CIN :");
 		scanf("%s",&CIN);
 		fclose(FI);
 		}
 	strcpy(i.CIN,CIN);
 	printf("Prenom: ");scanf("%s",&i.Prenom);
 	printf("Nom: ");scanf("%s",&i.Nom);
 	printf("nov_Montant: ");scanf("%ld",&i.nov_montant);
 	fprintf(FI,"%s |%s |%s |%ld |%ld \n",i.CIN,i.Prenom,i.Nom,i.anc_montant,i.nov_montant);
 	fflush(stdin);}
 	fclose(FI);
 	printf("*****leS compte a etes creer avec succees*****\n");
 	}

 void retrait(){

 	FILE *FI,*tempo;
 	FI=fopen("gestion_bancaire.txt","r");
 	tempo=fopen("tmp.txt","w+");
 	char CIN[10];
 	strupr(CIN);
 	long a;
 	printf("entrer le CIN :");
 	scanf("%s",&CIN);
 	if(search(CIN)==1){
        printf("le CIN n'existe pas merci d'introduire un compte\n");
        return;
    }
 	do{
     fscanf(FI,"%s |%s |%s |%ld |%ld \n",i.CIN,i.Prenom,i.Nom,&i.anc_montant,&i.nov_montant);
 	if(strcmp(CIN,i.CIN)==0){
 	i.anc_montant=i.nov_montant;
 	strcpy(i.CIN,CIN);
 	printf("Prenom: ");scanf("%s",&i.Prenom);
 	printf("Nom: ");scanf("%s",&i.Nom);
 	printf("donner le montant de retrait (DH)= ");
 	scanf("%ld",&a);
 	while(a<=0){
        printf("donner le montant exacte :\n");
        printf("donner le montant de retrait (DH)= ");
        scanf("%ld",&a);
 	}
 	i.nov_montant-=a;
 	printf("votre ancien montant (DH)= %ld\n",i.anc_montant);
 	printf("votre noveau montant (DH)= %ld\n",i.nov_montant);
 	printf("\n");
 	}
 	fprintf(tempo,"%s |%s |%s |%ld |%ld \n",i.CIN,i.Prenom,i.Nom,i.anc_montant,i.nov_montant);
 	}while(!feof(FI));
 	fflush(stdin);
 	fclose(FI);
 	fclose(tempo);
 	remove("gestion_bancaire.txt");
 	rename("tmp.txt","gestion_bancaire.txt");
 	printf("*****votre operation a ete effectuer avec succee*****\n");
 }





 void depot(){

 	FILE *FI,*tempo;
 	FI=fopen("gestion_bancaire.txt","r");
 	tempo=fopen("tmp.txt","w+");
 	char CIN[10];
 	strupr(CIN);
 	long a;
 	printf("entrer le CIN :");
 	scanf("%s",&CIN);
 	if(search(CIN)==1){
        printf("le compte de ce CIN n'existe pas merci d'introduire un compte\n");
        return;
    }
 	do{
     fscanf(FI,"%s |%s |%s |%ld |%ld \n",i.CIN,i.Prenom,i.Nom,&i.anc_montant,&i.nov_montant);
 	if(strcmp(CIN,i.CIN)==0){
 	i.anc_montant=i.nov_montant;
 	strcpy(i.CIN,CIN);
 	printf("Prenom: ");scanf("%s",&i.Prenom);
 	printf("Nom: ");scanf("%s",&i.Nom);
 	printf("donner le montant de retrait (DH)= ");
 	scanf("%ld",&a);
 	while(a<=0){
        printf("donner le montant exacte :\n");
        printf("donner le montant de retrait (DH)= ");
        scanf("%ld",&a);
 	}
 	i.nov_montant+=a;
 	printf("votre ancien montant (DH)= %ld\n",i.anc_montant);
 	printf("votre noveau montant (DH)= %ld\n",i.nov_montant);
 	printf("\n");
 	}
 	fprintf(tempo,"%s |%s |%s |%ld |%ld \n",i.CIN,i.Prenom,i.Nom,i.anc_montant,i.nov_montant);
 	}while(!feof(FI));
 	fflush(stdin);
 	fclose(FI);
 	fclose(tempo);
 	remove("gestion_bancaire.txt");
 	rename("tmp.txt","gestion_bancaire.txt");
 	printf("*****votre operation a ete effectuer avec succee*****\n");
	}
void aff_rechcin(){
    FILE *FI;
    FI=fopen("gestion_bancaire.txt","r");
    char CIN[11];
    printf("donner le CIN du compte souhaitee : ");
    scanf("%s",CIN);
    if(search(CIN)==0)
    {
       printf("\t=======Liste d'information=======\n");
       do{
        fscanf(FI,"%s |%s |%s |%ld |%ld \n",i.CIN,i.Prenom,i.Nom,&i.anc_montant,&i.nov_montant);
        if(strcmp(i.CIN,CIN)==0){
        printf("CIN :");printf("%s| ",i.CIN);printf("Prenom:");printf("%s| ",i.Prenom);printf("Nom:");printf("%s| ",i.Nom);printf("Anc.Montant(DH):");printf("%ld| ",i.anc_montant);printf("Nouv.Montnant(DH):");printf("%ld\n",i.nov_montant);
        }
       }while(!feof(FI));
       fflush(stdin);
       fclose(FI);
    }
    else
    {
       printf("le compte de ce CIN n'existe pas merci d'introduire un compte\n");
    }
}

int main(){
	int c,b;
	retour:
	printf("\n\n**********Meunu Principal********** \n");
	printf("chosire: \n");
	printf("1: introduire un compte\n");
	printf("2: introduire plusieur comptes a la fois\n");
	printf("3: Operations \n");
	printf("4: Recherche par CIN\n");
	printf("5: Quitter \n");
	scanf("%d",&b);
	switch(b)
	{case 1:insert_cmp();
	goto retour;
	case 2:insert_ncmp();
	goto retour;
	case 3:
			printf("1: retrait\n");
			printf("2: Depot\n");
			printf("3: retour\n");
	  		scanf("%d",&c);
			switch(c)
			{
				case 1: retrait();
				goto retour;
				case 2: depot();
				goto retour;
			}
			goto retour;
     case 4:aff_rechcin();
     break;
	default:printf("\t\t***************BYE***************");
	}

	return 0;
	}
