#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gsl/gsl_rng.h>
#include <time.h>

// const int N = 1000; 	/* liczba wierszy */
// const int M = 1000;	/* liczba kolumn */

#define IJ(i,j,N) (((i)-1) + ((j)-1)*(N))

// gcc -Wall -o ran9 ran9.c -lgsl -lgslcblas -lm
int N, M;


int main(int argc, char **argv)
{
FILE *plik;
unsigned long int *tab;
int i,j, a;
const gsl_rng_type * T;
gsl_rng * r;


//T = gsl_rng_ranlxs2;



char *nazwapl;


if (argc <=1){

fprintf(stderr,"Brak odpowiedzniej liczby argumentow\n");
fprintf(stderr,"Sposob uzycia:\n");
fprintf(stderr,"nazwa_programu liczba_wierszy liczba_kolumn numer_algorytmu_gsl nazwa_pliku_danych\n");

return(-1);

}

else

{

N=atoi(argv[1]);
M=atoi(argv[2]);
a=atoi(argv[3]);
nazwapl=argv[4];

    if ((plik=fopen(nazwapl,"w"))==NULL) {
       fprintf(stderr,"Nie otworzyc pliku\n");

    return(-1);
}

}

switch (a)
     {
    
     case 1:

    T = gsl_rng_mt19937;
    break;

     case 2:

    T = gsl_rng_ranlxs0;
    break;

     case 3:

    T = gsl_rng_ranlxs1;
    break;

     case 4:

    T = gsl_rng_ranlxs2;
    break;


     case 5:

    T = gsl_rng_ranlxd1;
    break;

     case 6:

    T = gsl_rng_ranlxd2;
    break;

     case 7:

    T = gsl_rng_ranlux;
    break;

     case 8:

    T = gsl_rng_ranlux389;
    break;

     case 9:

    T = gsl_rng_cmrg;
    break;

     case 10:

    T = gsl_rng_mrg;
    break;

     case 11:

    T = gsl_rng_taus;
    break;

     case 12:

    T = gsl_rng_taus2;
    break;

     case 13:

    T = gsl_rng_gfsr4;
    break;



     default:

    T = gsl_rng_mt19937;
    break;



}

r = gsl_rng_alloc (T);

gsl_rng_set(r,time(0));


/* Faza 1: tworzymy tablicę liczb tab */

if ((tab = (unsigned long int *) malloc(N*M*sizeof(unsigned long int))) == NULL)
{
	fprintf(stderr, "Nie mozna przydzielic pamieci\n");
	return(-1);
}

for( j = 1; j <= M; j++)
	for( i = 1; i <= N; i++)
		tab[IJ(i,j,N)] = gsl_rng_get (r);
		
/* Faza 2: wypisujemy dane z tablicy T do pliku tablica.dat */

/*if ((plik = fopen("ranlxs2_006.txt","w")) == NULL)
{
	fprintf(stderr, "Nie mozna otworzyc pliku\n");
	return(-1);
}*/


for( i = 1; i <= N; i++)
{
	for( j = 1; j <= M; j++)
		fprintf(plik, "%lu ", tab[IJ(i,j,N)]);
	fprintf(plik, "\n");

}

       printf ("generator type: %s\n", gsl_rng_name (r));
       printf ("seed = %lu\n", time(0));
       printf ("first value = %lu\n", gsl_rng_get (r));

/* Faza 3: sprzątanie */
ferror(plik);
fclose(plik);
free(tab);
gsl_rng_free (r);
return(0);
}
