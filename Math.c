#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

void affichage() {
        printf("+-----------------------------------+\n");
        printf("|1 : Addition                       |\n");
        printf("|2 : Soustraction                   |\n");
        printf("|3 : Multiplication                 |\n");
        printf("|4 : Tables des multiplications     |\n");
        printf("|5 : Divisions                      |\n");
        printf("|6 : Nombre mystère                 |\n");
        printf("|0 : Sortir du jeu                  |\n");
        printf("+-----------------------------------+\n");
    }

const char* addition(int * point){
        int nb1 = rand() % 101;
        int nb2 = rand() % 101;
        int reponse;
        int compt = 0;
        static char res[20];
        printf("%d+%d\n",nb1,nb2);
        printf("Entrez un resultat\n");
        scanf("%d",&reponse);
        printf("Vous avez entrez %d\n",reponse);
        while (compt < 3){
            compt = compt + 1 ;
            if ((nb1 + nb2) == reponse){
                if ( compt == 1) {
                    *point = *point + 10 ;
                }else if (compt == 2) {
                    *point = *point + 5;
                } else {
                    *point = *point + 1 ;
                }
                strcpy(res,"Bravo !\n");
                break;
            }else {
                printf("C'est faux, entrez un autre resultat\n");
                scanf("%d",&reponse); 
                strcpy(res,"Pas Bravo !\n");
        }
    }
    if (strcmp(res, "Bravo")){
    return res ;
    }
}

const char* multiplication(int * point){
    int nb1 = rand() % 10;
    int nb2 = rand() % 10;
    int reponse;
    int compt = 0;
    static char res[20] ;
    printf("%d*%d\n",nb1,nb2);
    printf("Entrez un resultat\n");
    scanf("%d",&reponse);
    printf("Vous avez entrez %d\n",reponse);
    while (compt < 3){
        compt = compt + 1;
        if ((nb1 * nb2) == reponse){
            if ( compt == 1) {
                    *point = *point + 10 ;
                }else if (compt == 2) {
                    *point = *point + 5;
                } else {
                    *point = *point + 1 ;
                }
            strcpy(res,"Bravo !\n");
            break;
        } else {
            printf("C'est faux, entrez un autre resultat\n");
            scanf("%d",&reponse);
            strcpy(res,"Pas Bravo !\n");
       }
    }
        return res; 
}

const char* soustraction(int * point){
    int nb1 = rand() % 101;
    int nb2 = rand() % 101;
    int nb;
    int reponse;
    int compt = 0;
    static char res[20] ;
    if (nb1<nb2){
        nb = nb2;
        nb2 = nb1;
        nb1 = nb;  
        }
    printf("%d-%d\n",nb1,nb2);
    printf("Entrez un resultat\n");
    scanf("%d",&reponse);
    printf("Vous avez entrez %d\n",reponse);
    while (compt < 3){
        compt = compt + 1;
        if ((nb1-nb2) == reponse){
            if ( compt == 1) {
                        *point = *point + 10 ;
                    }else if (compt == 2) {
                        *point = *point + 5;
                    } else {
                        *point = *point + 1 ;
                    }
            strcpy(res,"Bravo !\n");
            break;
        } else{
            printf("C'est faux, entrez un autre resultat\n");
            scanf("%d",&reponse);
            strcpy(res,"Pas Bravo !\n");
        }
    }
            return res;
        
    }

void tablesM(int * point){
    int choix;
    int rep;
    char res[10];
    strcpy(res,"Gagné");
    int p = 1;
    printf("Entrez la table que vous souhaitez réviser\n");
    scanf("%d",&choix);
    for (int i = 1;i<=10;i++){
        printf("%d*%d=%d\n",choix,i,choix*i);
    }
    printf("A toi de jouer!");
    for (int i=1; i<= 10; i++ ) {
        printf("%d * %d=\n" , choix, i);
        scanf("%d", &rep);
        if (rep !=( i * choix)) {
            strcpy(res,"Perdu");
            p = 0;
        }
    } printf("Vous avez %s\n",res);
    *point = *point + p ;
} 

void Nbr_mystere(int * point){
    int mystere = rand() % 1000;
    int reponse ; 
    int essai = 10;
    printf("Vous devez deviner un numéro entre 0 et 999\n");
    printf("Entrez votre premier nombre, vous avez %d essais \n", essai);
    scanf("%d", &reponse);
    while (essai != 0){
        if (reponse < mystere){
            printf("Le numéro mystère est plus grand, il vous reste %d essais\n", essai);
        } else if (reponse > mystere){
            printf("Le numéro mystère est plus petit, il vous reste %d essais \n", essai);
        } else {
            printf("Bravo ! \n");
            printf("Vous avez trouvé le bon numéro, il vous restez %d essais !\n", essai);
            *point = *point + 1 ;
            break;
        }
        essai = essai - 1;
        scanf("%d", &reponse);
    }
    if (reponse != mystere){
    printf("Perdue! \n");
    }
}

int main() {
    #ifdef _WIN32
    SetConsoleOutputCP(65001);
    #endif
    setlocale(LC_ALL, "fr_FR.UTF-8"); // Ou simplement ""
    // ... reste du code
    
    srand(time(NULL));

    int reponse ; 
    int point = 0;
    
    affichage();
    printf("Quel est votre choix?\n");
    scanf("%d", &reponse);

    while (reponse != 0) {
        
    switch(reponse) {
        case 1 : printf("Addition \n") ;
                 printf(addition(&point));
                 break ; 
        case 2 : printf("Soustraction \n");
                 printf(soustraction(&point));
                 break ; 
        case 3 : printf("Multiplication \n") ;
                 printf(multiplication(&point));
                 break ;
        case 4 : printf("Tables des multiplications \n");
                 tablesM(&point);
                 break ; 
        case 5 : printf("Divisions \n");
                 break ;
        case 6 : printf("Nombre mystère \n");
                 Nbr_mystere(&point);
                 break ;
    }
    affichage();
    printf("Quel est votre choix?\n");
    scanf("%d", &reponse);


}  
    printf("merci de votre visite\n");
    printf("Vous avez %d point(s)\n", point);
    return 0;

}