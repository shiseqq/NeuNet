#include "cnn.h"
#include "gui.h"
#include "screenans.h"
#include <SFML/Graphics.hpp>
#include <chrono>
#include <iostream>
#include <python3.6/Python.h>
#include <string>
#include <thread>

using namespace std;
using namespace sf;

RenderWindow window(VideoMode(1640, 1050), "NueNet");
int t;
string s;

int main()
{
    Py_Initialize();
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("import os");
    PyRun_SimpleString("sys.path.insert(1, \"../src\")");
    Texture bg0;
    Sprite bg;
    Font arial;
    arial.loadFromFile("../texture/arial.ttf");
    Text t1("Press ESC for exit", arial, 30);
    t1.setFillColor(Color(173, 255, 47));
    t1.setPosition(100, 930);
    t1.setOutlineThickness(1);
    bg0.loadFromFile("../texture/FS_30.jpg");
    bg.setTexture(bg0);
    Texture but0;
    Sprite button1;
    Event event;
    while (window.isOpen()) {
        Text t2("Open folder", arial, 30);
        t2.setFillColor(Color(173, 255, 47));
        t2.setPosition(
                window.getSize().x / 2 - 80, window.getSize().y / 2 - 150);
        t2.setOutlineThickness(1);
        but0.loadFromFile("../texture/button.png");
        button1.setTexture(but0);
        button1.setPosition(
                window.getSize().x / 2 - but0.getSize().x / 2,
                window.getSize().y / 2 - 200);
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            exit(0);
        }
        if (Mouse::isButtonPressed(Mouse::Left)
            && IntRect(678, 350, but0.getSize().x, but0.getSize().y)
                       .contains(Mouse::getPosition(window))) {
            window.clear();
            but0.loadFromFile("../texture/newbutton.png");
            button1.setTexture(but0);
            button1.setPosition(
                    window.getSize().x / 2 - but0.getSize().x / 2,
                    window.getSize().y / 2 - 195);
            t2.setCharacterSize(26);
            t2.setPosition(
                    window.getSize().x / 2 - 75, window.getSize().y / 2 - 150);
            window.draw(bg);
            window.draw(button1);
            window.draw(t1);
            window.draw(t2);
            window.display();
            this_thread::sleep_for(chrono::milliseconds(80));
            s = selectfile();
            t = analysis(s);
            screenans(&window, t);
        }
        window.clear();
        window.draw(bg);
        window.draw(button1);
        window.draw(t1);
        window.draw(t2);
        window.display();
    }
    Py_Finalize();
    return 0;
}