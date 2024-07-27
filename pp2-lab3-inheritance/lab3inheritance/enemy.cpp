#include "enemy.h"

float Enemy::lifePercent(){
    return (life*100/maxLife);
}
bool Enemy::isAlieve(){
    return(life > 0);
}
void Enemy::decreaseLife(const int& a){
    life -= a;
}
//Enemy::Enemy(Position a, int b){
//
//}

