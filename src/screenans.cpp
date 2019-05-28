#include "screenans.h"

void screenans(RenderWindow* window, int t)
{
    Texture bg0;
    Sprite bg;
    Texture bgans0;
    Sprite bgans;
    Font arial;
    arial.loadFromFile("../texture/arial.ttf");
    char ans = '0' + t;
    Text answ(ans, arial, 900);
    answ.setPosition((*window).getSize().x / 2 - 250, -50);
    answ.setFillColor(Color::White);
    bg0.loadFromFile("../texture/FS_30.jpg");
    bg.setTexture(bg0);
    bgans0.loadFromFile("../texture/bgforans1.png");
    bgans.setTexture(bgans0);
    bgans.setPosition(
            (*window).getSize().x / 2 - bgans0.getSize().x / 2,
            (*window).getSize().y / 2 - bgans0.getSize().y / 2);
    arial.loadFromFile("../texture/arial.ttf");
    Text t1("Press ESC for exit", arial, 30);
    t1.setFillColor(Color(173, 255, 47));
    t1.setPosition(100, 930);
    t1.setOutlineThickness(1);
    while ((*window).isOpen()) {
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            exit(0);
        }
        (*window).clear();
        (*window).draw(bg);
        (*window).draw(bgans);
        (*window).draw(answ);
        (*window).draw(t1);
        (*window).display();
    }
}