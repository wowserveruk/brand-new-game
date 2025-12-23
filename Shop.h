#pragma once
#include <vector>
#include "Item.h"
#include "Player.h"
class Shop{public:std::vector<Item> stock{{"Spice",30},{"Vials",80},{"Relics",200}};void Draw(Player&p){int y=120;for(auto&i:stock){int price=i.basePrice+GetRandomValue(-10,30);DrawText(TextFormat("%s $%d",i.name.c_str(),price),50,y,20,WHITE);if(IsKeyPressed(KEY_ONE)){if(p.cash>=price&&p.inventory.Add(i.name,1)){p.cash-=price;}}y+=30;}};
