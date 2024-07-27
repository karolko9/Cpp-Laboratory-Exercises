#include "object.h"

Object::Object(ObjectType objt, Position post){
    objecttype1 = objt;
    position1 = post;
}
Object::Object(){

}

ObjectType Object::type() const{
    return objecttype1;
}
Position Object::position() const{
    return position1;
}
void Object::setPosition(Position post) {
    position1 = post;
}
void Object::moveUp(){
    position1.moveUp();
}
void Object::moveDown(){
    position1.moveDown();
}
void Object::moveLeft(){
    position1.moveLeft();
}
void Object::moveRight(){
    position1.moveRight();
}
