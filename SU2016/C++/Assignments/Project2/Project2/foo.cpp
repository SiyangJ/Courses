#include "Multiset.h"
#include <iostream>
#include <cassert>
using namespace std;

void test()
{
    Multiset sms;
    assert(sms.insert("cumin"));
    assert(sms.insert("turmeric"));
    assert(sms.insert("cumin"));
    assert(sms.insert("coriander"));
    assert(sms.insert("cumin"));
    assert(sms.insert("turmeric"));
    assert(sms.size() == 6  &&  sms.uniqueSize() == 3);
    assert(sms.count("turmeric") == 2);
    assert(sms.count("cumin") == 3);
    assert(sms.count("coriander") == 1);
    assert(sms.count("cardamom") == 0);
}

int main()
{
    test();
    cout << "Passed all tests" << endl;
}
