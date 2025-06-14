#include "Bat.h"
Bat::Bat(float startX,float startY){//we are using the Bat function from the Bat class
    m_Position.x=startX;
    m_Position.y=startY;

    m_Shape.setSize(sf::Vector2f(150,15));
    m_Shape.setPosition(m_Position);

}

FloatRect Bat::getPosition(){
    return m_Shape.getGlobalBounds();
}

RectangleShape Bat::getShape(){
    return m_Shape;
}

void Bat::moveLeft(){
    m_MovingLeft=true;
}
void Bat::moveRight(){
    m_MovingRight=true;
}

void Bat::stopLeft(){
    m_MovingLeft=false;
}
void Bat::stopRight(){
    m_MovingRight=false;
}

void Bat::update(Time dt){
    //bat without boundary
    // if(m_MovingLeft){
    //     m_Position.x-=m_Speed*dt.asSeconds();
    // }
    // if(m_MovingRight){
    //     m_Position.x+=m_Speed*dt.asSeconds();
    // }

    //bat with boundary
    if (m_MovingLeft && m_Position.x > 0) {
        m_Position.x -= m_Speed * dt.asSeconds();
    }
    if (m_MovingRight && (m_Position.x + m_Shape.getSize().x) < 1920) { // Ensuring right boundary
        m_Position.x += m_Speed * dt.asSeconds();
    }
    m_Shape.setPosition(m_Position);
}