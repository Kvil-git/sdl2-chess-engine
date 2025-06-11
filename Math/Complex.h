#include <iostream>


template <typename ComponentType> struct Complex {
    ComponentType a = 0, b = 0;
    Complex(ComponentType a, ComponentType b){
        this->a = a; this->b = b;
    }
};