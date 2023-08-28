#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void creerPerroquet(){

    char peroq[20] = "\0";

printf("Veuillez choisir le perroquet a utiliser:");

scanf("%s", peroq);

//fflush(stdin);


printf("Creation du perroquet");

FILE *fp = NULL;

fp = fopen("peroq.def", "w+t");

if (fp == NULL)
    {
        printf("Erreur Open !");
        return EXIT_FAILURE;
    }


fwrite(peroq, sizeof(peroq), 1 , fp);


int retClose = fclose(fp);
    if (retClose!= 0)
    {
        printf("Erreur Open !");
        return EXIT_FAILURE;
    }

}
