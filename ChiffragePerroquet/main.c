#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "header.h"

int main()
{

    char choix = '0';
    bool exit = false;

    //Intro � l'utilisateur du logiciel
    printf("Bonjour \nBienvenue dans l'interface de codage ASCII d'Antoine.\n");
    printf("Nous pourrons ici coder un message par l'algorithme du perroquet.\n");


    //loop
    while (!exit){

    //Ouverture du menu
    printf("\nQue souhaitez vous faire ? Choisissez en tapant le chiffre correspondant:\n");
    printf("1. Choix du perroquet\n");
    printf("2. Codage du fichier source\n");
    printf("3. Decodage du fichier dest\n");
    printf("4. Quitter l'application\n");

    scanf("%c",&choix);

    switch (choix){

    case '1':

        creerPerroquet();

    break;

    case '2':

        coderSource();

    break;

    case '3':

        decoderDest();

    break;

    case '4':

        exit = true;

    break;

    default:

        printf("\nSaisi incorrecte, merci de reessayer.\n");

    break;


    }
}

printf("Merci d'avoir utilise l'appli. Bonne journee!");






    //Selection

    //1. Choisir perroquet
    //Demander

    //cr�er/modifier le fichier





    //2. Coder le texte
    //check perroquet

    //code

    //cr�er cod�

    //suppression de source

    //r�sultat





    //3. d�coder le texte

    //Check perroquet

    //d�code

    //Cr�er fichier

    //supprimer le cod�


    return 0;
}
