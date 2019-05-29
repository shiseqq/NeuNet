#include "screenans.h"

void screenans(RenderWindow* window, int t, string s, PyObject*& model)
{
    Texture bg0, bgans0, b0, b1;
    Sprite bg, bgans, sb0, sb1;
    Font arial;
    arial.loadFromFile("../texture/arial.ttf");
    char ans = '0' + t;
    Text answ(ans, arial, 800);
    answ.setPosition((*window).getSize().x / 2 - 650, -50);
    answ.setFillColor(Color::White);
    bg0.loadFromFile("../texture/FS_30.jpg");
    bg.setTexture(bg0);
    bgans0.loadFromFile("../texture/bgforans1.png");
    bgans.setTexture(bgans0);
    bgans.setPosition(50, 50);
    arial.loadFromFile("../texture/arial.ttf");
    Text t1("Press ESC for exit", arial, 30);
    t1.setFillColor(Color(173, 255, 47));
    t1.setPosition(100, 930);
    t1.setOutlineThickness(1);
    while ((*window).isOpen()) {
        b0.loadFromFile("../texture/button.png");
        sb0.setTexture(b0);
        sb0.setPosition(
                (*window).getSize().x / 2 - b0.getSize().x / 2 + 400,
                (*window).getSize().y / 2 - 400);
        b1.loadFromFile("../texture/button.png");
        sb1.setTexture(b1);
        sb1.setPosition(
                (*window).getSize().x / 2 - b1.getSize().x / 2 + 400,
                (*window).getSize().y / 2 - 200);
        Text menu("Menu", arial, 30);
        menu.setFillColor(Color(173, 255, 47));
        menu.setOutlineThickness(1);
        menu.setPosition(
                (*window).getSize().x / 2 + 370,
                (*window).getSize().y / 2 - 350);
        Text wrong("Wrong answer!", arial, 30);
        wrong.setFillColor(Color(173, 255, 47));
        wrong.setOutlineThickness(1);
        wrong.setPosition(
                (*window).getSize().x / 2 + 310,
                (*window).getSize().y / 2 - 150);
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            exit(0);
        }
        if (Mouse::isButtonPressed(Mouse::Left)
            && sb0.getGlobalBounds().contains(
                       Mouse::getPosition(*window).x,
                       Mouse::getPosition(*window).y)) {
            (*window).clear();
            b0.loadFromFile("../texture/newbutton.png");
            sb0.setTexture(b0);
            sb0.setPosition(
                    (*window).getSize().x / 2 - b0.getSize().x / 2 + 400,
                    (*window).getSize().y / 2 - 395);
            menu.setCharacterSize(26);
            menu.setPosition(
                    (*window).getSize().x / 2 + 365,
                    (*window).getSize().y / 2 - 350);
            (*window).draw(bg);
            (*window).draw(bgans);
            (*window).draw(answ);
            (*window).draw(sb0);
            (*window).draw(menu);
            (*window).draw(sb1);
            (*window).draw(wrong);
            (*window).draw(t1);
            (*window).display();
            this_thread::sleep_for(chrono::milliseconds(80));
            return;
        }
        if (Mouse::isButtonPressed(Mouse::Left)
            && sb1.getGlobalBounds().contains(
                       Mouse::getPosition(*window).x,
                       Mouse::getPosition(*window).y)) {
            (*window).clear();
            b1.loadFromFile("../texture/newbutton.png");
            sb1.setTexture(b1);
            sb1.setPosition(
                    (*window).getSize().x / 2 - b1.getSize().x / 2 + 400,
                    (*window).getSize().y / 2 - 195);
            wrong.setCharacterSize(26);
            wrong.setPosition(
                    (*window).getSize().x / 2 + 305,
                    (*window).getSize().y / 2 - 150);
            (*window).draw(bg);
            (*window).draw(bgans);
            (*window).draw(answ);
            (*window).draw(sb0);
            (*window).draw(menu);
            (*window).draw(sb1);
            (*window).draw(wrong);
            (*window).draw(t1);
            (*window).display();
            this_thread::sleep_for(chrono::milliseconds(80));
            lerarnpicture(s, wininp(), model);
        }
        (*window).clear();
        (*window).draw(bg);
        (*window).draw(bgans);
        (*window).draw(answ);
        (*window).draw(sb0);
        (*window).draw(menu);
        (*window).draw(sb1);
        (*window).draw(wrong);
        (*window).draw(t1);
        (*window).display();
    }
}