#include "subsystems/hatchPanel.h"
#include "commands/hatchPanel.h"
#include "RobotMap.h"
#include "Robot.h"

subsystem::HatchPanel::HatchPanel(const wpi::Twine &name):frc::Subsystem(name){}
void subsystem::HatchPanel::InitDefaultCommand(){}

void subsystem::HatchPanel::out(){
    RobotMap::solenoid::hatchPanel->Set(frc::DoubleSolenoid::kForward);
}
void subsystem::HatchPanel::in(){
    RobotMap::solenoid::hatchPanel->Set(frc::DoubleSolenoid::kReverse);
}

void subsystem::HatchPanel::rollerIntake(){
    RobotMap::motor::hatchRoller->Set(0.6);
}

void subsystem::HatchPanel::rollerExtake(){
    RobotMap::motor::hatchRoller->Set(-0.8);
}

void subsystem::HatchPanel::rollerHold(){
    RobotMap::motor::hatchRoller->Set(0.05);
}

void subsystem::HatchPanel::rollerOff(){
    RobotMap::motor::hatchRoller->Set(0);
}

command::hatchPanelIn::hatchPanelIn():frc::Command::Command(*Robot::hatchPanel){}
void command::hatchPanelIn::Initialize(){}
void command::hatchPanelIn::Execute(){ Robot::hatchPanel->in(); }
bool command::hatchPanelIn::IsFinished(){ return true; }
void command::hatchPanelIn::End(){}
void command::hatchPanelIn::Interrupted(){}

command::hatchPanelOut::hatchPanelOut():frc::Command::Command(*Robot::hatchPanel){}
void command::hatchPanelOut::Initialize(){}
void command::hatchPanelOut::Execute(){ Robot::hatchPanel->out(); }
bool command::hatchPanelOut::IsFinished(){ return true; }
void command::hatchPanelOut::End(){}
void command::hatchPanelOut::Interrupted(){}

command::hatchPanelRollerIntake::hatchPanelRollerIntake():frc::Command::Command(*Robot::hatchPanel){}
void command::hatchPanelRollerIntake::Initialize(){}
void command::hatchPanelRollerIntake::Execute(){ Robot::hatchPanel->rollerIntake(); }
bool command::hatchPanelRollerIntake::IsFinished(){ return true; }
void command::hatchPanelRollerIntake::End(){}
void command::hatchPanelRollerIntake::Interrupted(){}

command::hatchPanelRollerExtake::hatchPanelRollerExtake():frc::Command::Command(*Robot::hatchPanel){}
void command::hatchPanelRollerExtake::Initialize(){}
void command::hatchPanelRollerExtake::Execute(){ Robot::hatchPanel->rollerExtake(); }
bool command::hatchPanelRollerExtake::IsFinished(){ return true; }
void command::hatchPanelRollerExtake::End(){}
void command::hatchPanelRollerExtake::Interrupted(){}

command::hatchPanelRollerHold::hatchPanelRollerHold():frc::Command::Command(*Robot::hatchPanel){}
void command::hatchPanelRollerHold::Initialize(){}
void command::hatchPanelRollerHold::Execute(){ Robot::hatchPanel->rollerHold(); }
bool command::hatchPanelRollerHold::IsFinished(){ return true; }
void command::hatchPanelRollerHold::End(){}
void command::hatchPanelRollerHold::Interrupted(){}

command::hatchPanelRollerOff::hatchPanelRollerOff():frc::Command::Command(*Robot::hatchPanel){}
void command::hatchPanelRollerOff::Initialize(){}
void command::hatchPanelRollerOff::Execute(){ Robot::hatchPanel->rollerOff(); }
bool command::hatchPanelRollerOff::IsFinished(){ return true; }
void command::hatchPanelRollerOff::End(){}
void command::hatchPanelRollerOff::Interrupted(){}