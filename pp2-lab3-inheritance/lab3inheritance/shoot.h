#ifndef SHOOT_H
#define SHOOT_H

#include "object.h"
#include "direction.h"


/**
 * Proszę o utworzenie klasy `Shoot`, która będzie dziedziczyć po klasie `Object`, następnie proszę zakomentować `UNIMPLEMENTED_shootIsObject`
 * - Klasa ta powinna mieć mieć składową `direction_`, a także operujący na niej getter i setter
 * - Klasa powinna mieć konstruktor przyjmujący kierunek i pozycje początkową
 * - Po zaimplementowania tego proszę zakomentować `UNIMPLEMENTED_shootHasDirectionAndPosition`
 * - Klasa powinna zawierać statyczny atrybut odpowiadający prędkości o wartości `2`, oraz getter `speed()`
 */

//#define UNIMPLEMENTED_shootIsObject
//#define UNIMPLEMENTED_shootHasDirectionAndPosition


class Shoot : public Object
{
private:
    Direction direction_;
    static inline int speed_ = 2;
public:
    Shoot(Direction a, Position b = Position())
        : Object(ObjectType::OBJECT_SHOOT, b)
    {
        direction_ = a;
    }
    static int speed(){
        return speed_;
    }
    Direction direction() const{
        return direction_;
    }
    void setDirection(Direction c){
        direction_ = c;
    }
};

#endif // SHOOT_H

