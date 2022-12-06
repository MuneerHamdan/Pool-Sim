#include <SFML/Graphics.hpp>
// class w{
//     public:
//     sf::RenderWindow window;
//     w(){
//          create();
//     }
//     void create(){
//         sf::RenderWindow window(sf::VideoMode(2000, 1000), "SFML window");
//     }
//     bool getisopen(){
//         if (window.isOpen()){
//             return true;
//         } else {
//             return false;
//         }
//     }
//     void cls(){
//         window.close();
//     }
//     bool polle(){
//         if (window.pollEvent()){
//             return true;
//         }
//     }

// };

sf::RenderWindow window(sf::VideoMode(2560, 1000), "SFML window");

class ball {
    public: 
    
    sf::CircleShape c;
    sf::RectangleShape b;
    
    
    double mass = 2;

    bool ismoving = false;

    double vix = 0.0;
    double vfx = 0.0;
    double viy = 0.0;
    double vfy = 0.0;
    double ax = 0.0;
    double ay = 0.0;
    double xi = 0.0;
    double xf = 0.0; 
    double yi = 0.0;
    double yf = 0.0; 

    double pi = 0.0;
    double pf = 0.0;


    ball(){
        c.setFillColor(sf::Color::White);
        c.setRadius(40);
        
        b.setSize(sf::Vector2f(2 * c.getRadius(), 2 * c.getRadius()));
        b.setFillColor(sf::Color::Transparent);
    }
    void setcol(sf::Color col){
        c.setFillColor(col);
    }
    sf::Vector2f getpos(){
        return c.getPosition();
    }
    void setpos(int x, int y){
        c.setPosition(x, y);
    }
    sf::FloatRect getglobal(){
        return c.getGlobalBounds();
    }
    void moveball(){
        c.move(vfx, vfy);
    }

    void live(){
        b.setPosition(c.getPosition().x, c.getPosition().y);
        moveball();
        window.draw(c);
    }
};

