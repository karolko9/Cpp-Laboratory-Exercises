#ifndef ENEMY_H
#define ENEMY_H

#include "object.h"

/**
 * Proszę o utworzenie klasy `Enemy`, która będzie dziedziczyć po klasie `Object`
 * - Klasa ta powinna mieć mieć składową odpowiadającą ilości punktów życia, oraz getter: `lifePercent()`
 * - Klasa powinna mieć konstruktor przyjmujący aktualną pozycje oraz maksymalne życie z wartością domyślną.
 * - Klasa powinna mieć metodę `isAlieve()` która zwraca prawdę jeśli wróg ma życie powyżej zera
 * - Klasa powinna mieć metodę `decreaseLife()` przyjmującą jako argument liczbę obrażeń
 * - Po zaimplementowaniu powyższego proszę zakomentować makro `UNIMPLEMENTED_enemy`
 */

//#define UNIMPLEMENTED_enemy

class Enemy : public Object
{
private:
    int life;
    int maxLife;
public:
    Enemy(Position a , int b = 10) : life(b), maxLife(b), Object(ObjectType::OBJECT_ENEMY){};    ///////////////// poprawić
    void decreaseLife(const int&);
    float lifePercent();
    bool isAlieve();
};

#endif // ENEMY_H
