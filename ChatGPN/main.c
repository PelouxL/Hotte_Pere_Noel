#include<stdlib.h>
#include<stdio.h>
#include<time.h>

void viderBuffer(){
  int c = 0;
  while (c != '\n' && c != EOF)
    {
      c = getchar();
    }
}

int main(int argc, char **argv){
  int  nsage=-1;
  char c, s, cad, g1[20],g2[20],g3[20];
  FILE *fic = NULL, *ec;
  srand(time(NULL));


  
  if(argc < 2){
    printf("Erreur veuillez renseigner le nom de l'enfant\n");
    exit(EXIT_FAILURE);
  }
  printf("L'enfant a t-il été sage ? Y or N ou peux importe '?'\n");
  if(scanf("%c",&c)  < 1 || (c !='Y' && c !='N' && c!= '?')){
    printf("Erreur veuillez seulement renseignez N ou Y\n");
  }
  if ( c == 'Y' ){
    nsage=1;
  
  }else if( c == 'N'){
    nsage=0;
  }
  else{
    nsage =rand()%2;
  }


  
  if(system("clear") == 0){
  }
  if( nsage == 0){
    fic = fopen("psage.txt","r");
  }else{
    fic = fopen("sage.txt","r");
  }
  
  viderBuffer();
  printf("Liste de cadeaux ? Y or N\n");
  if(scanf("%c",&cad)  < 1 || (c !='Y' && c !='N')){
    printf("Erreur veuillez seulement renseignez N ou Y\n");
  }



  
  if(cad == 'Y'){
    printf("Veuillez renseignez un cadeaux séparer par des espaces\n");
    viderBuffer();
    if(scanf("%s %s %s",g1, g2, g3)  < 3 ){
      printf("Erreur veuillez seulement renseignez 3 cadeaux\n");
    }
  }
  if(system("clear") == 0){
  }

   ec = fopen("Lettre.txt","w+");
  
  fprintf(stdout,"Mon enfant %s.\n\n", argv[1]);
  fprintf(ec,"Mon enfant %s.\n\n", argv[1]);
  do{
    s=fgetc(fic);
    if (s ==':' && cad=='Y'){
      if(nsage==1){
	fprintf(stdout,"Tu pourras retrouver sous le sapin ton %s, %s et ton %s",g1,g2,g3);
		fprintf(ec,"Tu pourras retrouver sous le sapin ton %s, %s et ton %s",g1,g2,g3);
      }
      else{
	fprintf(stdout,"Malheureusement tu ne pourras pas avoir ton %s, %s et ton %s",g1,g2,g3);
	fprintf(ec,"Malheureusement tu ne pourras pas avoir ton %s, %s et ton %s",g1,g2,g3);
      }
    } 
    fprintf(stdout,"%c",s);
    fprintf(ec,"%c",s);

  } while(s != EOF);
  fclose(fic);
  fclose(ec);
  exit(EXIT_FAILURE);
}
