#include <stdbool.h>
#include "CSFML/Graphics.h"
#include "CSFML/System.h"
#include "CSFML/Window.h"
#include "button.h" 
#include <stdio.h>

static bool buttonHit(sfVector2i pos, struct Button butt); 
bool mouseLeftPressed; 

bool buttonClicked(struct Button butt, sfRenderWindow* window){ 
    if(mouseReleased() && buttonHit(sfMouse_getPositionRenderWindow(window), butt)) {
        mouseLeftPressed = false; 
        return true; 
    }    
    return false; 
}

bool mouseReleased(){
    if(sfMouse_isButtonPressed(sfMouseLeft)) mouseLeftPressed = true; 
    else if(!sfMouse_isButtonPressed(sfMouseLeft) && mouseLeftPressed) {
        return true; 
    }
    return false; 
}

static bool buttonHit(sfVector2i pos, struct Button butt){
    if(pos.x > butt.pos.x && pos.x < butt.pos.x + butt.size && pos.y > butt.pos.y && pos.y < butt.pos.y + butt.size) return true; 
    return false; 
}

sfRectangleShape* buttonCreate(struct Button butt){
    sfRectangleShape* button = rectangleCreate(butt.pos.x, butt.pos.y, butt.size, butt.size, butt.col); 
    return button; 
}

sfRectangleShape* rectangleCreate(int xCoor, int yCoor, int height, int width, sfColor color){
  sfVector2f size = {width, height}; 
  sfRectangleShape* shape = sfRectangleShape_create(); 
  sfRectangleShape_setSize(shape, size); 
  sfRectangleShape_setFillColor(shape, color);  
  sfVector2f pos = {xCoor,yCoor}; 
  sfRectangleShape_setPosition(shape, pos); 
  return shape; 
}