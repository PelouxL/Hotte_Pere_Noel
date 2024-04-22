#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include"types.h"
#include"cadeaux.h"
#include"tri.h"
#include"interface.h"
#include<MLV/MLV_all.h>
#include"interface_mlv.h"
#include"save.h"


int main(){
  int i=5, k, stop=0, desc=200;
  cadeaux * l;
  Hotte hot;
  srand(time(NULL));
  
  MLV_create_window("Agencement", " ", 1024, 900 );
  while(stop == 0){
    i=choix_nb_cad();
    init_mlv_hot(&hot); /* initialisation de la Hotte */
    menu();
    MLV_actualise_window();
    l = all_mlv_init(i); /* initialisation d'une liste de cadeaux */
    
    trois(l, i); /* tri la liste de façon decroissante */
  
    /* suppr(l, 3); */

    while( calc_mag(l, i, hot) == 1){
      magie(&l[0], 50);
      trois(l,5);
    }
    aff(l,i);
    
    for( k = 0; k < i ; k++){
        if( verifsuperpos(l, 1, &l[k], k, hot) == 1){ /* placement des cadeaux dans la hotte */
            aff_cad(l[k],hot);;
            aff_log(l[k], desc, k, 1);
        }else{
            aff_log(l[k], desc, k, 0);
        }
        desc+=30;
        MLV_actualise_window();	
    }
    stop=1;
  }
  ecrire(hot, l, i);
  printf("\n");
  aff_hot(l, i);
  MLV_wait_seconds(20);
  free(l);
  exit(EXIT_SUCCESS);
}
