#pragma once

#include <frc/Joystick.h>
#include <frc/buttons/JoystickButton.h>

class OI{

public:
    OI();
    frc::Joystick * joystick[2];
    frc::JoystickButton *buttonIntakeToggle;
    frc::JoystickButton *buttonIntakeTiltDown;
    frc::JoystickButton *buttonIntakeTiltUp;

    frc::JoystickButton *buttonExtakeHigh;
    frc::JoystickButton *buttonExtakeLow;
    frc::JoystickButton *buttonExtakeTiltUp;
    frc::JoystickButton *buttonExtakeTiltDown;
    frc::JoystickButton *buttonSolenoidsOut;
    frc::JoystickButton *buttonSolenoidsIn;
};
