#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

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
    fseek(sour, 0, SEEK_SET);

    //Codage

    FILE *dest = NULL;

    dest = fopen("dest.txt", "w+t");
    if (dest == NULL)
    {
        printf("Erreur lors de creation!");
        return EXIT_FAILURE;
    }

    //printf("lg peroq : %d \n", strlen(peroq));

    int i=0;
    char lettreEcr = '\0';

    int peroqSize = -1;

    while(!feof(peroq))
    {
        fread(&lettreLuP, sizeof(lettreLuP), sizeof(char), peroq);
        peroqSize++;
    }



    while(!feof(sour))
    {

        fread(&lettreLuS, sizeof(lettreLuS), sizeof(char), sour);

        printf("Valeur de i : %d \n", i);
        printf("lettre de la source : %c \n", lettreLuS);

        if (feof(sour))
        {
            printf("\nFin de fichier\n");
        }

        printf("peroqsize : %d \n", peroqSize);

        fseek(peroq, i % peroqSize, SEEK_SET);
        fread(&lettreLuP, sizeof(lettreLuP), sizeof(char), peroq);

        printf("lettre du peroq : %c \n", lettreLuP);

        lettreEcr = (lettreLuS - lettreLuP) % 128;

        printf("lettre codee : %c \n", lettreEcr);

        if (!feof(sour))
        {
            fwrite(&lettreEcr, sizeof(lettreEcr), sizeof(char), dest);
        }

        i++;
    }


    int retClose = fclose(sour);
    if (retClose!= 0)
    {
        printf("Erreur Open !");
        return EXIT_FAILURE;
    }

    retClose = fclose(dest);
    if (retClose!= 0)
    {
        printf("Erreur Open !");
        return EXIT_FAILURE;
    }

    retClose = fclose(peroq);
    if (retClose!= 0)
    {
        printf("Erreur Open !");
        return EXIT_FAILURE;
    }

    int retRemove = remove("source.txt");
    if ( retRemove != 0 )
    {
        printf( "Erreur lors de la suppression code: %d \n", retRemove );

        return EXIT_FAILURE;
    }

}
