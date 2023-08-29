#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


void decoderDest()
{


    printf("Decodage de dest\n");


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
        printf("\nLe perroquet n'a pas de caracteres pour decoder\n");
        return;

    }

    //Check dest

    FILE *dest = NULL;

    char lettreLuD = '\0';

    dest = fopen("dest.txt", "rt");
    if (dest == NULL)
    {
        printf("Pas de fichier dest present");
        return;
    }

    fread(&lettreLuD, sizeof(lettreLuD), sizeof(char), dest);
    if (feof(dest))
    {
        printf("\nLe dest n'a pas de carateres a decoder");
        return;
    }
    fseek(dest, 0, SEEK_SET);

    //Codage

    FILE *sour2 = NULL;

    sour2 = fopen("sour2.txt", "w+t");
    if (sour2 == NULL)
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



    while(!feof(dest))
    {

        fread(&lettreLuD, sizeof(lettreLuD), sizeof(char), dest);

        printf("Valeur de i : %d \n", i);
        printf("lettre de la dest : %c \n", lettreLuD);

        if (feof(dest))
        {
            printf("\nFin de fichier\n");
        }

        printf("peroqsize : %d \n", peroqSize);

        fseek(peroq, i % peroqSize, SEEK_SET);
        fread(&lettreLuP, sizeof(lettreLuP), sizeof(char), peroq);

        printf("lettre du peroq : %c \n", lettreLuP);

        lettreEcr = (lettreLuD + lettreLuP) % 128;

        printf("lettre codee : %c \n", lettreEcr);

        if (!feof(dest))
        {
            fwrite(&lettreEcr, sizeof(lettreEcr), sizeof(char), sour2);
        }

        i++;
    }



    int retClose = fclose(dest);
    if (retClose!= 0)
    {
        printf("Erreur Open !");
        return EXIT_FAILURE;
    }

    retClose = fclose(sour2);
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

    int retRemove = remove("dest.txt");
    if ( retRemove != 0 )
    {
        printf( "Erreur lors de la suppression: %d \n", retRemove );
        return EXIT_FAILURE;
    }

}
