/*
 * pet.hpp
 *
 *  Created on: Oct 27, 2023
 *      Author: tavishisharma
 *
 */

#ifndef PET_HPP
#define PET_HPP

#include <string>

class Pet {
public:
    Pet(const std::string& name, float weight) : name(name), weight(weight) {} //Constructor
    virtual float CalculateFee() const = 0;
    std::string GetName() const { return name; } // GetName implementation

protected:
    std::string name;
    float weight;
};

#endif /* PET_HPP_ */
