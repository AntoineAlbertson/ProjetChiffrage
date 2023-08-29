#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void creerPerroquet()
{

    char peroq[21] = "\0";

    printf("Veuillez choisir le perroquet de max 20 caracteres a utiliser:");

    scanf("%s", peroq);

    fflush(stdin);


    printf("Creation du perroquet \n");

    FILE *fp = NULL;

    fp = fopen("peroq.def", "w+t");

    if (fp == NULL)
    {
        printf("Erreur Open !");
        return EXIT_FAILURE;
    }

    printf("lg peroq : %d \n", strlen(peroq));

    fwrite(peroq, sizeof(peroq), 1, fp);


    int retClose = fclose(fp);
    if (retClose!= 0)
    {
        printf("Erreur Open !");
        return EXIT_FAILURE;
    }

}
