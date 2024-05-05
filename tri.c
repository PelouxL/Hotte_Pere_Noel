#include<stdlib.h>
#include<stdio.h>
#include"types.h"
#include<MLV/MLV_all.h>

char mag[500];

void magie(cadeaux *cad, int red){
  switch(red)
    {
    case 75:
      cad->larg = (cad->larg * 25) / 100;
      cad->haut = (cad->haut * 25) / 100;
      cad->pro = (cad->pro * 25) / 100;
      cad->effort += 3;
      return;
    case 50:
      cad->larg = (cad->larg * 50) / 100;
      cad->haut = (cad->haut * 50) / 100;
      cad->pro = (cad->pro * 50) / 100;
      cad->effort += 2;
      return;
    case 25:
      cad->larg = (cad->larg * 75) / 100;
      cad->haut = (cad->haut * 75) / 100;
      cad->pro = (cad->pro * 75) / 100;
      cad->effort += 1;
      return;
    default:
      printf("erreur lors de l'utilisation, selectionner 25, 50 ou 75\n");
      return;
    }
}




int estdedans(cadeaux cad1, cadeaux cad2){
  if ( cad1.x >= cad2.x && cad1.x <= (cad2.x + cad2.larg) && cad1.y >= cad2.y && cad1.y <= (cad2.y + cad2.haut)){
    return 1;
  }
  return 0;
}

int verifsuperpos(cadeaux *cad,int nbhot, cadeaux *cap, int nbcad, Hotte hot){
  int i, k = 0;
  if (cap->pro > hot.z){
    cap->x = -1;
    cap->y = -1;
    cap->hotte = -1;
    printf("plus de place dans la hotte\n");
    return 0;
  }
  for ( i = 0 ; i < nbcad ; i++ ){
    if( cad[i].hotte == nbhot){
      if ( cap->y <= cad[i].y + cad[i].haut && cap->x <= cad[i].x + cad[i].larg){
	cap->y = cad[i].y + cad[i].haut;
      }
      
      if( cap->y + cap->haut > hot.y){ 
	cap->x = cad[i].x + cad[i].larg;
	cap->y =0;
      
	for( k = 0 ; k < i ; k++){
	  if(cad[k].hotte == nbhot ){
	    if( estdedans(*cap, cad[k]) == 1 ){ /* fait un décalage a droite et si il y a de la place le met sur le cadeaux plus bas */
	      cap->y= cad[k].y+cad[k].haut;
	    }
	  }
	}
      }
    }
    
    if (cap->x + cap->larg > hot.x){ /* plus de place dans la hotte */
      cap->x = -1;
      cap->y = -1;
      cap->hotte = -1;
      printf("plus de place dans la hotte\n");
      return 0;
    }
    
  }
  cap->hotte = nbhot; /* on a pacer le cadeaux dans la hotte */
  printf("Coordonée du cadeau n° %d, x =%d et y = %d\n",nbcad+1, cap->x, cap->y);
  return 1;
}



int calc(cadeaux cad){
    int acc;
    acc = cad.larg * cad.haut;
    return acc;
}

void trois(cadeaux *cad, int nbcad){
    int i,j;
    cadeaux new = cad[0];
    for( i = nbcad-1 ; i > 0 ; i--){
        for( j = 0 ; j < i ; j++ ){
            if( calc(cad[j]) < calc(cad[j+1]) ){
                new=cad[j];
                cad[j] = cad[j+1];
                cad[j+1] = new;
            }
        }
    }
}

int calc_mag(cadeaux *cad,int nbcad, Hotte hot){
  int tho, tca=0, i;
  for(i = 0 ; i < nbcad ; i++){
    tca += cad[i].larg * cad[i].haut;
  }
  tho = (hot.x * hot.y) - 1000;
  if( tho < tca){
    return 1;
  }
  return 0;
}

cadeaux * copie(cadeaux *l, int nbcad){
  int i;
  cadeaux* cop=NULL;
  cop =(cadeaux*) malloc (nbcad * sizeof(cadeaux));
  if ( cop == NULL ){
    printf("Erreur d'allocation \n");
    exit(EXIT_FAILURE);
  }
  for( i = 0 ; i < nbcad ; i++ ){
    cop[i].x= l[i].x;
    cop[i].y= l[i].y;
    cop[i].effort= l[i].effort;
    cop[i].hotte= l[i].hotte;
    cop[i].larg = l[i].larg;
    cop[i].haut = l[i].haut;
    cop[i].pro = l[i].pro;
  }
  return cop;
}

int simulation(cadeaux *cad, int nbhot, int nbcad, Hotte hot ){
  int i, fin=0;
  while(fin == 0){
    for( i = 0 ; i < nbcad ; i++){
      if(verifsuperpos(cad,nbhot, &cad[i], nbcad, hot) == 0){
	return 0;
      }
    }
    fin=1;
  }
  return 1; /* tout les cadeaux rentre */
}

void calc_eff(cadeaux* cad, int nbcad){
  int i, acc=0;
  for(i = 0 ; i < nbcad ; i++){
    acc+=cad[i].effort;
  }
  sprintf(mag,"Total en effort demandé : %d",acc);
  MLV_draw_adapted_text_box(105, 300, mag,1, MLV_COLOR_GREY, MLV_COLOR_YELLOW, MLV_COLOR_GREY, MLV_TEXT_CENTER );
}

void fragile(cadeaux *cad , int nb){
  int i,j, tmpx, tmpy;
  for(i = 0 ; i< nb ; i++){
    for(j = 0 ; j < nb ; j++){
       if( calc(cad[j]) < calc(cad[j+1]) ){
	 if(cad[j].y > cad[j+1].y && (cad[j].x >= cad[j+1].x && (cad[j].x+cad[j].larg) <= (cad[j+1].x+cad[j+1].larg) ) ){

	   tmpx = cad[j].x;
	   tmpy = cad[j].y;

	   cad[j].x = cad[j+1].x;
	   cad[j].y = cad[j+1].y;

	   cad[j+1].x = tmpx;
	   cad[j+1].y = tmpy;
	 }  
       }
    }
  }
}

void malade(cadeaux* l, int i){
  int k;
  for(k = 0; k < i ; k++){
    l[k].x = 0;
    l[k].y=0;
  }
}
