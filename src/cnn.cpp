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