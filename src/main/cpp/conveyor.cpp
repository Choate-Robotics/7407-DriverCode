#include "commands/conveyor.h"
#include "subsystems/conveyor.h"
#include <frc/commands/Subsystem.h>
#include "RobotMap.h"
#include "Robot.h"

subsystem::Conveyor::Conveyor(const wpi::Twine &name) : frc::Subsystem(name){}
void subsystem::Conveyor::move(){
    RobotMap::motor::conveyor->Set(Robot::oi->joystick[RobotMap::joystick::conveyor]->GetRawAxis(RobotMap::keymap::axis::conveyor));
}

command::ConveyorMove::ConveyorMove():frc::Command::Command(*Robot::conveyor){}

void subsystem::Conveyor::InitDefaultCommand(){
    SetDefaultCommand(new command::ConveyorMove);
}

void command::ConveyorMove::Initialize(){}
void command::ConveyorMove::Execute(){
    Robot::conveyor->move();
}
bool command::ConveyorMove::IsFinished(){ return false;}
void command::ConveyorMove::End(){}
void command::ConveyorMove::Interrupted(){}



