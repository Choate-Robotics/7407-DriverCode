#pragma once

#include <frc/Joystick.h>
#include <frc/buttons/JoystickButton.h>

class OI{

public:
    OI();
    static frc::Joystick * joystick[2];
    static frc::JoystickButton *buttonIntakeToggle;
    static frc::JoystickButton *buttonIntakeTiltDown;
    static frc::JoystickButton *buttonIntakeTiltUp;
    static frc::JoystickButton *buttonHatchRollerIn;
    static frc::JoystickButton *buttonHatchRollerOut;

    static frc::JoystickButton *buttonExtakeStop;
    static frc::JoystickButton *buttonExtakeLow;
    static frc::JoystickButton *buttonExtakeHigh;
    static frc::JoystickButton *buttonExtakeTiltUp;
    static frc::JoystickButton *buttonExtakeTiltDown;
    static frc::JoystickButton *buttonSolenoidsOut;
    static frc::JoystickButton *buttonSolenoidsIn;
    static frc::JoystickButton *buttonClimberFrontToggle;
    static frc::JoystickButton *buttonClimberBackToggle;
};
