#include<stdlib.h>
#include<stdio.h>
#include"types.h"


void magie(cadeaux* cad){
  char c;
  int red,i;
  printf("Voulez vous utilisez la magie ? Y N\n");
  if( scanf("%c",&c) < 1 || (c!='N' && c!='Y')){
    printf("erreur lors de la réponse\n");
    return ;
  }
  if ( c == 'Y'){
    printf("Renseigner la taille voulu et le cadeaux separer d'un espace, ex: 75 2\n");
    if( scanf("%d %d",&red, &i) < 2 || ( red!=75 && red!=50 && red!=25 )){
      printf("erreur lors du remplissage, reduction possible 75 50 ou 25\n");
      return ;
    }
    i--;
    switch(red)
      {
      case 75:
        cad[i].larg = (cad->larg * 25) / 100;
        cad[i].haut = (cad->haut * 25) / 100;
        cad[i].pro = (cad->pro * 25) / 100;
        return;
      case 50:
        cad[i].larg = (cad->larg * 50) / 100;
        cad[i].haut = (cad->haut * 50) / 100;
        cad[i].pro = (cad->pro * 50) / 100;
        return;
      case 25:
        cad[i].larg = (cad->larg * 75) / 100;
        cad[i].haut = (cad->haut * 75) / 100;
        cad[i].pro = (cad->pro * 75) / 100;
        return;
      default:
        printf("erreur lors de l'utilisation, selectionner 25, 50 ou 75\n");
        return;
      }
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
  for ( i = 0 ; i < nbcad ; i++ ){
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
    
    if (cap->x + cap->larg > hot.x ){ /* plus de place dans la hotte */
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

cadeaux trois(cadeaux *cad, int nbcad){
    int i,j;
    cadeaux new = cad[0];
    for( i = 0 ; i < nbcad ; i++ ){
        for( j = 0 ; j < nbcad ; j++ ){
            if( calc(cad[j]) < calc(cad[j+1]) ){
                new=cad[j];
                cad[j] = cad[j+1];
                cad[j+1] = new;
            }
        }
    }
    return  *cad;
}


    
        
                
        
    
