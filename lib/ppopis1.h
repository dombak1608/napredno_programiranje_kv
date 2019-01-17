#ifndef PPOPIS1_H_
#define PPOPIS1_H_

	/*
	 * struktura koja definira element povezanog popisa
	*/
	typedef struct cvorS
	{
		int vrijednost;
		struct cvorS* iduci;
	}cvor;

	/*
	 * funkcija koja sluzi za inicijalizaciju povezanog popisa, kao povratnu vrijednost vraća NULL pokazivač, što označava da je povezani popis prazan
	*/
	cvor* initPP();

	/*
	 * funkcija koja prima vrijednost elementa koji se zapisuje u novo-stvoreni čvor povezanog popisa
	 * vraća adresu na inicijalizirani čvor
	*/
	cvor* stvaranjeCvora(int);

	/*
	 * funkcija koja prima adresu nultog elementa povezanog popisa te vrijednost koja se dodaje na kraj povezanog popisa,
	 * kao povratnu vrijednost vraća adresu nultog elementa povezanog popisa (što je potrebno, ako se dodaje nulti element)
	*/
	cvor* dodavanjeNaKrajPP(cvor*,int);

	/*
	 * funkcija koja prima adresu nultog elementa povezanog popisa te vrijednost n-tog broja elementa kojeg briše iz pp
	 * kao povratnu vrijednost vraća adresu nultog elementa (što je potrebno, ako se briše nulti element da sa sačuva vrijednost adresa novog nultog elementa)
	*/
	cvor* brisanjeElemIzPP(cvor*,int);

	/*
	 * funkcija koja prima adresu nultog elementa povezanog popisa te briše sve elemente koje se nalaze u povezanom popisu
	*/
	void brisanjePP(cvor*);

	/*
	 * funkcija koja prima adresu nultog elementa povezanog popisa te ispisuje sve vrijednosti elemenata koji se u njemu nalaze
	*/
	void ispisPP(cvor*);

#endif /* PPOPIS1_H_ */
