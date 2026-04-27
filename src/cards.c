#include "cards.h"
#include "CSFML/Graphics.h"
#include "button.h"
#include "string.h"

struct Card cardCreate(sfColor inColor, char* inTitle){
    const struct Card card = (struct Card) {
        .color = inColor,
    }; 
    strcpy(card.title, inTitle);
    return card; 
}

struct Slot slotCreate(sfVector2i inLocation, sfVector2i inSize, Card inCard){
    const Slot slot = (Slot) {
        .location = inLocation,
        .size = inSize, 
        .card = inCard, 
        .background = rectangleCreate(inLocation.x, inLocation.y, inSize.x, inSize.y, inCard.color)
    }; 
    return slot; 
}

void slotUpdate(Slot slots[], Card cards[], int gameIdx){
    slots[0].card = cards[gameIdx]; 
    slots[1].card = cards[gameIdx + 1]; 
    slots[2].card = cards[gameIdx + 2]; 
    sfRectangleShape_setFillColor(slots[0].background, cards[gameIdx].color); 
    sfRectangleShape_setFillColor(slots[1].background, cards[gameIdx+1].color); 
    sfRectangleShape_setFillColor(slots[2].background, cards[gameIdx+2].color); 
}
