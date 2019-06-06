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

void subsystem::HatchPanel::intake(){
    RobotMap::motor::hatchRoller->Set(-0.5);
}

void subsystem::HatchPanel::extake(){
    RobotMap::motor::hatchRoller->Set(0.5);
}

void subsystem::HatchPanel::hold(){
    RobotMap::motor::hatchRoller->Set(-0.05);
}

void subsystem::HatchPanel::off(){
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

command::hatchPanelIntake::hatchPanelIntake():frc::Command::Command(*Robot::hatchPanel){}
void command::hatchPanelIntake::Initialize(){}
void command::hatchPanelIntake::Execute(){ Robot::hatchPanel->intake(); }
bool command::hatchPanelIntake::IsFinished(){ return true; }
void command::hatchPanelIntake::End(){}
void command::hatchPanelIntake::Interrupted(){}

command::hatchPanelExtake::hatchPanelExtake():frc::Command::Command(*Robot::hatchPanel){}
void command::hatchPanelExtake::Initialize(){}
void command::hatchPanelExtake::Execute(){ Robot::hatchPanel->extake(); }
bool command::hatchPanelExtake::IsFinished(){ return true; }
void command::hatchPanelExtake::End(){}
void command::hatchPanelExtake::Interrupted(){}

command::hatchPanelHold::hatchPanelHold():frc::Command::Command(*Robot::hatchPanel){}
void command::hatchPanelHold::Initialize(){}
void command::hatchPanelHold::Execute(){ Robot::hatchPanel->hold(); }
bool command::hatchPanelHold::IsFinished(){ return true; }
void command::hatchPanelHold::End(){}
void command::hatchPanelHold::Interrupted(){}

command::hatchPanelOff::hatchPanelOff():frc::Command::Command(*Robot::hatchPanel){}
void command::hatchPanelOff::Initialize(){}
void command::hatchPanelOff::Execute(){ Robot::hatchPanel->off(); }
bool command::hatchPanelOff::IsFinished(){ return true; }
void command::hatchPanelOff::End(){}
void command::hatchPanelOff::Interrupted(){}