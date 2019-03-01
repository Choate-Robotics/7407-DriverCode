#include "subsystems/hatchPanel.h"
#include "commands/hatchPanel.h"
#include "RobotMap.h"
#include "Robot.h"

subsystem::HatchPanel::HatchPanel(const wpi::Twine &name):frc::Subsystem(name){}

void subsystem::HatchPanel::out(){
    RobotMap::solenoid::left.Set(frc::DoubleSolenoid::kForward);
    RobotMap::solenoid::top.Set(frc::DoubleSolenoid::kForward);
    RobotMap::solenoid::right.Set(frc::DoubleSolenoid::kForward);
}
void subsystem::HatchPanel::in(){
    RobotMap::solenoid::left.Set(frc::DoubleSolenoid::kReverse);
    RobotMap::solenoid::top.Set(frc::DoubleSolenoid::kReverse);
    RobotMap::solenoid::right.Set(frc::DoubleSolenoid::kReverse);
}

command::hatchPanelIn::hatchPanelIn():frc::Command::Command(*Robot::hatchPanel){}
command::hatchPanelOut::hatchPanelOut():frc::Command::Command(*Robot::hatchPanel){}

void subsystem::HatchPanel::InitDefaultCommand(){}

void command::hatchPanelIn::Initialize(){}
void command::hatchPanelIn::Execute(){
    Robot::hatchPanel->in();
}
bool command::hatchPanelIn::IsFinished(){
    return true;
}
void command::hatchPanelIn::End(){}
void command::hatchPanelIn::Interrupted(){}

void command::hatchPanelOut::Initialize(){}
void command::hatchPanelOut::Execute(){
    Robot::hatchPanel->out();
}
bool command::hatchPanelOut::IsFinished(){
    return true;
}
void command::hatchPanelOut::End(){}
void command::hatchPanelOut::Interrupted(){}