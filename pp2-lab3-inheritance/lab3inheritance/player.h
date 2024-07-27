#ifndef PLAYER_H
#define PLAYER_H

#include "object.h"
#include "direction.h"

/**
 * Proszę o utworzenie klasy `Player`, która będzie dziedziczyć po klasie `Object`, następnie proszę zakomentować `UNIMPLEMENTED_playerIsObject`
 * - Klasa ta powinna mieć mieć składową `direction_`, a także operujący na niej getter i setter. Domyślna wartość to `Direction::RIGHT`
 *    - po zdefiniowaniu proszę usunąć `UNIMPLEMENTED_playerHasDirection`
 * - Klasa powinna mieć składową oznaczającą czy gracz żyje, oraz getter i setter: `isAlieve()`, `setIsAlieve()`
 *    - po zdefiniowaniu proszę usunąć `UNIMPLEMENTED_playerCanDie`
 */

//#define UNIMPLEMENTED_playerIsObject
//#define UNIMPLEMENTED_playerHasDirection
//#define UNIMPLEMENTED_playerCanDie

class Player : public Object
{
private:
    Direction direction_;
    bool alive;
public:
    Player() : direction_(Direction::RIGHT), alive(true), Object(ObjectType::OBJECT_PLAYER){}
    Direction direction(){
        return direction_;
    }
    void setDirection(Direction direction1){
        direction_ = direction1;
    }
    bool isAlieve(){
        return alive;
    }
    void setIsAlieve(bool status){
        alive = status;
    }

};

#endif // PLAYER_H
