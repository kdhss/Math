#include <stdio.h>
#include <stdlib.h>     //pour les nombres aleatoires
#include <string.h>
#include "jeux.h"

void addition(int *point){
        int nb1 = rand() % 101;
        int nb2 = rand() % 101;
        int reponse;
        int compt = 0;
        static char res[20];
        printf("%d+%d\n",nb1,nb2);
        printf("Entrez un resultat\n");
        scanf("%d",&reponse);
        printf("Vous avez entrez %d\n",reponse);
        while (compt < 2){
            compt = compt + 1 ;
            if ((nb1 + nb2) == reponse){
                if ( compt == 1) {
                    *point = *point + 10 ;
                }else if (compt == 2) {
                    *point = *point + 5;
                } else {
                    *point = *point + 1 ;
                }
                printf("Bravo !\n");
                break;
            }else {
                printf("C'est faux, entrez un autre resultat\n");
                scanf("%d",&reponse); 
                printf("Pas Bravo !\n");
        }
    }
    if (compt >= 2){
            printf("Nombre d'essai d'épassé!\n");
            printf("La bonne réponse était : %d .\n", nb1+nb2);
        } 
}

void multiplication(int *point){
    int nb1 = rand() % 10;
    int nb2 = rand() % 10;
    int reponse;
    int compt = 0;
    static char res[20] ;
    printf("%d*%d\n",nb1,nb2);
    printf("Entrez un resultat\n");
    scanf("%d",&reponse);
    printf("Vous avez entrez %d\n",reponse);
    while (compt < 2){
        compt = compt + 1;
        if ((nb1 * nb2) == reponse){
            if ( compt == 1) {
                    *point = *point + 10 ;
                }else if (compt == 2) {
                    *point = *point + 5;
                } else {
                    *point = *point + 1 ;
                }
            printf("Bravo !\n");
            break;
        } else {
            printf("C'est faux, entrez un autre resultat\n");
            scanf("%d",&reponse);
       }
    }
    if (compt >= 2){
            printf("Pas Bravo !\n");
            printf("Nombre d'essai d'épassé!\n");
            printf("La bonne réponse était : %d.\n", nb1*nb2);
        } 
}

void soustraction(int *point){
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
    while (compt < 2){
        compt = compt + 1;
        if ((nb1-nb2) == reponse){
            if ( compt == 1) {
                        *point = *point + 10 ;
                    }else if (compt == 2) {
                        *point = *point + 5;
                    } else {
                        *point = *point + 1 ;
                    }
            printf("Bravo !\n");
            break;
        } else{
            printf("C'est faux, entrez un autre resultat\n");
            scanf("%d",&reponse);
        }
    }
    if (compt >= 2){
            printf("Pas Bravo !\n");
            printf("Nombre d'essai d'épassé!\n");
            printf("La bonne réponse était : %d.\n", nb1-nb2);
        } 
        
    }

void Divisions(int *point) {
    int a, b;
    int dividende, diviseur;
    int reponse_quotient, reponse_reste;
    int compt = 0;

    a = rand() % 100 + 1;
    b = rand() % 100 + 1;
    int p = 0;
    if (a > b) {
        dividende = a;
        diviseur = b;
    } else {
        dividende = b;
        diviseur = a;
    }
    printf("Calcule la division suivante :\n");
    printf("%d ÷ %d\n", dividende, diviseur);

    int bon_quotient = dividende / diviseur;
    int bon_reste = dividende % diviseur;

    printf("Donne le quotient : ");
    scanf("%d", &reponse_quotient);
    printf("Donne le reste : ");
    scanf("%d", &reponse_reste);

    while (compt < 2){
        compt = compt + 1;
        if ((reponse_quotient == bon_quotient) && (reponse_reste == bon_reste)) {
            if ( compt == 1) {
                        *point = *point + 10 ;
                    }else if (compt == 2) {
                        *point = *point + 5;
                    } else {
                        *point = *point + 1 ;
                    }
            printf("Bravo ! Bonne réponse\n");
            break;
        } else {
            printf("Faux, réessayez!\n");
            printf("Donne le quotient : ");
            scanf("%d", &reponse_quotient);
            printf("Donne le reste : ");
            scanf("%d", &reponse_reste);
        }

        if (compt >= 2){
            printf("Nombre d'essai d'épassé");
            printf("La bonne réponse était : quotient = %d, reste = %d\n", bon_quotient, bon_reste);
        }  
    }
}    

void tablesM(int *point){
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

void Nbr_mystere(int *point){
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
    if (reponse != mystere) {
         printf("Perdue! \n");
    }
}

void operations(int *point){
    int cible = 17;
    int essais = 3;

    printf("=== Jeu du calcul ===\n");
    printf("Objectif: %d\n", cible);
    printf("Vous avez 3 essais.\n");

    while(essais > 0) {
        int a, b, c;
        char op1, op2;

        printf("\nEntrez votre calcul (ex: 2 + 5 * 7): ");
        scanf("%d %c %d %c %d", &a, &op1, &b, &op2, &c);

        int r1, resultat;

        // premier calcul
        switch(op1) {
            case '+': 
            r1 = a + b; 
            break;
            case '-': 
            r1 = a - b; 
            break;
            case '*': 
            r1 = a * b; 
            break;
            case '/': 
            r1 = b != 0 ? a / b : 0; 
            break;
            default: 
            r1 = 0;
        }

        // deuxième calcul
        switch(op2) {
            case '+': 
            resultat = r1 + c; 
            break;
            case '-': 
            resultat = r1 - c; 
            break;
            case '*': 
            resultat = r1 * c; 
            break;
            case '/': 
            resultat = c != 0 ? r1 / c : 0; 
            break;
            default: 
            resultat = 0;
        }

        if(resultat == cible) {
            if (essais == 3){
                *point = *point + 10 ;
            } else if (essais == 2){
                *point = *point + 5;
            }else if (essais == 1){
                *point = *point + 1 ;
            } 
            printf("Bravo ! Vous avez trouvé !\n");
            return; // fin du jeu
        } else {
            essais = essais - 1;
            printf("Faux ! Résultat = %d\n", resultat);
            printf("Essais restants: %d\n", essais);
        }
    }
     printf("\nPerdu ! Plus d'essais.\n");
}

