/*
 * dog.hpp
 *
 *  Created on: Oct 27, 2023
 *      Author: tavishisharma
 */

#ifndef DOG_HPP
#define DOG_HPP

#include "pet.hpp"

class Dog : public Pet {
public:
    Dog(const std::string& name, float weight); //constructor
    float CalculateFee() const override;
};


#endif /* DOG_HPP_ */
