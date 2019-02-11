#include "OI.h"
#include <frc/Joystick.h>
#include <frc/buttons/JoystickButton.h>
#include "RobotMap.h"
#include "commands/hatchPanel.h"
#include "commands/drivetrain.h"
#include "commands/conveyor.h"
#include "commands/extake.h"
#include "commands/intake.h"

OI::OI()
{
    using namespace RobotMap;
    this->joystick[PRIMARY_JOYSTICK] = new frc::Joystick{joystick::portPrimary};
    this->joystick[SECONDARY_JOYSTICK] = new frc::Joystick{joystick::portSecondary};

    frc::JoystickButton *buttonIntake = new frc::JoystickButton(joystick[joystick::intake], keymap::button::intakeToggle);
    frc::JoystickButton *buttonExtakeHigh = new frc::JoystickButton(joystick[joystick::extake], keymap::button::extakeHigh);
    frc::JoystickButton *buttonExtakeLow = new frc::JoystickButton(joystick[joystick::extake], keymap::button::extakeLow);

    buttonIntake->WhenPressed(new command::IntakeToggle);
}
