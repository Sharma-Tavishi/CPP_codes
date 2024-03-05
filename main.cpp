//============================================================================
// Name        : A9.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include "pet.hpp"
#include "dog.hpp"
#include "cat.hpp"
#include "cat.cpp"
#include "dog.cpp"

int main() {
    std::vector<Pet*> pvec;

    Dog bob("Bob", 65);
    Dog stan("Stan", 37);
    Cat tom("Tom", 12);

    pvec.push_back(&bob);
    pvec.push_back(&stan);
    pvec.push_back(&tom);

    //same code that was given in the assignment details
    float total_fee = 0.0;
    for (int i = 0; i < pvec.size(); i++) {
        std::cout << pvec[i]->GetName() << ' ' << pvec[i]->CalculateFee() << std::endl;
        total_fee += pvec[i]->CalculateFee();
    }
    std::cout << "total licensing fee = " << total_fee << std::endl;

    return 0;
}
//adding comments were difficult in this code
//I couldn't write this code upto my potential, I was sick, but I tried my best

