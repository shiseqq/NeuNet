#include "gui.h"

string selectfile()
{
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.argv = ['']");
    PyObject *pArgs, *pModule, *pFunc, *pName, *pValue;
    pName = PyUnicode_FromString("gui");
    pModule = PyImport_Import(pName);
    Py_XDECREF(pName);
    if (pModule) {
        pFunc = PyObject_GetAttrString(pModule, "selectfile");
        if (pFunc) {
            pArgs = PyTuple_New(0);
            pValue = PyObject_CallObject(pFunc, pArgs);
        }
    }
    Py_XDECREF(pModule);
    Py_XDECREF(pArgs);
    Py_XDECREF(pFunc);
    if (PyUnicode_Check(pValue)) {
        return (char*)PyUnicode_DATA(pValue);
    } else {
        return "";
    }
}

int wininp()
{
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.argv = ['']");
    PyObject *pArgs, *pModule, *pFunc, *pName, *pValue;
    pName = PyUnicode_FromString("gui");
    pModule = PyImport_Import(pName);
    Py_XDECREF(pName);
    if (pModule) {
        pFunc = PyObject_GetAttrString(pModule, "wininp");
        if (pFunc) {
            pArgs = PyTuple_New(0);
            pValue = PyObject_CallObject(pFunc, pArgs);
        }
    }
    Py_XDECREF(pModule);
    Py_XDECREF(pArgs);
    Py_XDECREF(pFunc);
    return PyLong_AsLong(pValue);
}