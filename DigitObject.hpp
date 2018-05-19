#ifndef DIGIT_OBJECT_HPP
#define DIGIT_OBJECT_HPP

#include "BaseObject.hpp"

class DigitObject: public BaseObject {

public:

    DigitObject(int xPos, int yPos): BaseObject(xPos, yPos) {}

    void setValue(int digit) {
        clip = {1293 + 20 * digit, 1, 20, 23};
    }

};

#endif // DIGIT_OBJECT_HPP
