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
  int i=5, k, stop=0, desc=200, simu=0, cad_red=1, reduction = 25, cad_pla = 0;
  cadeaux * l, *tmp = NULL, *tmp2 = NULL;
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
    aff(l,i);
    tmp = copie(l, i);
    tmp2 = copie(l, i);


    /* Simulation pour vérifier que tout les cadeaux rentre dans 1 Hotte */
    
    while(simu == 0){
      if(simulation(tmp,1,i,hot) == 0){
	if(tmp != NULL){
	  free(tmp);
	}
	tmp= copie(tmp2, i);
	for( k = cad_pla ; k < cad_red ; k++){
	  if(reduction > 75){
	    magie(&tmp2[k],75);
	    reduction = 25;
	    cad_red++;
	    cad_pla++;
	    
	  }
	    if(cad_red >= i){
	    simu =1;
	  }
	   
	  magie(&tmp[k],reduction);
	}
	reduction+=25;
      }else{
	free(tmp2);
	tmp2 = copie(tmp,i);
	malade(tmp2,i);
	/*trois(tmp2,i); */
	simu=1;
	
      }
    }

    l = copie(tmp2, i);
    
    /*************************************************************************/
    
    for( k = 0; k < i ; k++){
      if( verifsuperpos(l, 1, &l[k], k, hot) == 1){  /*placement des cadeaux dans la hotte */
	aff_cad(l[k],hot, k);
	aff_log(l[k], desc, k, 1);
        }else{
            aff_log(l[k], desc, k, 0);
        }
        desc+=30;
        MLV_actualise_window();
    }
    stop=1;
  }
   
  calc_eff(l,i);
  ecrire(hot, l, i);
  MLV_actualise_window();
  printf("\n");
  aff_hot(l, i);
  
  MLV_wait_seconds(20);
  free(l);
  exit(EXIT_SUCCESS);
}
