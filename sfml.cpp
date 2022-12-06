#include <SFML/Graphics.hpp>
#include <iostream>

#include "physics.hpp"
#include "stuff.hpp"


int main(){
    // w window;
    window.setFramerateLimit(30);
    // window.setKeyRepeatEnabled(true);

    sf::RectangleShape mb;

    ball cue;

    ball one;


    cue.setpos(window.getSize().x/2, window.getSize().y/2);

    one.setcol(sf::Color::Yellow);
    one.setpos((int)window.getSize().x*2/3, window.getSize().y/2);


    while (window.isOpen()){

        mb.setPosition(sf::Mouse::getPosition().x-200, window.getSize().y/2);
        cue.xf = cue.getpos().x;



        cue.pi = cue.mass * cue.vix; 
        one.pi = one.mass * one.vix;

        cue.pf = cue.mass * cue.vfx;
        one.pf = one.mass * one.vfx; 


        if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
            main();
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            window.close();
        }


        if ( abs(cue.vfx > 0) ){
            t++;
            cue.vfx = cue.vix / t;

        } else {
            t = 0; 
            cue.vix = 0;
            cue.vfx = 0; 
            cue.ax = 0; 
        }


        if ((sf::Mouse::isButtonPressed(sf::Mouse::Left)) ){
            cue.vix = 100;
            // cue.ismoving = true;
            cue.ax = forceoffriction;
            // cue.xi = cue.xf;
        } else if (abs( (int)cue.vfx ) == 0){
            cue.vfx = 0;
        }
        

        one.b.setFillColor(sf::Color::Red);
        one.b.setPosition(one.getpos());
        // if ( one.b.getGlobalBounds().intersects(cue.b.getGlobalBounds())){
        //     one.ismoving = true;
        //     one.vfx = cue.vfx;
        // }


        sf::Event event;
        while (window.pollEvent(event)){

            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();

        std::cout << one.pf << " " << cue.pf << std::endl;
        // std::cout<< cue.xi << " " << (int)cue.xf << "moving? " <<cue.moving << "t: " << t << " v: " << cue.vfx << " a: " << cue.ax << std::endl;
        
        
        cue.live();
        one.live();       

        window.display();
    }

    return 0;
}
