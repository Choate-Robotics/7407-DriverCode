#pragma once

#include <frc/Joystick.h>

class OI{

public:
    OI();
    OI(int);
    frc::Joystick * joystick[2];
};
