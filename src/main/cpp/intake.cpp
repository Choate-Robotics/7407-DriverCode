#include "commands/intake.h"
#include "subsystems/intake.h"
#include "RobotMap.h"
#include "Robot.h"

void command::IntakeIn::Initialize(){
    RobotMap::motor::intake.Set(0.5);
}

void command::IntakeIn::Execute(){
    
}

bool command::IntakeIn::IsFinished(){
    return false;
}

void command::IntakeIn::End(){
    RobotMap::motor::intake.Set(0);
}