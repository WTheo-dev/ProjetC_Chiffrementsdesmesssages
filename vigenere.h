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

void VigenereCryp(char* code, char* clef);
int getValeurLettreCode(char* code, int indent);
int getValeurLettreClef(char* clef, int indent);
int getValeurMsgCode(int* valeurCode, int* valeurClef, int indent, int f);
int getValeurMsgCodeDecryp(int* valeurCode, int* valeurClef, int indent, int f);