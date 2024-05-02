#include"types.h"
#include<stdlib.h>
#include<stdio.h>
#include<MLV/MLV_all.h>
#include<string.h>
#include"cadeaux.h"
#include"interface.h"
#define L 290
char tabkkk[500];
char nb[220];

void menu(){
 
    /* --------------- fenetre -------------------------------- */
  
    MLV_draw_filled_rectangle(0, 0, 1024, 900,MLV_COLOR_GREY);
    MLV_draw_filled_rectangle(15, 28, 994, 843,MLV_COLOR_BLACK);
    MLV_draw_filled_rectangle(20, 33, 984, 833,MLV_COLOR_WHITE);

    MLV_draw_filled_rectangle(45, 95, 410, 610,MLV_COLOR_BLACK);
    MLV_draw_filled_rectangle(50, 100, 400, 600,MLV_COLOR_DARKGREY);


    /* ---------------- Hotte ---------------------------------- */
  
    MLV_draw_filled_rectangle(98, 348, 304, 304, MLV_COLOR_BLACK); 
    MLV_draw_filled_rectangle(100, 350, 300, 300, MLV_COLOR_RED);
    MLV_draw_filled_rectangle(105, 355, L, L, MLV_COLOR_DARKRED);

    /*----------------- Aléa/man ----------------------------- */

    MLV_draw_adapted_text_box(98, 322, " ?", 6, MLV_COLOR_BLACK, MLV_COLOR_BLACK, MLV_COLOR_GREY,MLV_TEXT_CENTER );
    MLV_draw_adapted_text_box(120, 322, "M", 6, MLV_COLOR_BLACK, MLV_COLOR_BLACK, MLV_COLOR_GREY,MLV_TEXT_CENTER );

    /*------------------------------ Log ---------------------*/
    MLV_draw_adapted_text_box(700, 125, " Logs ",20, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_COLOR_WHITE, MLV_TEXT_CENTER );

}



/*--------------------------------- fonction d'affichage du cadeaux et des logs ------------------------------------------- */
  
void aff_cad(cadeaux cad, Hotte hot, int i){
  float ratio, ratioy;
  ratio = L/(hot.x*1.0);
  ratioy= L/(hot.y*1.0);

  if(cad.effort == 0){
    MLV_draw_filled_rectangle(105+cad.x*ratio, (355+L-(cad.y+cad.haut)*ratioy), cad.larg*ratio, cad.haut*ratioy, MLV_COLOR_DARKGREEN);
  }else{
     MLV_draw_filled_rectangle(105+cad.x*ratio, (355+L-(cad.y+cad.haut)*ratioy),
			       cad.larg*ratio, cad.haut*ratioy, MLV_COLOR_YELLOW);
  }
 
  
  MLV_draw_filled_rectangle(105+cad.x*ratio+(cad.larg/3)*ratio, (355+L-(cad.y+cad.haut)*ratio), cad.larg/3*ratio, cad.haut*ratioy, MLV_COLOR_RED);  /* bandeau haut bas */ 
  MLV_draw_filled_rectangle(105+cad.x*ratio, (355+L-(cad.y+cad.haut)*ratioy+(cad.haut/3)*ratioy), cad.larg*ratio, cad.haut/3*ratioy, MLV_COLOR_RED);/* bandeau gauche droit */
  MLV_draw_rectangle(105+cad.x*ratio, (355+L-(cad.y+cad.haut)*ratioy), cad.larg*ratio, cad.haut*ratioy, MLV_COLOR_BLACK);

  sprintf(nb,"%d",i+1);
  MLV_draw_adapted_text_box(100+cad.x*ratio+(cad.larg/2)*ratio, +(350+L-(cad.y+cad.haut)*ratioy)+(cad.haut/2)*ratioy , nb,1, MLV_ALPHA_TRANSPARENT, MLV_COLOR_BLACK, MLV_ALPHA_TRANSPARENT, MLV_TEXT_CENTER );

}

void aff_log(cadeaux cad, int desc, int nbcad, int ok){
    if( ok == 1 ){
      sprintf(tabkkk,"Coordonée du cadeau n° %d, x =%d et y = %d et coup magique = %d\n",nbcad+1, cad.x, cad.y, cad.effort);
    }else{
        sprintf(tabkkk,"Cadeau n° %d, ne rentre pas dans la Hotte",nbcad+1);

    }
    MLV_draw_adapted_text_box(500, desc, tabkkk,1, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_COLOR_WHITE, MLV_TEXT_CENTER );
}

/* -------------------------------------------------------------------------------------------------------------------------- */

void Choix_cad_mlv(int *m){
    int sx=0, sy=0;   
    if(MLV_get_mouse_button_state( MLV_BUTTON_LEFT ) == MLV_PRESSED){
        MLV_get_mouse_position(&sx, &sy);
        if(sx >= 98 && sx <=119 && sy >=322 && sy <=348){
            *m=0; /* choix aleatoire */
            return;
        }
        
        if(sx >= 120 && sx <=140 && sy >=322 && sy <=348){
            *m=1;
            return ;
        }
    }
    return ;
}


int choix_nb_cad(){
   MLV_Input_box *input1;
   MLV_Event event;
   char *text1;
   int e=0 ,stop = 0;
   menu();
   input1 = MLV_create_input_box( 100, 200, 250, 20, MLV_COLOR_BLACK, MLV_COLOR_BLACK, MLV_COLOR_WHITE,"Nombre de cadeaux : ");
  
   while(stop !=1){
     event= MLV_get_event(NULL,NULL,NULL,&text1, &input1,NULL,NULL,NULL,NULL);
     MLV_draw_all_input_boxes ();
     if( event == MLV_INPUT_BOX){
       printf("%s\n",text1);
       sscanf(text1,"%d",&e);
       stop =1;
     }
     MLV_actualise_window();
     menu();
   }
   MLV_free_input_box(input1);
   return e;
}

void init_mlv_hot(Hotte* hot){
    MLV_Input_box *input1;
    char * text1;
    MLV_Event event;
    int largeur, hauteur, prof, niv, choix=-1, stop =0;
    
    input1 = MLV_create_input_box( 100, 200, 250, 20, MLV_COLOR_BLACK, MLV_COLOR_BLACK, MLV_COLOR_WHITE,"Taille Hotte : ");
    while(stop == 0){
      Choix_cad_mlv(&choix);
      if(choix == 0){   
	hot->x = 120;
	hot->y = 120;
	hot->z = 50;
	hot->niveaux = 1;
	stop=1;
	return ;
      }else if(choix == 1) {
	event= MLV_get_event(NULL,NULL,NULL,&text1, &input1,NULL,NULL,NULL,NULL);
	MLV_draw_all_input_boxes ();
	if( event == MLV_INPUT_BOX){
	  printf("%s\n",text1);
	  sscanf(text1,"%d %d %d %d",&largeur, &hauteur, &prof, &niv);
	  hot->x = largeur;
	  hot->y = hauteur;
	  hot->z = prof;
	  hot->niveaux = niv;
	  stop=1;
	  return;
	}
      }else{
	MLV_draw_adapted_text_box(65, 200, "Veuillez cliquer sur '?' ou 'M' aleatoire ou manuelle ",5, MLV_COLOR_DARKGREY, MLV_COLOR_BLACK, MLV_COLOR_DARKGREY, MLV_TEXT_CENTER );
      }
      MLV_actualise_window();
      menu();
    }
    return;
}


cadeaux init_mlv_cad(int choix){
  MLV_Input_box *input2;
  int x, y,z ;
  MLV_Event event;
  char * text1;
  cadeaux cad;
  cad.x=0;
  cad.y=0;
  cad.effort=0;
  cad.hotte=0;
  if(choix == 0){   
    cad.larg = rand()%80+20;
    cad.haut = rand()%80+20;
    cad.pro = rand()%20;
  }
  if(choix == 1){
     input2 = MLV_create_input_box( 100, 200, 250, 20, MLV_COLOR_BLACK, MLV_COLOR_BLACK, MLV_COLOR_WHITE,"Taille du cadeaux : ");
    while(1){
     
      
      event= MLV_get_event(NULL,NULL,NULL,&text1, &input2,NULL,NULL,NULL,NULL);
      MLV_draw_input_box(input2);
      if( event == MLV_INPUT_BOX){
	printf("%s\n",text1);
	sscanf(text1,"%d %d %d",&x, &y, &z);
	cad.larg= x;
	cad.haut = y;
	cad.pro =z;	
	return cad;
      }else{
   
	MLV_actualise_window();
	menu();
      }
    }
  
  }
  return cad;
}

cadeaux * all_mlv_init(int nbcad){
  int i, stop=0, ch=1;
  cadeaux *l;
  l=(cadeaux*) malloc ( nbcad * sizeof(cadeaux));
  if( l == NULL ){
    printf("Erreur d'allocation mémoire\n");
    exit(EXIT_FAILURE);
  }

  MLV_draw_adapted_text_box(65, 200, "Initialisation des cadeaux '?' ou 'M' ",5, MLV_COLOR_DARKGREY, MLV_COLOR_BLACK, MLV_COLOR_DARKGREY, MLV_TEXT_CENTER );
  while(stop == 0){
  
    Choix_cad_mlv(&ch);
    for( i = 0 ; i < nbcad ; i++){
      l[i]=init_mlv_cad(ch);
    }
    stop=1;
  }
   menu();
  return l;
}

  

