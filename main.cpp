#include <iostream>

#include "Vector.hpp"

using namespace std;

int main()
{    
    Jamn::Valerie<double> v;

    v.pushBack(1.1);
    v.pushBack(3.3);
    v.pushBack(2.2);
    v.pushBack(4.4);

    v.sort();

    cout << v.retSize() << endl;

    v.del(1);

    cout << v.retSize() << endl;

    for (int i = 0; i < v.retSize(); i++)
    {
        cout << v.pushOut(i) << endl;
    }

    Jamn::Valerie<double> v2;

    v2.pushBack(3.5);
    v2.pushBack(7.4);

    cout << v2.retSize() << endl;

    for (int i = 0; i < v2.retSize(); i++)
    {
        cout << v2.pushOut(i) << endl;
    }
    
    // ---------------------------    
    
    v2 = (v + v2);

    // ---------------------------

    cout << v2.retSize() << endl;

    v2.replace(4, 8.8);

    for (int i = 0; i < v2.retSize(); i++)
    {
        cout << v2.pushOut(i) << endl;
    }

    Jamn::Valerie<double> v3;

    v3 = { 4.5, 5.6, 6.7 };

    std::cout << v3.retSize() << std::endl;

    for (int i = 0; i < v3.retSize(); i++)
    {
        std::cout << v3.pushOut(i) << std::endl;
    }
    
    return 0;
}