#include"types.h"
#include<stdlib.h>
#include<stdio.h>
#include<MLV/MLV_all.h>
#include<string.h>
#include"cadeaux.h"
#define L 290

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


}

  
void aff_cad(cadeaux cad, Hotte hot){
  float ratio, ratioy;
  ratio = L/(hot.x*1.0);
  ratioy= L/(hot.y*1.0);
  printf("%f et %f y \n", ratio, ratioy); 

  MLV_draw_filled_rectangle(105+cad.x*ratio, (355+L-(cad.y+cad.haut)*ratioy), cad.larg*ratio, cad.haut*ratioy, MLV_COLOR_DARKGREEN);
 
  
  MLV_draw_filled_rectangle(105+cad.x*ratio+(cad.larg/3)*ratio, (355+L-(cad.y+cad.haut)*ratio), cad.larg/3*ratio, cad.haut*ratioy, MLV_COLOR_RED);  /* bandeau haut bas */ 
  MLV_draw_filled_rectangle(105+cad.x*ratio, (355+L-(cad.y+cad.haut)*ratioy+(cad.haut/3)*ratioy), cad.larg*ratio, cad.haut/3*ratioy, MLV_COLOR_RED);/* bandeau gauche droit */
  MLV_draw_rectangle(105+cad.x*ratio, (355+L-(cad.y+cad.haut)*ratioy), cad.larg*ratio, cad.haut*ratioy, MLV_COLOR_BLACK);
}


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
    return ;/* n'est pas supposer arriver */
}


void init_mlv_hot(Hotte* hot){
    MLV_Input_box *input1;
    char * text1;
    MLV_Event event;
    int largeur, hauteur, prof, choix=-1;
    
    input1 = MLV_create_input_box( 100, 200, 250, 20, MLV_COLOR_BLACK, MLV_COLOR_BLACK, MLV_COLOR_WHITE,"Taille Hotte : ");
    while(1){
        Choix_cad_mlv(&choix);
        if(choix == 0){
            
            hot->x = 120;
            hot->y = 120;
            hot->z = 50;
            hot->niveaux = 1;
            return ;
        }else if(choix == 1) {
      
            event= MLV_get_event(NULL,NULL,NULL,&text1, &input1,NULL,NULL,NULL,NULL);
            MLV_draw_all_input_boxes ();
            if( event == MLV_INPUT_BOX){
                printf("%s\n",text1);
                sscanf(text1,"%d %d %d",&largeur, &hauteur, &prof);
                hot->x = largeur;
                hot->y = hauteur;
                hot->z = prof;
                hot->niveaux = 1;
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




  

