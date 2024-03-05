/*
 * cat.cpp
 *
 *  Created on: Oct 27, 2023
 *      Author: tavishisharma
 */

#include "cat.hpp"

Cat::Cat(const std::string& name, float weight) : Pet(name, weight) {}

float Cat::CalculateFee() const {
    static const float licensingRate = 1.5; // $1.50/pound for cats
    return weight * licensingRate;
}
//I couldn't really understand how to do it without cpp files, so I included both hpp and cpp files for cat class
