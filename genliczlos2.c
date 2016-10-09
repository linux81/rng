#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gsl/gsl_rng.h>
#include <time.h>
#define IJ(i,j,N) (((i)-1) + ((j)-1)*(N))

// compilation gcc -Wall -o rng2 genliczlos2.c -lgsl -lgslcblas -lm


int N, M;




int main(int argc, char **argv)
{
FILE *plik;
unsigned long int *tab;
int i,j, a;
const gsl_rng_type * T;
gsl_rng * r;

char *nazwapl;

// definition of input parameters: prg_name nbr_rows nbr_colm nbr_alg file_name  


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

/* list GLS alghoritms acc to GSL manual:

https://www.gnu.org/software/gsl/manual/html_node/Random-number-generator-algorithms.html#Random-number-generator-algorithms */

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

     case 14:

    T = gsl_rng_rand;
    break;

     case 15:

    T = gsl_rng_random_bsd;
    break;

     case 16:

    T = gsl_rng_random_libc5;
    break;

     case 17:

    T = gsl_rng_random_glibc2;
    break;

     case 18:

    T = gsl_rng_rand48;
    break;

     case 19:

    T = gsl_rng_ranf;
    break;

     case 20:

    T = gsl_rng_ranmar;
    break;

     case 21:

    T = gsl_rng_r250;
    break;

     case 22:

    T = gsl_rng_tt800;
    break;

     case 23:

    T = gsl_rng_vax;
    break;

     case 24:

    T = gsl_rng_transputer;
    break;

     case 25:

    T = gsl_rng_randu;
    break;

     case 26:

    T = gsl_rng_minstd;
    break;

     case 27:

    T = gsl_rng_uni;
    break;

     case 28:

    T = gsl_rng_uni32;
    break;

     case 29:

    T = gsl_rng_slatec;
    break;

     case 30:

    T = gsl_rng_zuf;
    break;

     case 31:

    T = gsl_rng_knuthran2;
    break;

     case 32:

    T = gsl_rng_knuthran2002;
    break;

     case 33:

    T = gsl_rng_knuthran;
    break;

     case 34:

    T = gsl_rng_borosh13;
    break;

     case 35:

    T = gsl_rng_fishman18;
    break;

     case 36:

    T = gsl_rng_fishman20;
    break;

     case 37:

    T = gsl_rng_lecuyer21;
    break;

     case 38:

    T = gsl_rng_waterman14;
    break;

     case 39:

    T = gsl_rng_fishman2x;
    break;

     case 40:

    T = gsl_rng_coveyou;
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
