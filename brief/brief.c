#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct {
    char CIN[30];
    char NOM[20];
    char prenom[20];
    double Montant;
}infoclients ;


infoclients info[100];
int n = 0;

void menu ();
void ajoutercompte(){
    printf("CIN : ");
    scanf("%s",info[n].CIN);
    printf("Nom : ");
    scanf("%s",info[n].NOM);
    printf("Prenom : ");
    scanf("%s",info[n].prenom);
    printf("Montant : ");
    scanf("%lf",&info[n].Montant); 

    printf("%s  ",info[n].CIN);
    printf("%s  ",info[n].NOM);
    printf("%s  ",info[n].prenom);
    printf("%lf  ",info[n].Montant);
    n++;
     menu();
     
     }
     
void ajouterpluscompte(){
        int i,nombre;
       printf("combien voulez-vous enregistrer des clients ?");
       scanf("%d",&nombre);
       for(i=0;i<nombre;i++){
       printf("CIN \n");
       scanf("%s",info[n].CIN);
       printf("Nom \n");
       scanf("%s",info[n].NOM);
       printf("Prenom \n");
       scanf("%s",info[n].prenom);
       printf("Montant \n");
       scanf("%lf",&info[n].Montant);
       n++;  
       }
       system("cls");                  
      menu() ;   
}
            
int rechercheparcin(){
    char cin[30] ;
    printf("entrer le cin :");
    scanf("%s",cin);
    for(int i=0; i<n; i++){
        if(strcmp(info[i].CIN,cin)==0)
        
    return i ;
    
    }
}void retrait(){
        float Montant ;
        int i = rechercheparcin();
        printf("\n %s %s %s %f \n",info [i].CIN,info[i].NOM,info[i].prenom,info[i].Montant);
        printf(" donner le Mantant pour retrait :");
        scanf("%f",&Montant);
        if(Montant > info[i].Montant){
            printf("impossible pour retrait !!!");
        }
        else{
            info[i].Montant = info[i].Montant - Montant;
            printf("\n%s %s %s %f \n",info[i].CIN,info[i].NOM,info[i].prenom,info[i].Montant);}
        }
    
void depot(){
        float Montant ;
        int i = rechercheparcin();
        printf("\n %s %s %s %f \n",info [i].CIN,info[i].NOM,info[i].prenom,info[i].Montant);
        printf(" donner le Mantant pour retrait :");
        scanf("%f",&Montant);
        
            info[i].Montant = info[i].Montant + Montant;
            printf("\n %s %s %s \n",info[i].CIN,info[i].NOM,info[i].prenom,info[i].Montant);
    }


void operation(){
    int choix;
    system("cls");
    printf("__________________________________________________\n");
    printf("\t<<<<<<<<<< les operations >>>>>>>>>> \n\n");
    printf("\t  __1__ retrait____: \n\n");
    printf("\t __2___depot____:\n\n");
    printf("___________________________________________________\n");
    printf("\t entrer votre choix :");
    scanf("%d",&choix);

    switch (choix)
    {
    case 1 :
    retrait();
     break;
    case 2 :
    depot();
    break;
    default:
       printf("^^^^erreur de saisi^^^^  ");
        break;
    }
}
void affichage(){
	printf("affichez les comptes\n");
	for(int i=0 ; i<n ; i++ ){
		printf(".................................. \n");
		printf("CIN  :%s\n",info[i].CIN);
		printf("Nom  :%s\n",info[i].NOM);
		printf("Prenom :%s\n",info[i].prenom); 
		printf("Montant :%f\n",info[i].Montant);
		printf("...................................\n");
    }
   }

void menu (){
            int choix;
        printf("                                                 \n");
        printf("\t\t\t\t...............BANQUE....................\n\n\n");
        printf("\t\t\t\t  **************Bienvenue**************\n\n");
        printf("\t\t\t\t\t***********MENU*******\n\n");
        printf("\t\t\t\t.........................................\n\n");
        printf("                                                  \n");
        printf("\t\t\t\tchoisissez le nombre de votre choix\n\n");
        
    do{
        printf("1------>introduire un compte bancaire\n");
        printf("2------>introduire plusieurs ncompte bancaire\n");
        printf("3------>operation\n");
        printf("4------>Affichage \n");
        printf("5------>fidelisation \n") ;
        printf("6------> quitter l'application\n");
        scanf("%d",&choix);
        system("cls");
    switch(choix)
    {
        case 1 :
       ajoutercompte();
        break;
        case 2 :
        ajouterpluscompte();
        break;
        case 3 :
        operation();
        break;
        case 4 :
        affichage();
        break ;
        case 5 :
        printf("fidelisation "); 
        break ;
        case 6 :
        exit(0);
        system("cls");
        
        break ; 
        default :
        printf("verifier votre choix ");
        break;
    
        
    }
}while(choix<1 || choix>6);

}
int main ()
{
    menu();
   
return 0 ;
}