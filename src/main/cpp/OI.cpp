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

    frc::JoystickButton *buttonIntakeToggle = new frc::JoystickButton(joystick[joystick::intake], keymap::button::intakeToggle);
    frc::JoystickButton *buttonIntakeTiltUp = new frc::JoystickButton(joystick[joystick::intake], keymap::button::intakeTiltUp);
    frc::JoystickButton *buttonIntakeTiltDown = new frc::JoystickButton(joystick[joystick::intake], keymap::button::intakeTiltDown);

    frc::JoystickButton *buttonExtakeHigh = new frc::JoystickButton(joystick[joystick::extake], keymap::button::extakeHigh);
    frc::JoystickButton *buttonExtakeLow = new frc::JoystickButton(joystick[joystick::extake], keymap::button::extakeLow);
    frc::JoystickButton *buttonExtakeTiltUp = new frc::JoystickButton(joystick[joystick::extake], keymap::button::extakeTiltUp);
    frc::JoystickButton *buttonExtakeTiltDown = new frc::JoystickButton(joystick[joystick::extake], keymap::button::extakeTiltDown);
    frc::JoystickButton *buttonSolenoidsOut = new frc::JoystickButton(joystick[joystick::extake], keymap::button::hatchPanelOut);
    frc::JoystickButton *buttonSolenoidsIn = new frc::JoystickButton(joystick[joystick::extake], keymap::button::hatchPanelIn);

    buttonIntakeToggle->WhenPressed(new command::IntakeToggle);
}
