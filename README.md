# ProjetC_Chiffrementsdesmesssages
Projet réalisé par GINESTE Hugo et WAZYDRAG Théo (A2)

Ce projet est disponible via ce lien : https://github.com/WTheo-dev/ProjetC_Chiffrementsdesmesssages ( Nous vous conseillons de lire le README directement sur la page d'accueil du projet via GitHub ).

Notre projet utilise 5 fonctionnalités distinctes telles que le codage et le décodage en César et Vigenère de saisie de texte.

Elle fonctionne avec l'ensemble des caractères (hors chiffres), aussi bien les lettres que les caractères spéciaux de la table ASCII de base.

Cela comprend donc les lettres majuscules et minuscules que l'application 

# Utilisation de ce projet

Avant tous, il est nécessaire de compiler l'entièreté des fichiers, pour cela il faut utiliser le makefile fourni dans le git, puis ensuite taper les commandes makeall et enfin pour mettre en route le programme il faut taper la commande ./main. Ces commandes nécessitent pour le bon fonctionnement un terminal sous Linux.

# Documentation des fonctions

# main.c

• int main(void)

sortie : (entier) 

Permet le choix du type de cryptographie ainsi que le fait de choisir s'il l'on veut coder ou decoder notre message


• void Dechiffragecesard(char* code)

entrée : (chaine)chaine de caractère

Permet de decoder une chaine de caractère, caractère par caractère, grâce à la fonction Dechiffragecesard.


• void ChiffremenCesard(char* code, int* decallage)

entrée :  (chaine) chaine de caractère, (entier) nombre de décalage à appliquer 

Permet de coder une chaîne de caractère, toute en nous donnant le nombre de décalage, à l'aide de la fonction ChiffrementCesard


• void VigenereCryp(char* code, char* clef)

entrée : (chaine) chaine de caractère, (chaine) clef pour crypter et decrypter

Permet de crypter et decrypter à l'aide d'une clef fournie par l'utilisateur


•  int getValeurLettreCode(char* code, int indent)

entrée : (code) chaine de code, (entier) indentation 

sortie : (entier) Position de la lettre 

Permet de retourner la valeur de la lettre 


• int getValeurLettreClef(char* cle, int indent)

entrée : (chaine) Chaine de caractere pour la clé, (entier) indentation 

sortie : (entier) Position de la lettre 

Permet de retourner la valeur de la lettre


• int getValeurMsgCode(int* valeurCode, int* valeurClef, int indent, int f)

entrée : (entier) Valeur du code, (entier) Valeur de la Clef, (entier) Indentation, (entier) valeur de f

sortie : (entier) Valeur Crypté

Permet d'obtenir la valeur crypté du message


• int getValeurMsgCodeDecryp(int* valeurCode, int* valeurClef, int indent, int f)

entrée : (entier) Valeur du code, (entier) Valeur de la Clef, (entier) Indentation, (entier) valeur de f

sortie : (entier) Valeur Crypté

Permet d'obtenir la valeur décrypté du message


• bool saisieLigne(char* code, size_t taille)

entrée: (chaine) Chaine de caractere equivalente au code, (size_t) taille de la ligne

sortie: (boolean)

Permet d'ecrire une phrase sans que le scanf arrete la lecture a un espace.
















