#include "commands/drivetrain.h"
#include "subsystems/drivetrain.h"
#include "Robot.h"
#include "RobotMap.h"
#include "OI.h"
#include <frc/drive/DifferentialDrive.h>

subsystem::Drivetrain::Drivetrain(const wpi::Twine &name) : frc::Subsystem(name) {}
void subsystem::Drivetrain::InitDefaultCommand()
{
    SetDefaultCommand(new command::Drive);
}
command::Drive::Drive() : frc::Command(*Robot::drivetrain){}

void command::Drive::Initialize()
{

}

void command::Drive::Execute()
{
    RobotMap::motor::differentialDrive->ArcadeDrive(
        -Robot::oi->joystick[RobotMap::joystick::drivetrain]->GetRawAxis(RobotMap::keymap::axis::driveX),
        Robot::oi->joystick[RobotMap::joystick::drivetrain]->GetRawAxis(RobotMap::keymap::axis::driveY)*.80
    );
}

bool command::Drive::IsFinished()
{
    return false;
}

void command::Drive::End() {}
void command::Drive::Interrupted() {}
