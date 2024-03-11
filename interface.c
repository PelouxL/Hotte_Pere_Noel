#include<stdlib.h>
#include<stdio.h>
#include"types.h"

int choix(){
  char c;
  printf("Voulez rentrez les cadeaux manuellement ? Y N\n");
  if( scanf("%c",&c) < 1 || (c !='Y' && c !='N')){
    printf("Erreur veuillez seulement renseignez N ou Y\n");
  }
  if ( c == 'Y' ){
    return 1;
  }
  return 0;
}

void aff_hot(cadeaux *cad, int n){
  int i;
  for(i = 0 ; i < n ; i++ ){
    if( cad[i].hotte == -1 ){
      printf("Le cadeaux n°%d n'a pas pu etre ranger dans hotte\n",i+1);
    }else{
      printf("Le cadeaux n°%d : dans la Hotte n°%d \n",i+1 ,cad[i].hotte);
    }
    printf("\n");
  }
}

void vider_buffer(){
  int c=0;    
  while (c!='\n' && c != EOF) {
    c = getchar();
  }
}
