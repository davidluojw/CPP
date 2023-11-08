#include <iostream>
#include <memory>
#include "matrix.hpp"


int main()
{
    Matrix m1(3,8);
    Matrix m2(4,8);
    std::cout << "&m1 = " << &m1 << std::endl;
    std::cout << "&m2 = " << &m2 << std::endl;
    std::cout << "m1.data = " << m1.data << std::endl;
    std::cout << "m2.data = " << m2.data << std::endl;
    std::cout << "m1.data.get() = " << m1.data.get() << std::endl;
    std::cout << "m2.data.get() = " << m2.data.get() << std::endl;

    m2 = m1;
    std::cout << "&m1 = " << &m1 << std::endl;
    std::cout << "&m2 = " << &m2 << std::endl;
    std::cout << "m1.data = " << m1.data << std::endl;
    std::cout << "m2.data = " << m2.data << std::endl;
    std::cout << "m1.data.get() = " << m1.data.get() << std::endl;
    std::cout << "m2.data.get() = " << m2.data.get() << std::endl;
   
    m1.setElement(1, 2, 4.5f);
    std::cout << m2.getElement(1,2) << std::endl;

    std::cout << m1 << std::endl;
    std::cout << m2 << std::endl;

    Matrix m3 = m1 + m2;
    std::cout << "&m1 = " << &m1 << std::endl;
    std::cout << "&m2 = " << &m2 << std::endl;
    std::cout << "&m3 = " << &m3 << std::endl;
    std::cout << "m1.data = " << m1.data << std::endl;
    std::cout << "m2.data = " << m2.data << std::endl;
    std::cout << "m3.data = " << m3.data << std::endl;
    std::cout << "m1.data.get() = " << m1.data.get() << std::endl;
    std::cout << "m2.data.get() = " << m2.data.get() << std::endl;
    std::cout << "m3.data.get() = " << m3.data.get() << std::endl;

    Matrix m4 = m1;
    std::cout << "&m1 = " << &m1 << std::endl;
    std::cout << "&m2 = " << &m2 << std::endl;
    std::cout << "&m3 = " << &m3 << std::endl;
    std::cout << "&m4 = " << &m4 << std::endl;
    std::cout << "m1.data = " << m1.data << std::endl;
    std::cout << "m2.data = " << m2.data << std::endl;
    std::cout << "m3.data = " << m3.data << std::endl;
    std::cout << "m4.data = " << m4.data << std::endl;
    std::cout << "m1.data.get() = " << m1.data.get() << std::endl;
    std::cout << "m2.data.get() = " << m2.data.get() << std::endl;
    std::cout << "m3.data.get() = " << m3.data.get() << std::endl;
    std::cout << "m4.data.get() = " << m4.data.get() << std::endl;



    std::cout << m3 << std::endl;
    std::cout << m4 << std::endl;
    


    return 0;
}