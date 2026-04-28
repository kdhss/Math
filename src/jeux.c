#include <stdio.h>
#include <stdlib.h>     //pour les nombres aleatoires
#include <string.h>
#include "jeux.h"

void addition(int *point){
        int nb1 = rand() % 101;
        int nb2 = rand() % 101;
        int reponse;
        int compt = 0;
       
        while (compt < 3){
            compt = compt + 1 ;
            printf("%d+%d\n",nb1,nb2);
            printf("Entrez un resultat\n");
            scanf("%d",&reponse);
            printf("Vous avez entrez %d\n",reponse);
            if ((nb1 + nb2) == reponse){
                if ( compt == 1) {
                    *point = *point + 10 ;
                }else if (compt == 2) {
                    *point = *point + 5;
                } else {
                    *point = *point + 1 ;
                }
                printf("Bravo !\n");
                return;
            }else {
                printf("C'est faux!\n");
        }
    }
    if ((nb1 + nb2) != reponse) {
            printf("Pas Bravo !\n");
            printf("Nombre d'essai d'épassé!\n");
            printf("La bonne réponse était : %d .\n", nb1+nb2);
        } 
}

void multiplication(int *point){
    int nb1 = rand() % 10;
    int nb2 = rand() % 10;
    int reponse;
    int compt = 0;
    
    while (compt < 3){
        compt = compt + 1;
        printf("%d*%d\n",nb1,nb2);
        printf("Entrez un resultat\n");
        scanf("%d",&reponse);
        printf("Vous avez entrez %d\n",reponse);
        if ((nb1 * nb2) == reponse){
            if ( compt == 1) {
                    *point = *point + 10 ;
                }else if (compt == 2) {
                    *point = *point + 5;
                } else {
                    *point = *point + 1 ;
                }
            printf("Bravo !\n");
            return;
        } else {
            printf("C'est faux!\n");
       }
    }
    if ((nb1 * nb2) != reponse){
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
    if (nb1<nb2){
        nb = nb2;
        nb2 = nb1;
        nb1 = nb;  
        }
    
    while (compt < 3){
        compt = compt + 1;
        printf("%d-%d\n",nb1,nb2);
        printf("Entrez un resultat\n");
        scanf("%d",&reponse);
        printf("Vous avez entrez %d\n",reponse);
        if ((nb1-nb2) == reponse){
            if ( compt == 1) {
                        *point = *point + 10 ;
                    }else if (compt == 2) {
                        *point = *point + 5;
                    } else {
                        *point = *point + 1 ;
                    }
            printf("Bravo !\n");
            return;
        } else{
            printf("C'est faux!\n");
        }
    }
    if ((nb1 - nb2) != reponse){
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


    while (compt < 3){
        compt = compt + 1;
        printf("Donne le quotient : ");
        scanf("%d", &reponse_quotient);
        printf("Donne le reste : ");
        scanf("%d", &reponse_reste);
        if ((reponse_quotient == bon_quotient) && (reponse_reste == bon_reste)) {
            if ( compt == 1) {
                        *point = *point + 10 ;
                    }else if (compt == 2) {
                        *point = *point + 5;
                    } else {
                        *point = *point + 1 ;
                    }
            printf("Bravo ! Bonne réponse\n");
            return;
        } else {
            printf("Faux!\n");
        }
        }  
         if ((bon_quotient != reponse_quotient)&&(bon_reste != reponse_reste)){
            printf("Nombre d'essai d'épassé\n");
            printf("La bonne réponse était : quotient = %d, reste = %d\n", bon_quotient, bon_reste);
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
    int a, b, c, cible;
    int essais = 3;
    char ops[] = {'+', '*'};
    
    a = (rand() % 10) + 1;
    b = (rand() % 10) + 1;
    c = (rand() % 10) + 1;

    char secret_op1 = ops[rand() % 2];
    char secret_op2 = ops[rand() % 2];

    int r1;
    if (secret_op1 == '+') {
        r1= a + b ;
    } else { 
        r1=(a * b);
     }
    if (secret_op2 == '+') {
        cible= r1 + c ;
     } else { 
        cible = (r1 * c);
     }

    printf("\n============================");
    printf("\n NOUVEL EXERCICE ");
    printf("\n============================");
    printf("\nChiffres a utiliser : %d, %d et %d avec deux opérateurs comportant + ou * \n", a, b, c);
    printf("\nObjectif Cible : %d", cible);
    printf("\n============================\n");

    while(essais > 0) {
        int ua, ub, uc, ur1, resultat;
        char uop1, uop2;


        printf("\nEntrez votre calcul (ex: %d + %d * %d) : ", a, b, c);
        scanf("%d %c %d %c %d", &ua, &uop1, &ub, &uop2, &uc);
        
        if (uop1 == '+'){
             ur1 = ua + ub;
            }else {
                ur1 = ua * ub;
            }

        if (uop2 == '+') { 
            resultat = ur1 + uc;
        }else { 
            resultat = ur1 * uc;
        }
        if (resultat == cible){
        if ( essais == 3) {
                    *point = *point + 10 ;
                }else if (essais == 2) {
                    *point = *point + 5;
                } else {
                    *point = *point + 1 ;
                }
                printf("Bravo ! Vous avez trouve , il vous restez %d essai(s)\n", essais);
                return;
            }
            else {
                printf("C'est Faux!\n");
                essais = essais - 1;
            }
        
        }
        printf("La bonne réponse était %d %c %d %c %d \n", a,secret_op1, b, secret_op2, c );
    }
