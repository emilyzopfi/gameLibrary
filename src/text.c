#include "CSFML/System.h"
#include "CSFML/Graphics.h"
#include "CSFML/System/Vector2.h"
#include "CSFML/Window.h"

sfText* textCreate(char fontPath[], sfVector2f pos, sfColor col, int size, char text[]){
    sfFont* font = sfFont_createFromFile(fontPath); 
    sfText* title = sfText_create(font); 
    sfText_setPosition(title, pos); 
    sfText_setFillColor(title, col); 
    sfText_setCharacterSize(title, 50); 
    sfText_setStyle(title, sfTextRegular);
    sfText_setString(title, text);
    return title; 
}