#ifndef TRI_H
#define TRI_H

void magie(cadeaux* cad, int red);

int verifsuperpos(cadeaux *cad,int nbhot, cadeaux *cap, int nbcad, Hotte hot);
/* verifie avec tout les cadeaux d'une hotte si le cadeaux qu'on veux poser
ne se supperpose pas avec d'autres, si c'est le cad change les coordonne
de notre cadeau */


int estdedans(cadeaux cad1, cadeaux cad2);

int calc(cadeaux cad); /* permet de calculer l'air */

void trois(cadeaux *cad, int nbcad); /* tri en fonction de la taille */

int calc_mag(cadeaux *cad,int nbcad, Hotte hot);

cadeaux * copie(cadeaux *l, int nbcad);
/* 0 = cadeaux rentre pas, 1 tout cadeaux rentre */

int simulation(cadeaux *cad, int nbhot, int nbcad, Hotte hot );

void calc_eff(cadeaux * cad, int nbcad);


#endif
