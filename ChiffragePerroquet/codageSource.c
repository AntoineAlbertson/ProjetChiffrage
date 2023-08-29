#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void coderSource()
{


    printf("codage de source\n");


    //Check perroquet

    FILE *peroq = NULL;

    char lettreLuP = '\0';

    peroq = fopen("peroq.def", "rt");
    if (peroq == NULL)
    {
        printf("Pas de perroquet present\n");
        return;
    }

    fread(&lettreLuP, sizeof(lettreLuP), sizeof(char), peroq);
    if (feof(peroq))
    {
        printf("\nLe perroquet n'a pas de caracteres pour coder\n");
        return;

    }

    //Check source

    FILE *sour = NULL;

    char lettreLuS = '\0';

    sour = fopen("source.txt", "rt");
    if (sour == NULL)
    {
        printf("Pas de fichier source present");
        return;
    }

    fread(&lettreLuS, sizeof(lettreLuS), sizeof(char), sour);
    if (feof(sour))
    {
        printf("\nLa source n'a pas de carateres a coder");
        return;
    }

    //Codage

    FILE *dest = NULL;

    dest = fopen("dest.crt", "w+t");
    if (dest == NULL)
    {
        printf("Erreur lors de creation!");
        return EXIT_FAILURE;
    }

    //printf("lg peroq : %d \n", strlen(peroq));

    int i=0
    char lettreEcr = '\0'

    while(!feof(sour))
    {

        fread(&lettreLu, sizeof(lettreLu), sizeof(char), fp);
        if (feof(fp))
        {
           printf("\n\tFichier Fini !!!");
        }

        fwrite(&lettre, sizeof(lettre), sizeof(char), fp);

        i++;
    }




    //fwrite(peroq, sizeof(peroq), 1, fp);


    int retClose = fclose(fp);
    if (retClose!= 0)
    {
        printf("Erreur Open !");
        return EXIT_FAILURE;
    }









    /*

    while(!feof(fp))
    {
        printf("\nLettre Lu : %c", lettreLu);
        fread(&lettreLu, sizeof(lettreLu), sizeof(char), fp);
        if (feof(fp))
        {
           printf("\n\tFichier Fini !!!");
        }
    }

    while(!feof(fp2))
    {
        printf("\nLettre Lu : %c", lettreLu);
        fread(&lettreLu, sizeof(lettreLu), sizeof(char), fp);
        if (feof(fp))
        {
           printf("\n\tFichier Fini !!!");
        }
    }*/
}
