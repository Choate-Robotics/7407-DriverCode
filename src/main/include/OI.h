#pragma once

#include <frc/Joystick.h>

class OI{

public:
    OI();
    frc::Joystick * joystick[2];
    frc::JoystickButton *buttonIntake;
    frc::JoystickButton *buttonExtakeHigh;
    frc::JoystickButton *buttonExtakeLow;
    
};
