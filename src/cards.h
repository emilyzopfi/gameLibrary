#include "CSFML/Graphics/Rect.h"
#include "CSFML/Graphics/Types.h"
#include "CSFML/Graphics.h"

typedef struct Card{
    sfColor color; 
    char title[50]; 
    sfTexture* image; 
} Card;

typedef struct Slot{
    sfVector2i location; 
    sfVector2i size; 
    struct Card card; 
    sfRectangleShape* background; 
} Slot;


Card cardCreate(sfColor inColor, char inTitle[50], sfTexture* image); 
Slot slotCreate(sfVector2i inLocation, sfVector2i inSize, Card inCard); 
void slotUpdate(Slot slots[], Card cards[], int gameIdx); 