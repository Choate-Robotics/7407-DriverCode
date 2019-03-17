#include "commands/intake.h"
#include "subsystems/intake.h"
#include "RobotMap.h"
#include "Robot.h"

subsystem::Intake::Intake(const wpi::Twine & name):frc::Subsystem(name){}
void subsystem::Intake::InitDefaultCommand(){
    RobotMap::motor::intake->Set(-0.05);
}

subsystem::Intake::Direction subsystem::Intake::runningDirection = STOPPED;
subsystem::Intake::Direction subsystem::Intake::tiltingDirection = STOPPED;

void subsystem::Intake::in(){
    RobotMap::motor::intake->Set(0.5);
    this->runningDirection=FORWARD;
}

void subsystem::Intake::out(){
    RobotMap::motor::intake->Set(-0.5);
    this->runningDirection=REVERSED;
}

void subsystem::Intake::stop(){
    RobotMap::motor::intake->Set(0);
    this->runningDirection=STOPPED;
}

void subsystem::Intake::toggle(){
    if (runningDirection==FORWARD){
        subsystem::Intake::out();
    } else if (runningDirection==REVERSED){
        subsystem::Intake::in();
    } 
}

void subsystem::Intake::tiltUp(){
    RobotMap::motor::intakeTilt->Set(0.5);
    this->tiltingDirection=FORWARD;
}

void subsystem::Intake::tiltDown(){
    RobotMap::motor::intakeTilt->Set(-0.5);
    this->tiltingDirection=REVERSED;
}

void subsystem::Intake::tiltStop(){
    RobotMap::motor::intakeTilt->Set(0);
    this->tiltingDirection=STOPPED;
}

void subsystem::Intake::tiltToggle(){
    if (tiltingDirection==FORWARD){
        tiltDown();
    } else if (tiltingDirection==REVERSED){
        tiltUp();
    } 
}

command::IntakeIn::IntakeIn():frc::Command(*Robot::intake){}
void command::IntakeIn::Initialize() {Robot::intake->in();}
void command::IntakeIn::Execute() {}
bool command::IntakeIn::IsFinished() { return true; }
void command::IntakeIn::End() {}
void command::IntakeIn::Interrupted() {}

command::IntakeOut::IntakeOut():frc::Command(*Robot::intake){}
void command::IntakeOut::Initialize(){Robot::intake->out();}
void command::IntakeOut::Execute() {}
bool command::IntakeOut::IsFinished() { return true; }
void command::IntakeOut::End() {}
void command::IntakeOut::Interrupted() {}

command::IntakeStop::IntakeStop():frc::Command(*Robot::intake){}
void command::IntakeStop::Initialize(){Robot::intake->stop();}
void command::IntakeStop::Execute() {}
bool command::IntakeStop::IsFinished() { return true; }
void command::IntakeStop::End() {}
void command::IntakeStop::Interrupted() {}

command::IntakeToggle::IntakeToggle():frc::Command(*Robot::intake){}
void command::IntakeToggle::Initialize(){Robot::intake->toggle();}
void command::IntakeToggle::Execute() {}
bool command::IntakeToggle::IsFinished() { return true; }
void command::IntakeToggle::End() {}
void command::IntakeToggle::Interrupted() {}

command::IntakeTiltUp::IntakeTiltUp():frc::Command(*Robot::intake){}
void command::IntakeTiltUp::Initialize(){Robot::intake->tiltUp();}
void command::IntakeTiltUp::Execute() {}
bool command::IntakeTiltUp::IsFinished() { return true; }
void command::IntakeTiltUp::End() {}
void command::IntakeTiltUp::Interrupted() {}

command::IntakeTiltDown::IntakeTiltDown():frc::Command(*Robot::intake){}
void command::IntakeTiltDown::Initialize(){Robot::intake->tiltDown();}
void command::IntakeTiltDown::Execute() {}
bool command::IntakeTiltDown::IsFinished() { return true; }
void command::IntakeTiltDown::End() {}
void command::IntakeTiltDown::Interrupted() {}

command::IntakeTiltStop::IntakeTiltStop():frc::Command(*Robot::intake){}
void command::IntakeTiltStop::Initialize(){Robot::intake->tiltStop();}
void command::IntakeTiltStop::Execute() {}
bool command::IntakeTiltStop::IsFinished() { return true; }
void command::IntakeTiltStop::End() {}
void command::IntakeTiltStop::Interrupted() {}