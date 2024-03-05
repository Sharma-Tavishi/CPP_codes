/*
 * cat.hpp
 *
 *  Created on: Oct 27, 2023
 *      Author: tavishisharma
 */

#ifndef CAT_HPP
#define CAT_HPP

#include "pet.hpp"

class Cat : public Pet {
public:
    Cat(const std::string& name, float weight); //Contructor
    float CalculateFee() const override;
};

#endif /* CAT_HPP_ */
