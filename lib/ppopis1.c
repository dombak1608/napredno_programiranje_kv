#include "ppopis1.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

cvor* initPP()
{
	return NULL;
}

cvor* stvaranjeCvora(int broj)
{
	cvor* novi;
	novi = (cvor*)malloc(sizeof(cvor));
	(novi->iduci) = NULL;
	(novi->vrijednost) = broj;
	return novi;
}

cvor* dodavanjeNaKrajPP(cvor* glava, int broj)
{
	if(glava == NULL)
	{
		glava = stvaranjeCvora(broj);
		return glava;
	}
	cvor* trenutni;
	for (trenutni = glava ; (trenutni->iduci) != NULL ; trenutni = (trenutni->iduci));

	trenutni->iduci = stvaranjeCvora(broj);
	return glava;
}

cvor* dodavanjeNaPocetakPP(cvor* glava, int broj)
{
	if(glava == NULL)
	{
		glava = stvaranjeCvora(broj);
		return glava;
	}
	cvor* trenutni;
	trenutni = stvaranjeCvora(broj);
	trenutni->iduci = glava;
	return trenutni;
}

cvor* brisanjeElemIzPP(cvor* glava, int broj)
{
	cvor* trenutni = glava;
	cvor* temp;
	int i;
	if(broj == 0)
	{
		temp = (trenutni->iduci);
		free(trenutni);
		return temp;
	}
	for (i=1;i<broj;i++)
	{
		if ((trenutni == NULL) || ((trenutni->iduci) == NULL)) return glava;
		trenutni = (trenutni->iduci);
	}
	temp = (trenutni->iduci->iduci);
	free(trenutni->iduci);
	(trenutni->iduci) = temp;
	return glava;
}

void brisanjePP(cvor* glava)
{
	cvor* trenutni;
	for(trenutni = glava ; trenutni != NULL ; trenutni = brisanjeElemIzPP(trenutni, 0));
}

void ispisPP(cvor* glava)
{
	cvor* trenutni;
	printf("\nElementi povezanog popisa: ");
	if (glava == NULL)
    {
        printf("-\n");
        return;
    }
	for (trenutni = glava ; trenutni != NULL ; trenutni = (trenutni->iduci))
	{
		if((trenutni->iduci) != NULL) printf("%d, ", (trenutni->vrijednost));
		else printf("%d\n", (trenutni->vrijednost));
	}
}
