#include "commands/extake.h"
#include "subsystems/extake.h"
#include "RobotMap.h"
#include "Robot.h"

subsystem::Extake::Extake(const wpi::Twine & name):frc::Subsystem(name){}
void subsystem::Extake::InitDefaultCommand(){}

subsystem::Extake::Direction subsystem::Extake::runningDirection = STOPPED;
subsystem::Extake::Direction subsystem::Extake::tiltingDirection = STOPPED;

void subsystem::Extake::outLow(){
    RobotMap::motor::extakeLeft->Set(0.25);
    RobotMap::motor::extakeRight->Set(-0.25);
    this->runningDirection=FORWARD;
}

void subsystem::Extake::outHigh(){
    RobotMap::motor::extakeLeft->Set(0.5);
    RobotMap::motor::extakeRight->Set(-0.5);
    this->runningDirection=FORWARD;
}

void subsystem::Extake::stop(){
    RobotMap::motor::extakeLeft->Set(0);
    RobotMap::motor::extakeRight->Set(0);
    this->runningDirection=STOPPED;
}

void subsystem::Extake::tiltUp(){
    RobotMap::motor::extakeTilt->Set(0.3);
    this->tiltingDirection=REVERSED;
}

void subsystem::Extake::tiltDown(){
    RobotMap::motor::extakeTilt->Set(-0.3);
    this->tiltingDirection=FORWARD;
}

void subsystem::Extake::tiltStop(){
    RobotMap::motor::extakeTilt->Set(0);
    this->tiltingDirection=STOPPED;
}


command::ExtakeOutLow::ExtakeOutLow():frc::Command(*Robot::extake){}
void command::ExtakeOutLow::Initialize() {Robot::extake->outLow();}
void command::ExtakeOutLow::Execute() {}
bool command::ExtakeOutLow::IsFinished() { return true; }
void command::ExtakeOutLow::End() {}
void command::ExtakeOutLow::Interrupted() {}

command::ExtakeOutHigh::ExtakeOutHigh():frc::Command(*Robot::extake){}
void command::ExtakeOutHigh::Initialize(){Robot::extake->outHigh();}
void command::ExtakeOutHigh::Execute() {}
bool command::ExtakeOutHigh::IsFinished() { return true; }
void command::ExtakeOutHigh::End() {}
void command::ExtakeOutHigh::Interrupted() {}

command::ExtakeStop::ExtakeStop():frc::Command(*Robot::extake){}
void command::ExtakeStop::Initialize(){Robot::extake->stop();}
void command::ExtakeStop::Execute() {}
bool command::ExtakeStop::IsFinished() { return true; }
void command::ExtakeStop::End() {}
void command::ExtakeStop::Interrupted() {}

command::ExtakeTiltUp::ExtakeTiltUp():frc::Command(*Robot::extake){}
void command::ExtakeTiltUp::Initialize(){Robot::extake->tiltUp();}
void command::ExtakeTiltUp::Execute() {}
bool command::ExtakeTiltUp::IsFinished() { return true; }
void command::ExtakeTiltUp::End() {}
void command::ExtakeTiltUp::Interrupted() {}

command::ExtakeTiltDown::ExtakeTiltDown():frc::Command(*Robot::extake){}
void command::ExtakeTiltDown::Initialize(){Robot::extake->tiltDown();}
void command::ExtakeTiltDown::Execute() {}
bool command::ExtakeTiltDown::IsFinished() { return true; }
void command::ExtakeTiltDown::End() {}
void command::ExtakeTiltDown::Interrupted() {}

command::ExtakeTiltStop::ExtakeTiltStop():frc::Command(*Robot::extake){}
void command::ExtakeTiltStop::Initialize(){Robot::extake->tiltStop();}
void command::ExtakeTiltStop::Execute() {}
bool command::ExtakeTiltStop::IsFinished() { return true; }
void command::ExtakeTiltStop::End() {}
void command::ExtakeTiltStop::Interrupted() {}