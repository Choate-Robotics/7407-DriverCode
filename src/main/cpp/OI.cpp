#include "OI.h"
#include <frc/Joystick.h>
#include <frc/buttons/JoystickButton.h>
#include "RobotMap.h"
#include "commands/hatchPanel.h"
#include "commands/drivetrain.h"
#include "commands/conveyor.h"
#include "commands/extake.h"
#include "commands/intake.h"

frc::Joystick *OI::joystick[2] = {0};
frc::JoystickButton *OI::buttonIntakeToggle = 0;
frc::JoystickButton *OI::buttonIntakeTiltUp = 0;
frc::JoystickButton *OI::buttonIntakeTiltDown = 0;

frc::JoystickButton *OI::buttonExtakeHigh = 0;
frc::JoystickButton *OI::buttonExtakeLow = 0;
frc::JoystickButton *OI::buttonExtakeTiltUp = 0;
frc::JoystickButton *OI::buttonExtakeTiltDown = 0;
frc::JoystickButton *OI::buttonSolenoidsOut = 0;
frc::JoystickButton *OI::buttonSolenoidsIn = 0;

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

    buttonExtakeHigh->WhenPressed(new command::ExtakeOutHigh);
    buttonExtakeHigh->WhenReleased(new command::ExtakeStop);

    buttonExtakeLow->WhenPressed(new command::ExtakeOutLow);
    buttonExtakeLow->WhenReleased(new command::ExtakeStop);

    buttonExtakeTiltDown->WhenPressed(new command::ExtakeTiltDown);
    buttonExtakeTiltDown->WhenReleased(new command::ExtakeTiltStop);

    buttonExtakeTiltUp->WhenPressed(new command::ExtakeTiltUp);
    buttonExtakeTiltUp->WhenReleased(new command::ExtakeTiltStop);

    buttonIntakeTiltDown->WhenPressed(new command::IntakeTiltDown);
    buttonIntakeTiltDown->WhenReleased(new command::IntakeTiltStop);

    buttonIntakeTiltUp->WhenPressed(new command::IntakeTiltUp);
    buttonIntakeTiltUp->WhenReleased(new command::IntakeTiltStop);

    buttonIntakeToggle->WhenPressed(new command::IntakeToggle);
    buttonSolenoidsOut->WhenPressed(new command::hatchPanelOut);
    buttonSolenoidsIn->WhenPressed(new command::hatchPanelIn);
}
