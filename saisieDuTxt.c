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