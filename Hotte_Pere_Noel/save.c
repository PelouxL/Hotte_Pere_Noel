#include<stdlib.h>
#include<stdio.h>
#include"types.h"

int tabk[100];

void ecrire(Hotte hot, cadeaux *cad, int nbcad){
  int i;
  FILE * fic;
  fic = fopen("save.txt","w+");
  if( fic == NULL ){
    printf("Erreur lors de l'ouverture du fichier \n");
    exit(EXIT_FAILURE);
  }
  fprintf(fic,"Taille Hotte format : x y z \n");
  fprintf(fic,"%d %d %d\n",hot.x, hot.y, hot.z);
  fprintf(fic,"Taille cadeaux format : num x y largeur hauteur pro \n");
  for( i = 0 ; i < nbcad ; i++ ){
    if(cad[i].hotte != -1){
      fprintf(fic,"%d %d %d %d %d %d\n",i+1, cad[i].x, cad[i].y, cad[i].larg, cad[i].haut ,cad[i].pro);
    }
  }
  fclose(fic);
}

  

  
  
