#include "print.h"

// Copy elision : https://en.wikipedia.org/wiki/Copy_elision

class MoveTest
{
public:

    MoveTest();
    MoveTest(const MoveTest &test);
    MoveTest& operator=(const MoveTest &test);
    MoveTest(MoveTest &&test);
    MoveTest& operator =(MoveTest &&test);
    ~MoveTest();

    void run();
};

MoveTest::MoveTest()
{
    print("%p : constructor", this);
}

MoveTest::MoveTest(const MoveTest &test)
{
    print("%p : copy constructor", this);
}

MoveTest& MoveTest::operator=(const MoveTest &test)
{
    print("%p : assignement constructor", this);
    return *this;
}

MoveTest::MoveTest(MoveTest &&test)
{
    print("%p : move constructor", this);
}

MoveTest& MoveTest::operator =(MoveTest &&test)
{
    print("%p : move assignement", this);
    return *this;
}

MoveTest::~MoveTest()
{
    print("%p : destructor", this);
}

void MoveTest::run()
{
    print("bla");
}

MoveTest create()
{
    MoveTest test;
    return test;
}

int main()
{
    MoveTest test = create();
    test.run();

    return 0;
}


