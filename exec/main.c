#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "ppopis1.h"

typedef struct dvaCvoraS
{
    cvor* prvi;
    cvor* drugi;
}dvaCvora;

typedef struct redS
{
	cvor* glava;
	int brojElemenata;
}red;

dvaCvora* rastavljanjePP(dvaCvora*, int);
void pushR(int,red*);
int popR(red*);
red* initReda();
red* brisanjeNelem(int,red*);
void brisanjeReda(red*);
void ispisReda(red*);


int main()
{
	//testiranje reda
	printf("pocinje\n");
	red* probni = initReda();
	printf("inicijalizirano\n");

	pushR(1,probni);
	pushR(2,probni);
	pushR(5,probni);
	printf("pushano\n");

	probni = brisanjeNelem(1,probni);
	printf("obrisan element\n");

	ispisReda(probni);

	printf("\n%d",popR(probni));
	printf("\n%d",popR(probni));
	printf("\n%d",popR(probni));
	printf("\npopano\n");
	brisanjeReda(probni);
	printf("obrisan red\n");
	printf("\n%d",popR(probni));


	//testiranje povezanih popisa
    dvaCvora* dupli = (dvaCvora*)malloc(sizeof(dvaCvora));
    dupli->prvi = initPP();
    dupli->drugi = initPP();
    int i;
    int a;
    int br;
    printf("Unos elemenata prvog pp: \n");
    printf("Koliko elemenata zelite unijeti?\n");
    scanf("%d", &br);
    for(i=0 ; i<br ; i++)
    {
        printf("%d. element: ",i+1);
        scanf("%d", &a);
        //printf("%d\n",a);
        dupli->prvi = dodavanjeNaKrajPP(dupli->prvi,a);
    }
    printf("Prvi povezani popis: ");
    ispisPP(dupli->prvi);

//    dupli->prvi = brisanjeElemIzPP(dupli->prvi, 2);
//    printf("Prvi povezani popis: ");
//    ispisPP(dupli->prvi);
//    brisanjePP(dupli->prvi);
//    printf("Obrisan prvi povezani popis: ");
//    ispisPP(dupli->prvi);

    printf("Unesi referentni broj za rastav: ");
    scanf("%d", &a);
    dupli = rastavljanjePP(dupli, a);
    printf("Prvi povezani popis: ");
    ispisPP(dupli->prvi);
    printf("Drugi povezani popis: ");
    ispisPP(dupli->drugi);

    brisanjePP(dupli->prvi);
    brisanjePP(dupli->drugi);
    free(dupli);

    return 0;
}

/*
 * funkcija za rastavljanje povezanog popisa na dva povezana popisa
 * u prvom pp se nalaze elementi manji od referentnog broja koji se predaje funkciji
 * u drugom se nalaze elementi veći ili jednaki referentnom broju
 */
dvaCvora* rastavljanjePP(dvaCvora* glave, int refBr)
{
    dvaCvora* dva;
    dva = glave;
	dva->drugi = NULL;
	cvor* trenutni;
	cvor* trenutni2;
	int i = 0;
	for(trenutni = dva->prvi ; trenutni != NULL ; trenutni = (trenutni->iduci))
	{
		if((trenutni->vrijednost) >= refBr)
		{
			dva->drugi = dodavanjeNaKrajPP(dva->drugi, trenutni->vrijednost);
		}
	}
	trenutni = dva->prvi;
	while(trenutni != NULL)
	{
	    trenutni2 = trenutni->iduci;
	    if((trenutni->vrijednost) >= refBr)
		{
			dva->prvi = brisanjeElemIzPP(dva->prvi, i);
			--i;
		}
		trenutni = trenutni2;
		i++;
	}
	return dva;
}

/*
 * funkcija za inicijalizaciju reda
 */
red* initReda()
{
	red* redNovi = (red*)malloc(sizeof(red));
	redNovi->glava = NULL;
	redNovi->brojElemenata = 0;
	return redNovi;
}

/*
 * funkcija za ubacivanje elementa u red, svaki novi element dodaje na kraj povezanog popisa
 */
void pushR(int vrijednost, red* redG)
{
	redG->glava = dodavanjeNaKrajPP(redG->glava, vrijednost);
	redG->brojElemenata = redG->brojElemenata + 1;
}

/*
 * funkcija za izbacivanje elemenata iz reda, element uzima s početka, ako je red prazan vraća se vrijednost EXIT_FAILURE
 */
int popR(red* redG)
{
	int vrijednost;
	if((redG->brojElemenata)>0)
	{
		vrijednost = redG->glava->vrijednost;
		redG->glava = brisanjeElemIzPP(redG->glava,0);
		redG->brojElemenata--;
		return vrijednost;
	}
	printf("\nRed prazan");
	return EXIT_FAILURE;
}

/*
 * funkcija za brisanje N-tog elementa iz reda
 */
red* brisanjeNelem(int br, red* redG)
{
	if(br > (redG->brojElemenata)) return redG;
	redG->glava = brisanjeElemIzPP(redG->glava,br-1);
	redG->brojElemenata--;
	return redG;
}

/*
 * funkcija za brisanje reda
 */
void brisanjeReda(red* redG)
{
	brisanjePP(redG->glava);
	redG->brojElemenata = 0;
	free(redG);
}

/*
 * funkcija za ispis cijelog red bez brisanja
 */
void ispisReda(red* redG)
{
	cvor* trenutni;
	printf("\nElementi reda: ");
	if (redG->brojElemenata <= 0)
	{
		printf("-\n");
		return;
	}
	for (trenutni = redG->glava ; trenutni != NULL ; trenutni = (trenutni->iduci))
	{
		if((trenutni->iduci) != NULL) printf("%d, ", (trenutni->vrijednost));
		else printf("%d\n", (trenutni->vrijednost));
	}
}
