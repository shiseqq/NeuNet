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

int main()
{
    string s;
    Texture bg0, but0, but1;
    Py_Initialize();
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("import os");
    PyRun_SimpleString("sys.path.insert(1, \"../src\")");
    Sprite bg, button0, button1;
    Font arial;
    arial.loadFromFile("../texture/arial.ttf");
    Text teaching("Teaching process", arial, 60);
    teaching.setFillColor(Color(173, 255, 47));
    teaching.setOutlineThickness(1);
    teaching.setPosition(70, 900);
    Text t1("Press ESC for exit", arial, 30);
    t1.setFillColor(Color(173, 255, 47));
    t1.setPosition(100, 930);
    t1.setOutlineThickness(1);
    bg0.loadFromFile("../texture/FS_30.jpg");
    bg.setTexture(bg0);
    PyObject* model;
    startcnn(model);
    while (window.isOpen()) {
        Text t2("Open folder", arial, 30);
        t2.setFillColor(Color(173, 255, 47));
        t2.setPosition(
                window.getSize().x / 2 - 80, window.getSize().y / 2 - 150);
        t2.setOutlineThickness(1);
        Text t3("Teach CNN", arial, 30);
        t3.setFillColor(Color(173, 255, 47));
        t3.setPosition(
                window.getSize().x / 2 - 80, window.getSize().y / 2 + 50);
        t3.setOutlineThickness(1);
        but0.loadFromFile("../texture/button.png");
        button0.setTexture(but0);
        button0.setPosition(
                window.getSize().x / 2 - but0.getSize().x / 2,
                window.getSize().y / 2 - 200);
        but1.loadFromFile("../texture/button.png");
        button1.setTexture(but1);
        button1.setPosition(
                window.getSize().x / 2 - but1.getSize().x / 2,
                window.getSize().y / 2);
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            exit(0);
        }
        if (Mouse::isButtonPressed(Mouse::Left)
            && button0.getGlobalBounds().contains(
                       Mouse::getPosition(window).x,
                       Mouse::getPosition(window).y)) {
            window.clear();
            but0.loadFromFile("../texture/newbutton.png");
            button0.setTexture(but0);
            button0.setPosition(
                    window.getSize().x / 2 - but0.getSize().x / 2,
                    window.getSize().y / 2 - 195);
            t2.setCharacterSize(26);
            t2.setPosition(
                    window.getSize().x / 2 - 75, window.getSize().y / 2 - 150);
            window.draw(bg);
            window.draw(button0);
            window.draw(button1);
            window.draw(t1);
            window.draw(t2);
            window.draw(t3);
            window.display();
            this_thread::sleep_for(chrono::milliseconds(80));
            s = selectfile();
            if (s.size() > 0) {
                int t;
                t = analysis(s, model);
                screenans(&window, t, s, model);
                startcnn(model);
            }
        }
        if (Mouse::isButtonPressed(Mouse::Left)
            && button1.getGlobalBounds().contains(
                       Mouse::getPosition(window).x,
                       Mouse::getPosition(window).y)) {
            window.clear();
            but1.loadFromFile("../texture/newbutton.png");
            button1.setTexture(but1);
            button1.setPosition(
                    window.getSize().x / 2 - but1.getSize().x / 2,
                    window.getSize().y / 2 + 5);
            t3.setCharacterSize(26);
            t3.setPosition(
                    window.getSize().x / 2 - 75, window.getSize().y / 2 + 50);
            window.draw(bg);
            window.draw(button0);
            window.draw(button1);
            window.draw(t1);
            window.draw(t2);
            window.draw(t3);
            window.display();
            this_thread::sleep_for(chrono::milliseconds(80));
            window.clear();
            window.draw(bg);
            window.draw(teaching);
            window.display();
            teach();
        }
        window.clear();
        window.draw(bg);
        window.draw(button0);
        window.draw(button1);
        window.draw(t1);
        window.draw(t2);
        window.draw(t3);
        window.display();
    }
    Py_Finalize();
    return 0;
}