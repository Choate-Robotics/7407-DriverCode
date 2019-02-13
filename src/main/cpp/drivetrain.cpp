#include "commands/drivetrain.h"
#include "subsystems/drivetrain.h"
#include "Robot.h"
#include "RobotMap.h"

subsystem::Drivetrain::Drivetrain(const wpi::Twine &name):frc::Subsystem(name){}
void subsystem::Drivetrain::InitDefaultCommand(){}
command::Drive::Drive():frc::Command(*Robot::drivetrain){};

void command::Drive::Initialize() {}

void command::Drive::Execute() {

}

bool command::Drive::IsFinished() {
    return false;
}

void command::Drive::End() {}
void command::Drive::Interrupted() {}

