#include <stdio.h>
#include <time.h>   
#include <string.h>
#include <locale.h>   //pour les accents  (setlocale)
#include <windows.h>   //aussi pour les accents (setConsoleOutputCP)
#include "jeux.h"
#include "affichage.h"
#include "scores.h"


int main() {
    #ifdef _WIN32
    SetConsoleOutputCP(65001);
    #endif
    setlocale(LC_ALL, "fr_FR.UTF-8");
    
    srand(time(NULL));

    Score s ;
    printf("Quel est ton nom?\n");
    scanf("%s", s.nom);
    int point = chargerDernierScore(s.nom);
    printf("Bonjour! Ton score actuel est de %d .\n", point);
    time_t t = time(NULL);    //on récupère le temps de l'ordinateur en seconde(donc un grand nombre)
    struct tm tm = *localtime(&t);          //on transforme ce même temps en un truc plus clair qu'on range dans la structure tm
    sprintf(s.date, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

    int reponse ; 
    
    affichage();
    printf("Quel est votre choix?\n");
    scanf("%d", &reponse);

    while (reponse != 0) {
        
    switch(reponse) {
        case 1 : printf("Addition \n") ;
                 addition(&point);
                 printf("Vous avez maintenant %d point(s) \n", point);
                 break ; 
        case 2 : printf("Soustraction \n");
                 soustraction(&point);
                 printf("Vous avez maintenant %d point(s) \n", point);
                 break ; 
        case 3 : printf("Multiplication \n") ;
                 multiplication(&point);
                 printf("Vous avez maintenant %d point(s) \n", point);
                 break ;
        case 4 : printf("Tables des multiplications \n");
                 tablesM(&point);
                 printf("Vous avez maintenant %d point(s) \n", point);
                 break ; 
        case 5 : printf("Divisions \n");
                Divisions(&point);
                 printf("Vous avez maintenant %d point(s) \n", point);
                 break ;
        case 6 : printf("Nombre mystère \n");
                 Nbr_mystere(&point);
                 printf("Vous avez maintenant %d point(s) \n", point);
                 break ;
        case 7 : printf("Jeux des opérations \n");
                 operations(&point);
                 printf("Vous avez maintenant %d point(s) \n", point);
                 break ;
    }
    affichage();
    printf("Quel est votre choix?\n");
    scanf("%d", &reponse);
    } 

    s.point = point ;
    enregistrerScore(s);
    printf("Merci de votre visite.\n");
    printf("Vous avez %d point(s) enregistrés\n", s.point);

    return 0;

}