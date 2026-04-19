#include <stdio.h>
#include <string.h>
#include "scores.h"

void enregistrerScore(Score s){
    FILE *f = fopen("scores.txt", "a"); // "a" = append pour ajouter à la fin du fichier pour garder les scores précédent
    if (f != NULL){              //si le fichier existe
        fprintf(f, "%s;%s;%d\n", s.nom, s.date, s.point);
        fclose(f);
    }
}

int chargerDernierScore(char *nom_recherche) {
    FILE *f = fopen("scores.txt", "r");  // ici r pour read, on lit le fichier
    if (f == NULL) {        // si le fichier n'existe pas
        return 0;
    }
    char nom[50], date[20];
    int scoreTrouve = 0;    // au cas où on le trouve pas
    int scoreLu;

    while(fscanf(f, "%[^;];%[^;];%d\n", nom, date, &scoreLu) != EOF) {    // EOF pour la fin du fichier, ici on parcours toutes les lignes
        if (strcmp(nom, nom_recherche) == 0) {
            scoreTrouve = scoreLu;
        }
    }
    fclose(f);
    return scoreTrouve;
}