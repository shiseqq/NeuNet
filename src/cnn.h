#ifndef _CNN_H
#define _CNN_H
#include <python3.6/Python.h>
#include <string>

using namespace std;

void teach();
int analysis(std::string, PyObject*&);
void startcnn(PyObject*&);

#endif