#include "cards.h"
#include "CSFML/Graphics.h"
#include "CSFML/Graphics/Texture.h"
#include "button.h"
#include "string.h"

Card cardCreate(sfColor inColor, char inTitle[50], sfTexture* image){
    const struct Card card = (struct Card) {
        .color = inColor,
    }; 
    strcpy(card.title, inTitle);
    return card; 
}

Slot slotCreate(sfVector2i inLocation, sfVector2i inSize, Card inCard){

    const Slot slot = (Slot) {
        .location = inLocation,
        .size = inSize, 
        .card = inCard, 
        .background = rectangleCreate(inLocation.x, inLocation.y, inSize.x, inSize.y, inCard.color),
    }; 
    return slot; 
}

void slotUpdate(Slot slots[], Card cards[], int gameIdx){
    for(int i = 0; i < 3; i++){
        slots[i].card = cards[gameIdx+i]; 
        sfRectangleShape_setFillColor(slots[i].background, cards[gameIdx+i].color); 
    }
}    


