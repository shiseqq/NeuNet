#include "cnn.h"
#include <python3.6/Python.h>

using namespace std;

int main()
{
    Py_Initialize();
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("import os");
    PyRun_SimpleString("sys.path.insert(1, \"../src\")");
    Py_Finalize();
    return 0;
}