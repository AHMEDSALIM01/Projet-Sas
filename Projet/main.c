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
 	printf("*****le compte a ete cree avec succee*****\n");
 	}

 void insert_ncmp(){
 	FILE *FI;
 	FI=fopen("gestion_bancaire.txt","a");
 	char CIN[10];
 	int j,n;
 	printf("combien de compte que vous devrez creer :");
 	scanf("%d",&n);
 	while(n==0){printf("veuillez entrer le nombre des fois different a 0 :");
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
 	printf("*****le compte a ete cree avec succee*****\n");
 	}

 void retrait(){

 	FILE *FI;
 	FI=fopen("gestion_bancaire.txt","a");
 	char CIN[10];
 	long a;
 	printf("entrer le CIN :");
 	scanf("%s",&CIN);
 	if(search(CIN)!=0){
 		printf ("le CIN %s n'existe pas merci d'introduire un compte\n",CIN);
 		return;}
 	else{
 	i.anc_montant=i.nov_montant;
 	printf("donner le montant de retrait (DH)= ");
 	scanf("%ld",&a);
 	i.nov_montant-=a;
 	printf("votre ancien montant (DH)= %ld\n",i.anc_montant);
 	fprintf(FI,"%s |%s |%s |%ld |%ld \n",i.CIN,i.Prenom,i.Nom,i.anc_montant,i.nov_montant);
 	printf("votre noveau montant (DH)= %ld\n",i.nov_montant);
 	printf("\n");
 	fflush(stdin);
 	fclose(FI);
 	printf("*****votre operation a ete effectuer avec succee*****\n");
 	}

 }

 void depot(){

 	FILE *FI;
 	FI=fopen("gestion_bancaire.txt","a");
 	char CIN[10];
 	long a;
 	printf("entrer le CIN :");
 	scanf("%s",&CIN);
 	if(search(CIN)!=0){
 		printf ("le CIN %s n'existe pas merci d'introduire un compte\n",CIN);
 		return;}
 	else{
 	i.anc_montant=i.nov_montant;
 	printf("donner le montant de depot (DH)= ");
 	scanf("%ld",&a);
 	i.nov_montant+=a;
 	printf("votre ancien montant (DH)= %ld\n",i.anc_montant);
 	fprintf(FI,"%s |%s |%s |%ld |%ld \n",i.CIN,i.Prenom,i.Nom,i.anc_montant,i.nov_montant);
 	printf("votre votre noveau montant (DH)= %ld\n",i.nov_montant);
 	printf("\n");
 	fflush(stdin);
 	fclose(FI);
 	printf("*****votre operation a ete effectuer avec succee*****\n");
 	}
	}

int main(){
	int c,b;
	retour:
	printf("**********Meunu Principal********** \n");
	printf("chosire: \n");
	printf("1: introduire un compte\n");
	printf("2: introduire plusieur comptes a la fois\n");
	printf("3: Operations \n");
	printf("4: Quitter \n");
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

	default:printf("***************BYE***************");
	}

	return 0;
	}
