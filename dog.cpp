/*
 * dog.cpp
 *
 *  Created on: Oct 27, 2023
 *      Author: tavishisharma
 */

#include "dog.hpp"

Dog::Dog(const std::string& name, float weight) : Pet(name, weight) {}

float Dog::CalculateFee() const {
    static const float licensingRate = 2.0; // $2/pound for dogs
    return weight * licensingRate;
}

//I couldn't really understand how to do it without cpp files, so I included both hpp and cpp files for dog class
