#ifndef INTERFACE_MLV_H
#define INTERFACE_MLV_H

void menu();

void aff_cad(cadeaux cad, Hotte hot, int i);

void aff_log(cadeaux cad, int desc, int nbcad, int ok);

void init_mlv_hot(Hotte* hot);

int Choix_mlv();

int choix_nb_cad();


cadeaux init_mlv_cad(int choix);

cadeaux * all_mlv_init(int nbcad);

#endif
