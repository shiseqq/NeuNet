#include <SFML/Graphics.hpp>
#include <chrono>
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
    Texture bg0;
    bg0.loadFromFile("../texture/FS_30.jpg");
    Sprite bg;
    bg.setTexture(bg0);
    Texture but0;
    but0.loadFromFile("../texture/button.png");
    Sprite button1;
    button1.setTexture(but0);
    button1.setPosition(
            window.getSize().x / 2 - but0.getSize().x / 2,
            window.getSize().y / 2 - 200);
    while (window.isOpen()) {
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            exit(0);
        }
        window.clear();
        window.draw(bg);
        window.draw(button1);
        window.draw(t1);
        window.display();
    }
}
