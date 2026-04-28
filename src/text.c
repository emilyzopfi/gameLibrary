#include "CSFML/System.h"
#include "CSFML/Graphics.h"
#include "CSFML/System/Vector2.h"
#include "CSFML/Window.h"

sfText* textCreate(sfFont* font, sfVector2f pos, sfColor col, int size, char text[]){
    sfText* title = sfText_create(font); 
    sfText_setPosition(title, pos); 
    sfText_setFillColor(title, col); 
    sfText_setCharacterSize(title, 50); 
    sfText_setStyle(title, sfTextRegular);
    sfText_setString(title, text);
    return title; 
}