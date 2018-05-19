#ifndef CLOUD_OBJECT_HPP
#define CLOUD_OBJECT_HPP

#include "BaseObject.hpp"
#include "ScreenSize.hpp"
#include <cstdlib>

class CloudObject: public BaseObject {

public:
    CloudObject(): BaseObject(screenWidth, 50 + rand() % 150) {
        clip = {166, 2, 92, 27};
    }
    ~CloudObject() {}

    void update() {
        xPos -= 2;
    }
};

#endif // CLOUD_OBJECT_HPP
