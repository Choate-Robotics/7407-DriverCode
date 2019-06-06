#include "OI.h"
#include <frc/Joystick.h>
#include <frc/buttons/JoystickButton.h>
#include "RobotMap.h"
#include "commands/hatchPanel.h"
#include "commands/drivetrain.h"
#include "commands/conveyor.h"
#include "commands/extake.h"
#include "commands/intake.h"
#include "commands/climber.h"


frc::Joystick *OI::joystick[2] = {nullptr};
frc::JoystickButton *OI::buttonIntakeToggle = nullptr;
frc::JoystickButton *OI::buttonIntakeTiltUp = nullptr;
frc::JoystickButton *OI::buttonIntakeTiltDown = nullptr;

frc::JoystickButton *OI::buttonExtakeStop = nullptr;
frc::JoystickButton *OI::buttonExtakeLow = nullptr;
frc::JoystickButton *OI::buttonExtakeTiltUp = nullptr;
frc::JoystickButton *OI::buttonExtakeTiltDown = nullptr;
frc::JoystickButton *OI::buttonSolenoidsOut = nullptr;
frc::JoystickButton *OI::buttonSolenoidsIn = nullptr;
frc::JoystickButton *OI::buttonClimberFrontToggle = nullptr;
frc::JoystickButton *OI::buttonClimberBackToggle = nullptr;
frc::JoystickButton *OI::buttonHatchRollerIn = nullptr;
frc::JoystickButton *OI::buttonHatchRollerOut = nullptr;

OI::OI()
{
    using namespace RobotMap;
    this->joystick[PRIMARY_JOYSTICK] = new frc::Joystick{joystick::portPrimary};
    this->joystick[SECONDARY_JOYSTICK] = new frc::Joystick{joystick::portSecondary};

    this->buttonIntakeToggle = new frc::JoystickButton(joystick[joystick::intake], keymap::button::intakeToggle);
    this->buttonIntakeTiltUp = new frc::JoystickButton(joystick[joystick::intakeTilt], keymap::button::intakeTiltUp);
    this->buttonIntakeTiltDown = new frc::JoystickButton(joystick[joystick::intakeTilt], keymap::button::intakeTiltDown);

    this->buttonExtakeStop = new frc::JoystickButton(joystick[joystick::extake], keymap::button::extakeStop);
    this->buttonExtakeLow = new frc::JoystickButton(joystick[joystick::extake], keymap::button::extakeLow);
    this->buttonExtakeTiltUp = new frc::JoystickButton(joystick[joystick::extake], keymap::button::extakeTiltUp);
    this->buttonExtakeTiltDown = new frc::JoystickButton(joystick[joystick::extake], keymap::button::extakeTiltDown);
    this->buttonSolenoidsOut = new frc::JoystickButton(joystick[joystick::hatchPanel], keymap::button::hatchPanelOut);
    this->buttonSolenoidsIn = new frc::JoystickButton(joystick[joystick::hatchPanel], keymap::button::hatchPanelIn);
    this->buttonClimberFrontToggle = new frc::JoystickButton(joystick[joystick::climber],keymap::button::climberFront);
    this->buttonClimberBackToggle = new frc::JoystickButton(joystick[joystick::climber],keymap::button::climberBack);
    this->buttonHatchRollerIn = new frc::JoystickButton(joystick[joystick::climber],keymap::button::hatchPanelIntake);
    this->buttonHatchRollerOut = new frc::JoystickButton(joystick[joystick::climber],keymap::button::hatchPanelExtake);



    buttonExtakeStop->WhenPressed(new command::ExtakeStop);
    buttonExtakeLow->WhenPressed(new command::ExtakeOutSlow);


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

    buttonClimberFrontToggle->WhenPressed(new command::climberFrontToggle);
    buttonClimberBackToggle->WhenPressed(new command::climberBackToggle);

    buttonHatchRollerIn->WhenPressed(new command::hatchPanelIntake);
    buttonHatchRollerIn->WhenReleased(new command::hatchPanelHold);

    buttonHatchRollerOut->WhenPressed(new command::hatchPanelExtake);
    buttonHatchRollerOut->WhenReleased(new command::hatchPanelOff);

}
