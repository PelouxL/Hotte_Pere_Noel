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
  srand(time(NULL));
  
  MLV_create_window("Agencement", " ", 1024, 900 );
  while(1){
      menu();
      init_mlv_hot(&hot); /* initialisation de la Hotte */
 
  vider_buffer();
  manuelle = choix();
  l = all_init(i, manuelle); /* initialisation d'une liste de cadeaux */
  vider_buffer();
   
  trois(l, 5); /* tri la liste de façon decroissante */
  aff(l,5);
  

  /*
  magie(l);
  aff(l,5);
  */
  /* suppr(l, 3); */
  
  for( k = 0; k < i ; k++){
      if( verifsuperpos(l, 1, &l[k], k, hot) == 1){ /* placement des cadeaux dans la hotte */
	aff_cad(l[k],hot);
	MLV_actualise_window();
      }   
  }
  printf("\n");
  aff_hot(l, i);
  MLV_wait_seconds(20);
  free(l);
  exit(EXIT_SUCCESS);
}
