#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include"types.h"
#include"cadeaux.h"
#include"tri.h"
#include"interface.h"
#include<MLV/MLV_all.h>
#include"interface_mlv.h"


int main(){
  int i=5, manuelle,k;
  cadeaux * l;
  Hotte hot;

  
  MLV_create_window("Agencement", " ", 1024, 900 );

  menu();
  srand(time(NULL));
  init_hot(&hot); /* initialisation de la Hotte */
  
  vider_buffer();
  manuelle=choix();
  l = all_init(i, manuelle); /* initialisation d'une liste de cadeaux */
  vider_buffer();
   
  aff(l, 5);

  /*
  magie(l);
  aff(l,5);
  */

  
  for( k = 0; k < i ; k++){
      if( verifsuperpos(l, 1, &l[k], k, hot) == 0){ /* placement des cadeaux dans la hotte */
      }   
  }
  printf("\n");
  aff_hot(l, i);
  free(l);
  exit(EXIT_SUCCESS);
}
