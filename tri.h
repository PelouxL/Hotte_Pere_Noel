#ifndef TRI_H
#define TRI_H

void magie(cadeaux* cad);

int verifsuperpos(cadeaux *cad,int nbhot, cadeaux *cap, int nbcad, Hotte hot);
/* verifie avec tout les cadeaux d'une hotte si le cadeaux qu'on veux poser
ne se supperpose pas avec d'autres, si c'est le cad change les coordonne
de notre cadeau */


int estdedans(cadeaux cad1, cadeaux cad2);

#endif
