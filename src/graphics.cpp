#include <SFML/Graphics.hpp>
#include <chrono>
#include <iostream>
#include <thread>

using namespace sf;
using namespace std;

RenderWindow window(VideoMode(1920, 1080), "NueNet", Style::Fullscreen);

int main()
{
    Font font;
    font.loadFromFile("../texture/arial.ttf");
    Text t1("Press ESC for exit", font, 30);
    t1.setFillColor(Color(173, 255, 47));
    t1.setPosition(100, 930);
    t1.setOutlineThickness(1);
    Text but1txt("Select image", font, 50);
    but1txt.setFillColor(Color::White);
    but1txt.setPosition(
            window.getSize().x / 2 - 150, window.getSize().y / 2 - 165);
    Texture bg0;
    bg0.loadFromFile("../texture/FS_30.jpg");
    Sprite bg;
    bg.setTexture(bg0);
    Texture but0;
    but0.loadFromFile("button.png");
    Sprite button1;
    button1.setTexture(but0);
    button1.setPosition(
            window.getSize().x / 2 - but0.getSize().x / 2,
            window.getSize().y / 2 - 200);
    while (window.isOpen()) {
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            exit(0);
        }
        if (Mouse::isButtonPressed(Mouse::Left)
            && IntRect(678, 350, but0.getSize().x, but0.getSize().y)
                       .contains(Mouse::getPosition(window))) {
            exit(0);
        }
        window.clear();
        window.draw(bg);
        window.draw(button1);
        window.draw(but1txt);
        window.draw(t1);
        window.display();
    }
}