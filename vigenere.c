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
#include "vigenere.h"
#include "saisieDuTxt.h"

/*Fonction vigenere permetant de crypter ou de decrypter a l'aide d'une clef fournis par l'utilisateur*/
void VigenereCryp(char* code, char* clef) {
    int valeurLettreCode[tailleMaxCode], valeurLettreClef[tailleMaxCode], valeurMsgDecode[tailleMaxCode],  i, j, c, f = 0,o;

    char alphabet[] = "abcdefghijklmnopqrstuvwxyz", Msg[strlen(code)],choix[5],valide[]="01";
    /*Affectation de la valeur de la lettre pour chaque lettre du code*/
    for (i=0;i<= strlen(code) ; i++){
        if (code[i]>= 65 && code[i]<= 90 ){
            code[i]= tolower(code[i]);
      }
    }

    for (i=0;i<= strlen(clef) ; i++){
        if (clef[i]>= 65 && clef[i]<= 90 ){
            clef[i]= tolower(clef[i]);
      }
    }

    for (i=0;i<=strlen(code);i++){
       if ((code[i] >= 33 && code[i] <= 47) || (code[i] >= 58 && code[i] <= 64 ) || (code[i] >= 91 && code[i] <= 96 ) || code[i]==' ') {
            code[i] = ' ';
        }
    }

    for (i=0;i<=strlen(code);i++){
       if ((clef[i] >= 33 && clef[i] <= 47) || (clef[i] >= 58 && clef[i] <= 64 ) || (clef[i] >= 91 && clef[i] <= 96 ) || clef[i]==' ') {
            clef[i] = ' ';
        }

    }

    for (i = 0; i <= strlen(code) - 1; i++) {
        
        valeurLettreCode[i] = getValeurLettreCode(code, i);

    }
    
    /*Affectation de la valeur de la lettre pour chaque lettre du clef*/
    for (o = 0; o <= strlen(clef) - 1; o++) {
        valeurLettreClef[o] = getValeurLettreClef(code, o);
    }
    /*Choix entre le cryptage ou le decryptage*/
    printf("Pour crypter entre 0 pour decrypter entre 1 ");
    saisieLigne(choix, sizeof(choix));
    
    for (j = 0; j <= strlen(code) - 1; j++) {
        /*Affectation de l'espace peut importe le si c'est un cryptage ou non*/
        if (valeurLettreCode[j] == 27) {
            Msg[j] = ' ';
            
        }
        /*Condition pour le decryptage*/
        else if(choix[1] == valide[1]) {
            /*Retour a la valeur initiale de la clef quand on l'a totalement parcouru*/
            if (f >= strlen(clef) ) {
                f = 0;
            }
            /*Affectation de la valeur modifiée au msg voulu*/
            Msg[j] =alphabet[ getValeurMsgCode(valeurLettreCode, valeurLettreClef, j, f)];
            f++;
        }
        /*Condition pour le cryptage*/
        else if (choix[0] == valide[0]) {
            /*Retour a la valeur initiale de la clef quand on l'a totalement parcouru*/
            if (f >= strlen(clef)) {
                f = 0;
            }
            /*Affectation de la valeur modifiée au msg voulu*/
            Msg[j] = alphabet[getValeurMsgCodeDecryp(valeurLettreCode, valeurLettreClef, j, f)];
            f++;

        }
    }

    printf("Le message est %s\n", Msg);
}

/*Fonction retournant la valeur de la lettre, on utilise une boucle en dehors de la fonction car il est impossible de retourner directement un tableau*/
int getValeurLettreCode(char* code, int indent) {
    int c;
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    /*Verifie que le caractere est un espace*/
    if (code[indent] == ' ') {
        return 27;

    }
    else {
        /*Incremente c jusqu'a que la lettre du code soit la même que celle de l'alphabet et retourne c*/
        c = 0;
        while (code[indent] != alphabet[c] && code[indent] != ' ') {

            c++;

        }        
        return  c;
    }
}

/*Fonction retournant la valeur de la lettre, on utilise une boucle en dehors de la fonction car il est impossible de retourner directement un tableau*/
int getValeurLettreClef(char* clef, int indent) {
    int c;
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    c = 0;
    /*Incremente c jusqu'a que la lettre de la clef soit la même que celle de l'alphabet et retourne c*/
    while (clef[indent] != alphabet[c]) {
        
        c++;
    }
    return c;
}

/*Fonction retournant la valeur crypté*/
int getValeurMsgCode(int* valeurCode, int* valeurClef, int indent, int f) {
    int resultat;
    /*Application de la formule de cryptage de vigenere*/
    resultat= (valeurCode[indent] - valeurClef[f])%26;
    /*En c quand le modulo est negatif il reste le même or pour vigenere il ne faut pas de modulo negatif, donc je viens rajouter 26 si la valeur est negative pour avoir un resultat correcte*/
    if (resultat < 0 ) {
        resultat += 26;
    }   
    return  resultat;
}

/*Fonction retournant la valeur decrypte*/
int getValeurMsgCodeDecryp(int* valeurCode, int* valeurClef, int indent, int f) {
    int resultat;
    /*Application de la formule de decryptage de vigenere ici pas besoin de rajouter 26 car pas de valeur <0*/
    resultat = (valeurCode[indent] + valeurClef[f]) % 26;
    return  resultat;
}