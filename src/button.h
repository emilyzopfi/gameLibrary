#include <stdbool.h>
#include "CSFML/Window.h"
#include "CSFML/Graphics.h"
#include "CSFML/System.h"

struct Button {
    sfVector2i pos; 
    int size; 
    sfColor col; 
    sfRectangleShape* shape; 
};

bool buttonClicked(struct Button butt, sfRenderWindow* window);
bool mouseReleased(); 

sfRectangleShape* rectangleCreate(int xCoor, int yCoor, int height, int width, sfColor color); 

sfRectangleShape* buttonCreate(struct Button butt); 
