#include <iostream>

#include "Valerie.hpp"

using namespace std;

// Error during + operator on vectors with reserved size and without reserved size.

int main()
{
    Jamn::Valerie<double> v;

    v.reserv(6);

    v.pushBack(1.1);
    v.pushBack(3.3);
    v.pushBack(2.2);
    v.pushBack(4.4);

    // v.pushBack(5.5);

    std::cout << v.isFull() << std::endl;
    std::cout << v.isEmpty() << std::endl;

    v.sort();

    cout << v.retSize() << endl;

    v.remove(1);

    cout << v.retSize() << endl;

    for (std::size_t i = 0; i < v.retSize(); i++)
    {
        cout << v.pushOut(i) << endl;
    }

    v = { 5.5, 4.4, 3.3, 2.2, 1.1 };

    Jamn::Valerie<double> v2;

    v2.pushBack(3.5);
    v2.pushBack(7.4);

    cout << v2.retSize() << endl;

    for (std::size_t i = 0; i < v2.retSize(); i++)
    {
        cout << v2[i] << endl;
    }
    
    // ---------------------------    
    
    v2 = (v + v2);

    // ---------------------------

    cout << v2.retSize() << endl;

    v2.replace(4, 8.8);

    for (std::size_t i = 0; i < v2.retSize(); i++)
    {
        cout << v2.pushOut(i) << endl;
    }

    Jamn::Valerie<double> v3;

    v3 = { 4.5, 5.6, 6.7 };

    std::cout << v3.retSize() << std::endl;

    for (std::size_t i = 0; i < v3.retSize(); i++)
    {
        std::cout << v3.pushOut(i) << std::endl;
    }
    
    v3.clear();
    std::cout << v3.retSize() << std::endl;

    std::cout << v2.at(100) << std::endl;

    return 0;
}