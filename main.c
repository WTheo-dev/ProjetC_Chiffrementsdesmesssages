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
#define tailleMaxCode 1000
#define tailleMaxClef 100


void Dechiffragecesard(char* code);
void ChiffrementCesard(char* code, int* decallage);
void VigenereCryp(char* code, char* clef);
int getValeurLettreCode(char* code, int indent);
int getValeurLettreClef(char* clef, int indent);
int getValeurMsgCode(int* valeurCode, int* valeurClef, int indent, int f);
int getValeurMsgCodeDecryp(int* valeurCode, int* valeurClef, int indent, int f);
bool saisieLigne(char* code, size_t taille);


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
        VigenereCryp(code, clef)
    }
    printf("FIN");
    return 0;
}




/*Fonction de dechiffrage d'un code cesard*/
void Dechiffragecesard(char* code) {

    int c, i, j, f;
    int taille;
    /* Affectation de d'un double alphabet pour eviter un stack overflow en lors des decallages */
    char ChaineLettre[] = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
    char ChaineTempo[tailleMaxCode];

    taille = strlen(code);
    c = 0;

    /* La boucle for ici permet de faire tout les callages de toutes les lettres de l'alphabet*/
    for (i = 0; i <= 25; i++) {
        c = 0;
        j = 0;
        /* Remise a 0 de notre chaine contenant notre code entre chaque decallage pour evité des problemes de taille*/
        memset(ChaineTempo, 0, sizeof(ChaineTempo));
        /* Boucle while nous permettant de passer toutes les lettres de notres code que l'on souhaite decrypter/crypter */
        while (c <= taille - 1) {
            /* Verification du char espace pour eviter un probleme de modification de ce dernier*/
            if (code[c] == ' ') {
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
    /* Verification que le decalage est bien entre 0 et 26 si ce n'est pas le cas on trouve le decallage a l'aide d'un modulo*/
    while (decallage[0] > 26 || decallage[0] <= 0) {
        decallage[0] %= 26;
    }
    /* Boucle while nous permettant de passer toutes les lettres de notres code que l'on souhaite decrypter/crypter */
    while (c <= taille - 1) {
        /* Verification du char espace pour eviter un probleme de modification de ce dernier*/
        if (code[c] == ' ') {
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

/*Fonction vigenere permetant de crypter ou de decrypter a l'aide d'une clef fournis par l'utilisateur*/
void VigenereCryp(char* code, char* clef) {
    int valeurLettreCode[tailleMaxCode], valeurLettreClef[tailleMaxCode], valeurMsgDecode[tailleMaxCode], tailleCode, i, j, c, tailleClef, f = 0,o;

    char alphabet[] = "abcdefghijklmnopqrstuvwxyz", Msg[strlen(code)],choix[5],valide[]="01";
    /*Affectation de la valeur de la lettre pour chaque lettre du code*/
    for (i = 0; i <= strlen(code) - 1; i++) {
        printf("Valeur de i = %d\n", i);
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
        printf("Valeur de c boucle Code %d\n", c);
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
    printf("Valeur de c boucle Clef %d\n", c);
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

/*Fonction trouvée sur internet permetant d'entrer une phrase sans que le scanf arrete la lecture a un espace (\0) ce qui posait de nombreux pb*/
bool saisieLigne(char* code, size_t taille) {
    size_t i;
    for (i = 0; i < taille - 1; ++i)
    {
        char c;
        if (scanf("%c", &c) != 1)
            return false;
        else if (c == '\n')
            break;
        code[i] = c;
    }
    code[i] = '\0';
    return true;

}