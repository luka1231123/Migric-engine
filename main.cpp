#include<SFML/Graphics.hpp>
#include<cmath>
#include<iostream>
using namespace sf;

int main(){
    RenderWindow window(VideoMode(1500, 800), "lgm");
    CircleShape c1(10);
    c1.setOrigin(10, 10);
    c1.setFillColor(Color::Yellow);
    c1.setPosition(Vector2f(750, 400));
    CircleShape c2(20);
    c2.setOrigin(20, 20);
    c2.setFillColor(Color::Blue);
    c2.setPosition(Vector2f(850, 600));
    float mass = 2500;
    float vx=3,vy=0; // Initial velocity of Blue sprite
    sf::VertexArray vertices;
    while(window.isOpen()){
        c2.setFillColor(Color::Blue);
        Event event;
        while(window.pollEvent(event)){
            if(event.type == Event::Closed){
                window.close();
            }
        }
        if(c2.getPosition().x>1500 || c2.getPosition().y>800 || c2.getPosition().x<0 || c2.getPosition().y<0){
            std::cout<<"you went out you dumb dumb";
            window.close();
        }
        if(Mouse::isButtonPressed(Mouse::Left)){
            c1.setPosition(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
        }
        float a = c1.getPosition().x - c2.getPosition().x;
        float b = c1.getPosition().y - c2.getPosition().y;
        float acc = (mass)/(a*a + b*b);
        float accx = (acc*a)/(sqrt(a*a + b*b));
        float accy = (acc*b)/(sqrt(a*a + b*b));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            accy=accy-0.05;
            c2.setFillColor(Color::Red);

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            accy=accy+0.05;
            c2.setFillColor(Color::Red) ;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            accx=accx-0.05;
            c2.setFillColor(Color::Red);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            accx=accx+0.05;
            c2.setFillColor(Color::Red);
        }
        vertices.append(Vertex(Vector2f(c2.getPosition().x, c2.getPosition().y)));
        vx += accx;
        vy += accy;
        c2.move(vx, vy);
        window.clear();
        window.draw(vertices);
        window.draw(c1);
        window.draw(c2);
        window.display();

    }
        return 0;
}
