/******************************************************************************
*  ASR => M2101                                                               *
*******************************************************************************
*                                                                             *
*  N° de Sujet :3                                                              *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Intitulé :Chiffrement de messages                                                                 *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom-prénom1 : WAZYDRAG Theo                                                             *
*                                                                             *
*  Nom-prénom2 : GINESTE Hugo                                                             *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom du fichier : main.c                                                          *
*                                                                             *
******************************************************************************/


#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "cesard.h"

/*Fonction de dechiffrage d'un code cesard*/
void Dechiffragecesard(char* code) {

    int c, i, j, f;
    int taille;
    /* Affectation de d'un double alphabet pour eviter un stack overflow en lors des decallages */
    char ChaineLettre[] = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
    char ChaineTempo[tailleMaxCode];

    taille = strlen(code);
    c = 0;
    for (i=0;i<= taille ; i++){
        if (code[i]>= 65 && code[i]<= 90 ){
            code[i]= tolower(code[i]);
      }
    }
    /* La boucle for ici permet de faire tout les callages de toutes les lettres de l'alphabet*/
    for (i = 0; i <= 25; i++) {
        c = 0;
        j = 0;
        /* Remise a 0 de notre chaine contenant notre code entre chaque decallage pour evité des problemes de taille*/
        memset(ChaineTempo, 0, sizeof(ChaineTempo));
        /* Boucle while nous permettant de passer toutes les lettres de notres code que l'on souhaite decrypter/crypter */
        while (c <= taille - 1) {
            /* Verification du char espace pour eviter un probleme de modification de ce dernier*/
            if ((code[c] >= 33 && code[c] <= 47) || (code[c] >= 58 && code[c] <= 64 ) || (code[c] >= 91 && code[c] <= 96 ) || code[c]==' ') {
                ChaineTempo[c] = ' ';
                /* On incremente de 1 pour eviter d'avoir une boucle infinie*/
                c++;
            }
            else {
                /* Comparaison d'une lettre de notre code jusqu'a qu'elle corresponde a l'alphabet*/
                if (code[c] == ChaineLettre[j]) {
                    /* Creation du decallage et affectation de la valeur decalé a notre chaine de caractere */
                    f = j + i;

                    ChaineTempo[c] = ChaineLettre[f];
                    c++;
                    j = 0;
                }
                else {
                    j++;
                }
            }
        }
        printf(" Le mot est %s avec un decallage de %d\n", ChaineTempo, i);
    }
}

/* Fonction permetant le chiffrement avec un decallage donné*/
void ChiffrementCesard(char* code, int* decallage) {
    int c, i, j, f;
    int taille;
    /* Affectation de d'un double alphabet pour eviter un stack overflow en lors des decallages */
    char ChaineLettre[] = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
    char ChaineTempo[tailleMaxCode];

    taille = strlen(code);

    c = 0;
    j = 0;
    for (i=0;i<= taille ; i++){
        if (code[i]>= 65 && code[i]<= 90 ){
            code[i]= tolower(code[i]);
      }
    }
    /* Verification que le decalage est bien entre 0 et 26 si ce n'est pas le cas on trouve le decallage a l'aide d'un modulo*/
    while (decallage[0] > 26 || decallage[0] <= 0) {
        decallage[0] %= 26;
    }
    /* Boucle while nous permettant de passer toutes les lettres de notres code que l'on souhaite decrypter/crypter */
    while (c <= taille - 1) {
        /* Verification du char espace pour eviter un probleme de modification de ce dernier*/
        if ((code[c] >= 33 && code[c] <= 47) || (code[c] >= 58 && code[c] <= 64 ) || (code[c] >= 91 && code[c] <= 96 ) || code[c]==' ') {
            ChaineTempo[c] = ' ';

            c++;
        }
        else {
            if (code[c] == ChaineLettre[j]) {

                /* Affectation de la valeur decallé a notre chaine de caractere*/
                ChaineTempo[c] = ChaineLettre[j + decallage[0]];
                c++;
                j = 0;
            }
            else {
                j++;
            }
        }
    }
    printf("Voici le mot %s chiffre avec un decallage de %d = %s\n", code, decallage[0], ChaineTempo);
}