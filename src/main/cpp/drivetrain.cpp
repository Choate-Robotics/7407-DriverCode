#include "commands/drivetrain.h"
#include "Robot.h"
#include "RobotMap.h"


subsystem::Drivetrain::Drivetrain(const wpi::Twine &name):frc::Subsystem(name){
    
}

command::Drive::Drive(){
    Requires(Robot::drivetrain);
}

void command::Drive::Initialize() {}

void command::Drive::Execute() {

}

bool command::Drive::IsFinished() {
    return false;
}

void command::Drive::End() {}
void command::Drive::Interrupted() {}

