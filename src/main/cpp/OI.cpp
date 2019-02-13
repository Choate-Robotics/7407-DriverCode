#include "OI.h"
#include <frc/Joystick.h>
#include <frc/buttons/JoystickButton.h>
#include "RobotMap.h"
#include "commands/hatchPanel.h"
#include "commands/drivetrain.h"
#include "commands/conveyor.h"
#include "commands/extake.h"
#include "commands/intake.h"

frc::Joystick* OI::joystick[2] = {0}; 
frc::JoystickButton* OI::buttonIntakeToggle = 0;
frc::JoystickButton* OI::buttonIntakeTiltUp = 0;
frc::JoystickButton* OI::buttonIntakeTiltDown = 0;

frc::JoystickButton* OI::buttonExtakeHigh = 0;
frc::JoystickButton* OI::buttonExtakeLow = 0;
frc::JoystickButton* OI::buttonExtakeTiltUp = 0;
frc::JoystickButton* OI::buttonExtakeTiltDown = 0;
frc::JoystickButton* OI::buttonSolenoidsOut = 0;
frc::JoystickButton* OI::buttonSolenoidsIn = 0;

OI::OI()
{
    using namespace RobotMap;
    OI::joystick[PRIMARY_JOYSTICK] = new frc::Joystick{joystick::portPrimary};
    OI::joystick[SECONDARY_JOYSTICK] = new frc::Joystick{joystick::portSecondary};

    OI::buttonIntakeToggle = new frc::JoystickButton(joystick[joystick::intake], keymap::button::intakeToggle);
    OI::buttonIntakeTiltUp = new frc::JoystickButton(joystick[joystick::intake], keymap::button::intakeTiltUp);
    OI::buttonIntakeTiltDown = new frc::JoystickButton(joystick[joystick::intake], keymap::button::intakeTiltDown);

    OI::buttonExtakeHigh = new frc::JoystickButton(joystick[joystick::extake], keymap::button::extakeHigh);
    OI::buttonExtakeLow = new frc::JoystickButton(joystick[joystick::extake], keymap::button::extakeLow);
    OI::buttonExtakeTiltUp = new frc::JoystickButton(joystick[joystick::extake], keymap::button::extakeTiltUp);
    OI::buttonExtakeTiltDown = new frc::JoystickButton(joystick[joystick::extake], keymap::button::extakeTiltDown);
    OI::buttonSolenoidsOut = new frc::JoystickButton(joystick[joystick::hatchPanel], keymap::button::hatchPanelOut);
    OI::buttonSolenoidsIn = new frc::JoystickButton(joystick[joystick::hatchPanel], keymap::button::hatchPanelIn);

    buttonIntakeToggle->WhenPressed(new command::IntakeToggle);
    buttonSolenoidsOut->WhenPressed(new command::hatchPanelOut);
    buttonSolenoidsIn->WhenPressed(new command::hatchPanelIn);
}
