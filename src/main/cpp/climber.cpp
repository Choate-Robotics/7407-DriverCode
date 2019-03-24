#include "subsystems/climber.h"
#include "commands/climber.h"
#include "RobotMap.h"
#include "Robot.h"

subsystem::Climber::Climber(const wpi::Twine &name):frc::Subsystem(name){}

void subsystem::Climber::frontToggle(){
    if (frontFired){
        RobotMap::solenoid::climberFront->Set(frc::DoubleSolenoid::kReverse);
        this->frontFired=false;
    } else {
        RobotMap::solenoid::climberFront->Set(frc::DoubleSolenoid::kForward);
        this->frontFired=true;
    }
}
void subsystem::Climber::backToggle(){
    if (backFired){
        RobotMap::solenoid::climberBack->Set(frc::DoubleSolenoid::kReverse);
        this->backFired=false;
    } else {
        RobotMap::solenoid::climberBack->Set(frc::DoubleSolenoid::kForward);
        this->backFired=true;
    }
}

void subsystem::Climber::InitDefaultCommand(){}

command::climberBackToggle::climberBackToggle():frc::Command::Command(*Robot::climber){}
command::climberFrontToggle::climberFrontToggle():frc::Command::Command(*Robot::climber){}

void command::climberFrontToggle::Initialize(){}
void command::climberFrontToggle::Execute(){
    Robot::climber->frontToggle();
}
bool command::climberFrontToggle::IsFinished(){
    return true;
}
void command::climberFrontToggle::End(){}
void command::climberFrontToggle::Interrupted(){}

void command::climberBackToggle::Initialize(){}
void command::climberBackToggle::Execute(){
    Robot::climber->backToggle();
}
bool command::climberBackToggle::IsFinished(){
    return true;
}
void command::climberBackToggle::End(){}
void command::climberBackToggle::Interrupted(){}