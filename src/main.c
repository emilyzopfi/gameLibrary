#include "CSFML/Graphics.h"
#include "CSFML/Graphics/RenderWindow.h"
#include "CSFML/System.h"
#include "CSFML/Window.h"
#include <time.h> 
#include <stdio.h>
#include <time.h> 
#include "colors.h"
#include <string.h>
#include <stdbool.h>
#include "button.h"

sfRenderWindow* window; 

int main(int argc, char **argv) {

    // const struct colors col = (struct colors) {
    //     .background = sfBlack,
    //     .color1 = sfMagenta,
    //     .color2 = sfCyan,
    //     .color3 = sfGreen 
    // }; 

    sfColor games[] = {sfGreen, sfMagenta, sfYellow, sfCyan, sfGreen, sfMagenta, sfYellow, sfCyan}; 
    int gameIdx = 0; 

    sfVideoMode mode = {{1000, 600}, 32};
    window = sfRenderWindow_create(mode, "welcome", sfClose, sfWindowed, NULL);
    // sfRectangleShape* background = createRectangle(0, 0, 200 ,200, col.background); 


    // creation of title 
    sfFont* font = sfFont_createFromFile("res/newFont.otf"); 
    sfText* title = sfText_create(font); 
    sfVector2f vec = {300,50};
    sfText_setPosition(title, vec); 
    sfText_setFillColor(title, sfMagenta); 
    sfText_setCharacterSize(title, 50); 
    sfText_setStyle(title, sfTextRegular);
    sfText_setString(title, "Meilei's Console");

    struct Button arrowLeft = (struct Button) {
        .pos = {50,300},
        .size = 60,
        .col = sfMagenta
    }; arrowLeft.shape = buttonCreate(arrowLeft); 
        struct Button arrowRight = (struct Button) {
        .pos = {890,300},
        .size = 60,
        .col = sfMagenta
    }; arrowRight.shape = buttonCreate(arrowRight); 
    

    while (sfRenderWindow_isOpen(window)) {
        sfEvent event;
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
        }
        
        if(buttonClicked(arrowRight, window) && gameIdx < sizeof(games)/sizeof(games[0])-3) gameIdx++; 
        if(buttonClicked(arrowLeft, window) && gameIdx > 0) gameIdx--; 


        sfRenderWindow_clear(window, sfBlack);

        sfRectangleShape* card1 = rectangleCreate(160,200,240,200, games[gameIdx]); 
        sfRectangleShape* card2 = rectangleCreate(400,200,240,200, games[gameIdx + 1]); 
        sfRectangleShape* card3 = rectangleCreate(640,200,240,200, games[gameIdx + 2]); 

        // want to create a start up screen with menu. 
        // sfRenderWindow_drawRectangleShape(window, background, NULL); 
        sfRenderWindow_drawRectangleShape(window, card1, NULL); 
        sfRenderWindow_drawRectangleShape(window, card2, NULL); 
        sfRenderWindow_drawRectangleShape(window, card3, NULL); 
        sfRenderWindow_drawText(window, title, NULL); 
        sfRenderWindow_drawRectangleShape(window, arrowRight.shape, NULL); 
        sfRenderWindow_drawRectangleShape(window, arrowLeft.shape, NULL); 
        sfRenderWindow_display(window);
    }

    sfRenderWindow_destroy(window);
    return 0;
}