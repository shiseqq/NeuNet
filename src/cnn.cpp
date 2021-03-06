#include "cnn.h"

void teach()
{
    PyObject *pArgs, *pModule, *pFunc, *pName;
    pName = PyUnicode_FromString("teach_сnn");
    pModule = PyImport_Import(pName);
    Py_XDECREF(pName);
    if (pModule) {
        pFunc = PyObject_GetAttrString(pModule, "teach");
        if (pFunc) {
            pArgs = PyTuple_New(0);
            PyObject_CallObject(pFunc, pArgs);
        }
    }
    Py_XDECREF(pModule);
    Py_XDECREF(pArgs);
    Py_XDECREF(pFunc);
}

int analysis(string str, PyObject*& model)
{
    PyObject *pName, *pModule, *pFunc, *pValue, *pArgs;
    pName = PyUnicode_FromString("image_analysis");
    pModule = PyImport_Import(pName);
    Py_XDECREF(pName);
    if (pModule) {
        pFunc = PyObject_GetAttrString(pModule, "analysis");
        pArgs = PyTuple_New(2);
        PyTuple_SetItem(pArgs, 0, PyUnicode_FromString(str.c_str()));
        PyTuple_SetItem(pArgs, 1, model);
        pValue = PyObject_CallObject(pFunc, pArgs);
        Py_XDECREF(pModule);
        Py_XDECREF(pFunc);
        Py_XDECREF(pArgs);
        return PyLong_AsLong(pValue);
    }
    Py_XDECREF(pModule);
    Py_XDECREF(pFunc);
    Py_XDECREF(pArgs);
    return -1;
}

void startcnn(PyObject*& model)
{
    PyObject *pName, *pModule, *pFunc, *pArgs;
    pName = PyUnicode_FromString("startcnn");
    pModule = PyImport_Import(pName);
    Py_XDECREF(pName);
    if (pModule) {
        pFunc = PyObject_GetAttrString(pModule, "startcnn");
        pArgs = PyTuple_New(0);
        model = PyObject_CallObject(pFunc, pArgs);
    }
    Py_XDECREF(pModule);
    Py_XDECREF(pFunc);
    Py_XDECREF(pArgs);
}

void lerarnpicture(string img_path, int target, PyObject*& model)
{
    PyObject *pName, *pModule, *pFunc, *pArgs;
    pName = PyUnicode_FromString("learn_picture");
    pModule = PyImport_Import(pName);
    Py_XDECREF(pName);
    if (pModule) {
        pFunc = PyObject_GetAttrString(pModule, "lerarnpicture");
        pArgs = PyTuple_New(3);
        PyTuple_SetItem(pArgs, 0, PyUnicode_FromString(img_path.c_str()));
        PyTuple_SetItem(pArgs, 1, PyLong_FromLong(target));
        PyTuple_SetItem(pArgs, 2, model);
        PyObject_CallObject(pFunc, pArgs);
    }
    Py_XDECREF(pModule);
    Py_XDECREF(pFunc);
    Py_XDECREF(pArgs);
}