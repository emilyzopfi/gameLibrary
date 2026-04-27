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

struct Slot slotCreate(sfVector2i inLocation, sfVector2i inSize, Card inCard, char inTitle[]){
    const Slot slot = (Slot) {
        .location = inLocation,
        .size = inSize, 
        .card = inCard, 
        .background = rectangleCreate(inLocation.x, inLocation.y, inSize.x, inSize.y, inCard.color), 
    }; 
    strcpy(slot.title, inTitle); 
    return slot; 
}

void slotUpdate(Slot slots[], Card cards[], int gameIdx){
    for(int i = 0; i < 3; i++){
        slots[i].card = cards[gameIdx+i]; 
        sfRectangleShape_setFillColor(slots[i].background, cards[gameIdx+i].color); 
        strcpy(slots[i].title, cards[gameIdx + i].title); 
    }
}
