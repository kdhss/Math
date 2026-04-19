#ifndef SCORES_H
#define SCORES_H

typedef struct {
    char nom[50];
    char date[20];
    int point;
} Score;

void enregistrerScore(Score s); 

int chargerDernierScore(char *nom_recherche);

#endif 