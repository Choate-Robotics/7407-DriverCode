#pragma once

#include <frc/Joystick.h>
#include <frc/buttons/JoystickButton.h>

class OI{

public:
    OI();
    static frc::Joystick * joystick[2];
};
