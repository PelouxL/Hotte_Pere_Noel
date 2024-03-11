#include"types.h"
#include<stdlib.h>
#include<stdio.h>
#include<MLV/MLV_all.h>

void menu(){
    MLV_Image* image;

    image = MLV_load_image("images/fond.jpeg");
    MLV_draw_image(image,0,0);
    MLV_actualise_window();
}

void hotte(int x, int y){
    MLV_draw_adapted_text_box(200,200 	