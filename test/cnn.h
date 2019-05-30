#include "../src/cnn.h"
#include <cxxtest/TestSuite.h>
#include <python3.6/Python.h>
class MyTest : public CxxTest::TestSuite {
    PyObject* model;

public:
    void test0()
    {
        Py_Initialize();
        PyRun_SimpleString("import sys");
        PyRun_SimpleString("sys.path.insert(1, \"../src\")");
        startcnn(model);
        TS_ASSERT_EQUALS(analysis("../test/numbers/0.png", model), 0);
    }
    void test2()
    {
        startcnn(model);
        TS_ASSERT_EQUALS(analysis("../test/numbers/2.png", model), 2);
    }
    void test3()
    {
        startcnn(model);
        TS_ASSERT_EQUALS(analysis("../test/numbers/3.png", model), 3);
    }
    void test4()
    {
        startcnn(model);
        TS_ASSERT_EQUALS(analysis("../test/numbers/4.png", model), 4);
    }
    void test5()
    {
        startcnn(model);
        TS_ASSERT_EQUALS(analysis("../test/numbers/5.png", model), 5);
    }
    void test6()
    {
        startcnn(model);
        TS_ASSERT_EQUALS(analysis("../test/numbers/6.png", model), 6);
    }
    void test7()
    {
        startcnn(model);
        TS_ASSERT_EQUALS(analysis("../test/numbers/7.png", model), 7);
    }
    void test8()
    {
        startcnn(model);
        TS_ASSERT_EQUALS(analysis("../test/numbers/8.png", model), 8);
    }
    void test9()
    {
        startcnn(model);
        TS_ASSERT_EQUALS(analysis("../test/numbers/9.png", model), 9);
    }
    void testError()
    {
        startcnn(model);
        TS_ASSERT_EQUALS(analysis("", model), -1);
        Py_Finalize();
    }
};