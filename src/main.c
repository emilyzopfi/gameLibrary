#include "CSFML/Graphics/RectangleShape.h"
#include "CSFML/Graphics/RenderWindow.h"
#include "CSFML/Graphics/Sprite.h"
#include "CSFML/System.h"
#include "CSFML/Graphics.h"
#include "CSFML/System/Vector2.h"
#include "CSFML/Window.h"
#include <time.h> 
#include <stdio.h>
#include <time.h> 
#include "colors.h"
#include <string.h>
#include <stdbool.h>
#include "button.h"
#include "cards.h"
#include "text.h"

sfRenderWindow* window; 
sfFont* font;

int main(int argc, char **argv) {

    // const struct colors col = (struct colors) {
    //     .background = sfBlack,
    //     .color1 = sfMagenta,
    //     .color2 = sfCyan,
    //     .color3 = sfGreen 
    // }; 
    font = sfFont_createFromFile("res/newFont.otf"); 
    struct Card cards[8]; 

    sfVector2i pos0 = {160,200}; 
    sfVector2i pos1 = {400,200}; 
    sfVector2i pos2 = {640,200}; 
    sfVector2i size = {240,200}; 

    sfTexture* imageSnake = sfTexture_createFromFile("res/cardSnake.png", NULL); 
    sfTexture* imageTicTacToe = sfTexture_createFromFile("res/ticTacToe.png", NULL);

    sfSprite* snakeSprite = sfSprite_create(imageSnake); 


    cards[0] = cardCreate(sfMagenta, "snake", imageSnake); 
    cards[1] = cardCreate(sfCyan, "Game 1", imageTicTacToe); 
    cards[2] = cardCreate(sfGreen, "Game 2", imageSnake); 
    cards[3] = cardCreate(sfBlue, "game 3", imageSnake); 
    cards[4] = cardCreate(sfYellow, "game 4", imageSnake); 
    cards[5] = cardCreate(sfRed, "game 5", imageSnake); 
    cards[6] = cardCreate(sfMagenta, "game 6", imageSnake); 
    cards[7] = cardCreate(sfCyan, "game 7", imageSnake); 
    
    struct Slot slots[3];
    slots[0] = slotCreate(pos0, size, cards[0]); 
    slots[1] = slotCreate(pos1, size, cards[1]); 
    slots[2] = slotCreate(pos2, size, cards[2]); 

    int gameIdx = 0; 

    sfVideoMode mode = {{1000, 600}, 32};
    window = sfRenderWindow_create(mode, "welcome", sfClose, sfWindowed, NULL);
    // sfRectangleShape* background = createRectangle(0, 0, 200 ,200, col.background); 

    sfVector2f vec = {300,50};
    sfText* title = textCreate(font, vec, sfMagenta, 50,"Meilei's Console"); 


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
        
        if(buttonClicked(arrowRight, window) && gameIdx < sizeof(cards)/sizeof(cards[0])-3) {
            gameIdx++; 
            slotUpdate(slots, cards, gameIdx); 

        }    
        if(buttonClicked(arrowLeft, window) && gameIdx > 0) {
            gameIdx--; 
            slotUpdate(slots, cards, gameIdx); 
        }    

        sfRenderWindow_clear(window, sfBlack);

        sfVector2f pos0 = {170,350};
        sfVector2f pos1 = {410,350};
        sfVector2f pos2 = {650,350};

        sfText* card0Text = textCreate(font, pos0, sfWhite, 25, slots[0].card.title); 
        sfText* card1Text = textCreate(font, pos1, sfWhite, 25, slots[1].card.title); 
        sfText* card2Text = textCreate(font, pos2, sfWhite, 25, slots[2].card.title); 
        
        // sfRectangleShape* rect0 = sfRectangleShape_create(); 
        // sfRectangleShape_setSize(rect0,(sfVector2f){220,180});  
        // sfRectangleShape_setPosition(rect0,(sfVector2f){180,360}); 
        

        // sfRectangleShape_setTexture(rect0, slots[0].card.image, true); 
        
        sfSprite_setPosition(snakeSprite, (sfVector2f){185,205});
        sfSprite_setScale(snakeSprite, (sfVector2f){3,3});  

        // sfRenderWindow_drawSprite(window, slots[1].image, NULL); 
        // sfRenderWindow_drawSprite(window, slots[2].image, NULL); 
        sfRenderWindow_drawRectangleShape(window, slots[0].background , NULL); 
        sfRenderWindow_drawSprite(window, snakeSprite, NULL); 
        sfRenderWindow_drawRectangleShape(window, slots[1].background, NULL); 
        sfRenderWindow_drawRectangleShape(window, slots[2].background, NULL); 

        // sfRenderWindow_drawRectangleShape(window, rect0, NULL);

        sfRenderWindow_drawText(window, title, NULL);
        sfRenderWindow_drawText(window, card0Text, NULL); 
        sfRenderWindow_drawText(window, card1Text, NULL);
        sfRenderWindow_drawText(window, card2Text, NULL);
        sfRenderWindow_drawRectangleShape(window, arrowRight.shape, NULL); 
        sfRenderWindow_drawRectangleShape(window, arrowLeft.shape, NULL); 
        sfRenderWindow_display(window);
    }

    sfRenderWindow_destroy(window);
    return 0;
}

