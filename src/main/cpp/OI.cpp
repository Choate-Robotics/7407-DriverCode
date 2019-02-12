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

    this->buttonIntakeToggle = new frc::JoystickButton(joystick[joystick::intake], keymap::button::intakeToggle);
    this->buttonIntakeTiltUp = new frc::JoystickButton(joystick[joystick::intake], keymap::button::intakeTiltUp);
    this->buttonIntakeTiltDown = new frc::JoystickButton(joystick[joystick::intake], keymap::button::intakeTiltDown);

    this->buttonExtakeHigh = new frc::JoystickButton(joystick[joystick::extake], keymap::button::extakeHigh);
    this->buttonExtakeLow = new frc::JoystickButton(joystick[joystick::extake], keymap::button::extakeLow);
    this->buttonExtakeTiltUp = new frc::JoystickButton(joystick[joystick::extake], keymap::button::extakeTiltUp);
    this->buttonExtakeTiltDown = new frc::JoystickButton(joystick[joystick::extake], keymap::button::extakeTiltDown);
    this->buttonSolenoidsOut = new frc::JoystickButton(joystick[joystick::hatchPanel], keymap::button::hatchPanelOut);
    this->buttonSolenoidsIn = new frc::JoystickButton(joystick[joystick::hatchPanel], keymap::button::hatchPanelIn);

    buttonIntakeToggle->WhenPressed(new command::IntakeToggle);
    buttonSolenoidsOut->WhenPressed(new command::hatchPanelOut);
    buttonSolenoidsIn->WhenPressed(new command::hatchPanelIn);
}
