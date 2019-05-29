#ifndef _SCREENANS_H
#define _SCREENANS_H
#include "cnn.h"
#include "gui.h"
#include <SFML/Graphics.hpp>
#include <chrono>
#include <python3.6/Python.h>
#include <string>
#include <thread>

using namespace std;
using namespace sf;

void screenans(RenderWindow*, int, string, PyObject*&);

#endif