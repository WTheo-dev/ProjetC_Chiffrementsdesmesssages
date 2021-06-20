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
#include "saisieDuTxt.h"
#include "cesard.h"
#include "vigenere.h"
#define tailleMaxCode 1000
#define tailleMaxClef 100







/* Fonction main permetant le choix du type de cryptographie ainsi que le fait de choisir s'il l'on veut decoder ou coder notre message */
int main(void) {

    int tailleCode = tailleMaxCode, valDecallage[30], tailleClef = tailleMaxClef;
    char choix[5], choixCriptage[5];
    char code[tailleCode], clef[tailleClef];
    char valide[] = "01";
    printf("Entre ton msg codé\n");
    /*Saisie du code*/
    saisieLigne(code, sizeof(code));

    printf("Entre 0 si tu veux utiliser le code vigenere ou 1 pour le code cesard\n");
    saisieLigne(choixCriptage, sizeof(choixCriptage));
    /*Choix entre le codage cesard ou vigenere*/
    if (choixCriptage[0] == valide[1]) {

        printf("Entre 0 si tu veux dechiffrer un code ou 1 pour le chiffrer\n");
        saisieLigne(choix, sizeof(choix));

        while (choix[0] != valide[0] && choix[0] != valide[1]) {

            printf("Tu t'es trompé entre 0 si tu veux dechiffrer un code ou 1 pour le chiffrer\n");
            printf(" Voici la valeur de choix %c\n", choix[0]);
            saisieLigne(choix, sizeof(choix));

        }


        if (choix[0] == valide[0]) {
            Dechiffragecesard(code);
            printf("Voici les codes dechiffrés");
        }
        else if (choix[0] == valide[1]) {
            /*Saisie du decallage*/
            printf("Choisis la ton decallage entre 1 et 25\n");

            scanf("%d", valDecallage);
            printf("Valeur de valDecallage %d\n", valDecallage);
            ChiffrementCesard(code, valDecallage);
        }
    }
    else if (choixCriptage[0] == valide[0]) {
        /*Saisie de la clef*/
        printf("Choisis la clef pour vigenere\n");
        saisieLigne(clef, sizeof(clef));
        VigenereCryp(code, clef);
    }
    printf("FIN");
    return 0;
}


