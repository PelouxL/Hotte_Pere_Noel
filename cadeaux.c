#include<stdlib.h>
#include<stdio.h>
#include"types.h"
#include"interface.h"

void init_hot(Hotte* hot){
  char c;
  int x,y,z;
  printf("Voulez vous remplir la Hotte manuellement  Y N ? définie de base a 120 120 50\n");
  if( scanf("%c",&c) < 1 || (c !='Y' && c !='N')){
    printf("Erreur veuillez seulement renseignez N ou Y\n");
    return; 
  }
  if( c =='N'){
   
    hot->x = 120;
    hot->y = 120;
    hot->z = 50;
    hot->niveaux = 1;
    printf("allalalala\n");
  }else{
    printf("Donner les dimension seprarer d'un espace\n");
    if((scanf("%d %d %d",&x,&y,&z))< 3){
      printf("Erreur lors du remplissage\n");
      return ;
    }else{
      hot->x = x;
      hot->y = y;
      hot->z = z;
      hot->niveaux = 1;
    }
  }
  return;
} 

cadeaux init_cad(int m){
  int x, y,z;
  cadeaux cad;
   cad.x=0;
   cad.y=0;
   cad.effort=0;
   cad.hotte=0;
  if (m == 1){
    printf("Rentrez la largeur, la hauteur et la profondeur separer d'un espace\n");
    if( scanf("%d %d %d",&x,&y,&z) < 3 ){
      printf("erreur lors du remplissage\n");
       cad.larg = 0;
       cad.haut = 0;
       cad.pro = 0;
       return cad;
    }
    cad.larg = x;
    cad.haut = y;
    cad.pro = z;

  }else{
    cad.larg = rand()%80+20;
    cad.haut = rand()%80+20;
    cad.pro = rand()%20;

  }
  return cad;
}

cadeaux * all_init(int nb_cad, int m){
  int i;
  cadeaux * l;
  l =(cadeaux*) malloc (nb_cad * sizeof(cadeaux));
  if ( l == NULL ){
    return NULL;
  }
  for( i = 0 ; i < nb_cad ; i++ ){
    l[i]=init_cad(m);
  }
  return l;
}

void aff(cadeaux l[N], int n){
  int i;
    for(i = 0 ; i < n ; i++ ){
        printf("cadeaux %d : largeur : %d, hauteur : %d, profondeur : %d\n",i+1 ,l[i].larg, l[i].haut, l[i].pro);

    }
    printf("\n");
}



/* cadeaux *ajout(cadeaux *cad, int n){ /\* permet d'ajouter un cadeau en donnant, la liste de cadeaux , et le nombre de cadeaux déjà present dans la liste *\/ */
/*     cadeaux aj; */
/*     int manuelle; */
/*     printf("lalalala\n"); */
/*     cad = ( cadeaux*) realloc ( cad, (n+1)*sizeof(cadeaux)); */
/*     if(cad == NULL){ */
/*         printf("Erreur d'allocation mémoire lui\n"); */
/*         exit(EXIT_FAILURE); */
/*     } */
/*     printf("lalaiiiiiiilala\n"); */
/*     manuelle=choix(); */
/*     aj = init_cad(manuelle); /\* si ajout définie aleatoirement ou manuellleme,nt *\/ */
/*     cad[n]=aj; */
/*     return cad; */
/* } PROBLEME DALLOCATION REVOIR PLUS TARD */

/* cadeaux * suppr(cadeaux *cad, int n){ */
    
/*     return cad; */
/* } */