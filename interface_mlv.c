#include"types.h"
#include<stdlib.h>
#include<stdio.h>
#include<MLV/MLV_all.h>
#define L 290

void menu(){
  MLV_Input_box *input1;
  char * text1;
  MLV_Event event;
  cadeaux cad;
  float ratio;
   
  cad.larg=60;
  cad.haut=60;
  cad.pro=20;
  cad.x=60;
  cad.y=0;
  cad.effort=0;
  cad.hotte=1;

  ratio = L/120.0;
  printf("%f \n",ratio);
  MLV_draw_filled_rectangle(0, 0, 1024, 900,MLV_COLOR_GREY);
  MLV_draw_filled_rectangle(15, 28, 994, 843,MLV_COLOR_BLACK);
  MLV_draw_filled_rectangle(20, 33, 984, 833,MLV_COLOR_WHITE);

  MLV_draw_filled_rectangle(45, 95, 410, 610,MLV_COLOR_BLACK);
  MLV_draw_filled_rectangle(50, 100, 400, 600,MLV_COLOR_DARKGREY);


  /* ---------------- Hotte ---------------------------------- */
  
  MLV_draw_filled_rectangle(98, 348, 304, 304, MLV_COLOR_BLACK); 
  MLV_draw_filled_rectangle(100, 350, 300, 300, MLV_COLOR_RED);
  MLV_draw_filled_rectangle(105, 355, L, L, MLV_COLOR_DARKRED);

  /* MLV_draw_filled_rectangle(105, 355, cad.larg*ratio, cad.haut*ratio, MLV_COLOR_GREEN); */
 ;
  MLV_draw_filled_rectangle(105+cad.x*ratio, (355+L-(cad.y+cad.haut)*ratio), cad.larg*ratio, cad.haut*ratio, MLV_COLOR_GREEN);
  MLV_draw_rectangle(105+cad.x*ratio, (355+L-(cad.y+cad.haut)*ratio), cad.larg*ratio, cad.haut*ratio, MLV_COLOR_BLACK);
  
  printf("x = %f\n",105+cad.y*ratio); 
     
  input1 = MLV_create_input_box( 600, 400, 250, 20, MLV_COLOR_BLACK, MLV_COLOR_GREY, MLV_COLOR_WHITE,"Taille Hotte : ");
  while(1){
      event= MLV_get_event(NULL,NULL,NULL,&text1, &input1,NULL,NULL,NULL,NULL);  
      if( event == MLV_INPUT_BOX){
          printf("%s\n",text1);
      }
      MLV_draw_all_input_boxes ();
  
  

       /* event = MLV_get_event(  */
       /*                  NULL, NULL, NULL, */
       /*                  &text1, &input1, */
       /*                  NULL, NULL, NULL, */
       /*                  NULL); */

   
    
    MLV_actualise_window();
  }
}

/* void aff_cad(cadeaux cad, Hotte hot){ */
/*     MLV_draw_rectangle(105+cad.x*ratio, (355+L-(cad.y+cad.haut)*ratio), cad.larg*ratio, cad.haut*ratio, MLV_COLOR_BLACK); */
/*     MLV_draw_filled_rectangle(105+cad.x*ratio, (355+L-(cad.y+cad.haut)*ratio), cad.larg*ratio, cad.haut*ratio, MLV_COLOR_GREEN); */



