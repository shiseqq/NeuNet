#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>

using namespace sf;
using namespace std;

RenderWindow window(VideoMode(1920, 1080), "NueNet", Style::Fullscreen);

void bg()
{
    Texture bg0;
    bg0.loadFromFile("bg/0.gif");
    Texture bg1;
    bg1.loadFromFile("bg/1.gif");
    Texture bg2;
    bg2.loadFromFile("bg/2.gif");
    Texture bg3;
    bg3.loadFromFile("bg/3.gif");
    Texture bg4;
    bg4.loadFromFile("bg/4.gif");
    Texture bg5;
    bg5.loadFromFile("bg/5.gif");
    Texture bg6;
    bg6.loadFromFile("bg/6.gif");
    Texture bg7;
    bg7.loadFromFile("bg/7.gif");
    Texture bg8;
    bg8.loadFromFile("bg/8.gif");
    Texture bg9;
    bg9.loadFromFile("bg/9.gif");
    Texture bg10;
    bg10.loadFromFile("bg/10.gif");
    Texture bg11;
    bg11.loadFromFile("bg/11.gif");
    Texture bg12;
    bg12.loadFromFile("bg/12.gif");
    Texture bg13;
    bg13.loadFromFile("bg/13.gif");
    Texture bg14;
    bg14.loadFromFile("bg/14.gif");
    Texture bg15;
    bg15.loadFromFile("bg/15.gif");
    Sprite sbg0;
    sbg0.setTexture(bg0);
    Sprite sbg1;
    sbg1.setTexture(bg1);
    Sprite sbg2;
    sbg2.setTexture(bg2);
    Sprite sbg3;
    sbg3.setTexture(bg3);
    Sprite sbg4;
    sbg4.setTexture(bg4);
    Sprite sbg5;
    sbg5.setTexture(bg5);
    Sprite sbg6;
    sbg6.setTexture(bg6);
    Sprite sbg7;
    sbg7.setTexture(bg7);
    Sprite sbg8;
    sbg8.setTexture(bg8);
    Sprite sbg9;
    sbg9.setTexture(bg9);
    Sprite sbg10;
    sbg10.setTexture(bg10);
    Sprite sbg11;
    sbg11.setTexture(bg11);
    Sprite sbg12;
    sbg12.setTexture(bg12);
    Sprite sbg13;
    sbg13.setTexture(bg13);
    Sprite sbg14;
    sbg14.setTexture(bg14);
    Sprite sbg15;
    sbg15.setTexture(bg15);
    while (window.isOpen()) {
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            exit(0);
        }
        window.clear();
        window.draw(sbg0);
        window.display();
        this_thread::sleep_for(chrono::milliseconds(60));
        window.draw(sbg1);
        window.display();
        this_thread::sleep_for(chrono::milliseconds(60));
        window.draw(sbg2);
        window.display();
        this_thread::sleep_for(chrono::milliseconds(60));
        window.draw(sbg3);
        window.display();
        this_thread::sleep_for(chrono::milliseconds(60));
        window.draw(sbg4);
        window.display();
        this_thread::sleep_for(chrono::milliseconds(60));
        window.draw(sbg5);
        window.display();
        this_thread::sleep_for(chrono::milliseconds(60));
        window.draw(sbg6);
        window.display();
        this_thread::sleep_for(chrono::milliseconds(60));
        window.draw(sbg7);
        window.display();
        this_thread::sleep_for(chrono::milliseconds(60));
        window.draw(sbg8);
        window.display();
        this_thread::sleep_for(chrono::milliseconds(60));
        window.draw(sbg9);
        window.display();
        this_thread::sleep_for(chrono::milliseconds(60));
        window.draw(sbg10);
        window.display();
        this_thread::sleep_for(chrono::milliseconds(60));
        window.draw(sbg11);
        window.display();
        this_thread::sleep_for(chrono::milliseconds(60));
        window.draw(sbg12);
        window.display();
        this_thread::sleep_for(chrono::milliseconds(60));
        window.draw(sbg13);
        window.display();
        this_thread::sleep_for(chrono::milliseconds(60));
        window.draw(sbg14);
        window.display();
        this_thread::sleep_for(chrono::milliseconds(60));
        window.draw(sbg15);
        window.display();
        this_thread::sleep_for(chrono::milliseconds(60));
        window.display();
    }
}

int main()
{
    while (window.isOpen()) {
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            exit(0);
        }
        window.clear();
        bg();
        window.display();
    }
}