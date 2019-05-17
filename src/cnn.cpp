#include "cnn.h"

void teach()
{
    Py_Initialize();
    PyObject *pArgs, *pModule, *pFunc, *pName;
    pName = PyUnicode_FromString("teach_сnn");
    pModule = PyImport_Import(pName);
    Py_DECREF(pName);
    if (pModule) {
        pFunc = PyObject_GetAttrString(pModule, "teach");
        if (pFunc) {
            pArgs = PyTuple_New(0);
            PyObject_CallObject(pFunc, pArgs);
        }
    }
    Py_DECREF(pModule);
    Py_DECREF(pArgs);
    Py_DECREF(pFunc);
    Py_Finalize();
}

int analysis(std::string str)
{
    Py_Initialize();
    PyObject *pName, *pModule, *pFunc, *pValue, *pArgs;
    pName = PyUnicode_FromString("image_analysis");
    pModule = PyImport_Import(pName);
    Py_DECREF(pName);
    if (pModule) {
        pFunc = PyObject_GetAttrString(pModule, "analysis");
        pArgs = PyTuple_New(1);
        PyTuple_SetItem(pArgs, 0, PyUnicode_FromString(str.c_str()));
        pValue = PyObject_CallObject(pFunc, pArgs);
        return PyLong_AsLong(pValue);
    }
    Py_Finalize();
    return -1;
}

void startcnn(PyObject*& model)
{
    Py_Initialize();
    PyObject *pName, *pModule, *pFunc, *pArgs;
    pName = PyUnicode_FromString("startcnn");
    pModule = PyImport_Import(pName);
    Py_DECREF(pName);
    if (pModule) {
        pFunc = PyObject_GetAttrString(pModule, "startcnn");
        pArgs = PyTuple_New(0);
        model = PyObject_CallObject(pFunc, pArgs);
    }
}