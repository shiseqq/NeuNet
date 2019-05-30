/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/ErrorPrinter.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestListener.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/TestTracker.h>

int main(int argc, char* argv[])
{
    int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main<CxxTest::ErrorPrinter>(tmp, argc, argv);
    return status;
}
bool suite_MyTest_init = false;
#include "cnn.h"

static MyTest suite_MyTest;

static CxxTest::List Tests_MyTest = {0, 0};
CxxTest::StaticSuiteDescription suiteDescription_MyTest(
        "test/cnn.h", 4, "MyTest", suite_MyTest, Tests_MyTest);

static class TestDescription_suite_MyTest_test0
    : public CxxTest::RealTestDescription {
public:
    TestDescription_suite_MyTest_test0()
        : CxxTest::RealTestDescription(
                  Tests_MyTest, suiteDescription_MyTest, 8, "test0")
    {
    }
    void runTest()
    {
        suite_MyTest.test0();
    }
} testDescription_suite_MyTest_test0;

static class TestDescription_suite_MyTest_test2
    : public CxxTest::RealTestDescription {
public:
    TestDescription_suite_MyTest_test2()
        : CxxTest::RealTestDescription(
                  Tests_MyTest, suiteDescription_MyTest, 16, "test2")
    {
    }
    void runTest()
    {
        suite_MyTest.test2();
    }
} testDescription_suite_MyTest_test2;

static class TestDescription_suite_MyTest_test3
    : public CxxTest::RealTestDescription {
public:
    TestDescription_suite_MyTest_test3()
        : CxxTest::RealTestDescription(
                  Tests_MyTest, suiteDescription_MyTest, 21, "test3")
    {
    }
    void runTest()
    {
        suite_MyTest.test3();
    }
} testDescription_suite_MyTest_test3;

static class TestDescription_suite_MyTest_test4
    : public CxxTest::RealTestDescription {
public:
    TestDescription_suite_MyTest_test4()
        : CxxTest::RealTestDescription(
                  Tests_MyTest, suiteDescription_MyTest, 26, "test4")
    {
    }
    void runTest()
    {
        suite_MyTest.test4();
    }
} testDescription_suite_MyTest_test4;

static class TestDescription_suite_MyTest_test5
    : public CxxTest::RealTestDescription {
public:
    TestDescription_suite_MyTest_test5()
        : CxxTest::RealTestDescription(
                  Tests_MyTest, suiteDescription_MyTest, 31, "test5")
    {
    }
    void runTest()
    {
        suite_MyTest.test5();
    }
} testDescription_suite_MyTest_test5;

static class TestDescription_suite_MyTest_test6
    : public CxxTest::RealTestDescription {
public:
    TestDescription_suite_MyTest_test6()
        : CxxTest::RealTestDescription(
                  Tests_MyTest, suiteDescription_MyTest, 36, "test6")
    {
    }
    void runTest()
    {
        suite_MyTest.test6();
    }
} testDescription_suite_MyTest_test6;

static class TestDescription_suite_MyTest_test7
    : public CxxTest::RealTestDescription {
public:
    TestDescription_suite_MyTest_test7()
        : CxxTest::RealTestDescription(
                  Tests_MyTest, suiteDescription_MyTest, 41, "test7")
    {
    }
    void runTest()
    {
        suite_MyTest.test7();
    }
} testDescription_suite_MyTest_test7;

static class TestDescription_suite_MyTest_test8
    : public CxxTest::RealTestDescription {
public:
    TestDescription_suite_MyTest_test8()
        : CxxTest::RealTestDescription(
                  Tests_MyTest, suiteDescription_MyTest, 46, "test8")
    {
    }
    void runTest()
    {
        suite_MyTest.test8();
    }
} testDescription_suite_MyTest_test8;

static class TestDescription_suite_MyTest_test9
    : public CxxTest::RealTestDescription {
public:
    TestDescription_suite_MyTest_test9()
        : CxxTest::RealTestDescription(
                  Tests_MyTest, suiteDescription_MyTest, 51, "test9")
    {
    }
    void runTest()
    {
        suite_MyTest.test9();
    }
} testDescription_suite_MyTest_test9;

static class TestDescription_suite_MyTest_testError
    : public CxxTest::RealTestDescription {
public:
    TestDescription_suite_MyTest_testError()
        : CxxTest::RealTestDescription(
                  Tests_MyTest, suiteDescription_MyTest, 56, "testError")
    {
    }
    void runTest()
    {
        suite_MyTest.testError();
    }
} testDescription_suite_MyTest_testError;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
