#include "commands/drivetrain.h"
#include "subsystems/drivetrain.h"
#include "Robot.h"
#include "RobotMap.h"
#include "OI.h"
#include <frc/drive/DifferentialDrive.h>

subsystem::Drivetrain::DriveStyle subsystem::Drivetrain::currentDriveStyle = ARCADE;

subsystem::Drivetrain::Drivetrain(const wpi::Twine &name) : frc::Subsystem(name) {}
void subsystem::Drivetrain::InitDefaultCommand(){ SetDefaultCommand(new command::DriveArcade); }


command::DriveArcade::DriveArcade() : frc::Command(*Robot::drivetrain){}
void command::DriveArcade::Initialize() {
    command::DriveArcade::SetInterruptible(true);
}
void command::DriveArcade::Execute()
{
    RobotMap::motor::differentialDrive->ArcadeDrive(
        -Robot::oi->joystick[RobotMap::joystick::drivetrain]->GetRawAxis(RobotMap::keymap::axis::driveX),
        Robot::oi->joystick[RobotMap::joystick::drivetrain]->GetRawAxis(RobotMap::keymap::axis::driveY)*.80
    );
}
bool command::DriveArcade::IsFinished() {return false;}
void command::DriveArcade::End() {}
void command::DriveArcade::Interrupted() {}


command::DriveTank::DriveTank() : frc::Command(*Robot::drivetrain){}
void command::DriveTank::Initialize() {
    command::DriveTank::SetInterruptible(true);
}
void command::DriveTank::Execute()
{
    RobotMap::motor::differentialDrive->TankDrive(
        Robot::oi->joystick[RobotMap::joystick::drivetrain]->GetRawAxis(1),
        Robot::oi->joystick[RobotMap::joystick::drivetrain]->GetRawAxis(3)
    );
}
bool command::DriveTank::IsFinished() {return false;}
void command::DriveTank::End() {}
void command::DriveTank::Interrupted() {}


void subsystem::Drivetrain::switchDrive()
{
    if (this->currentDriveStyle == ARCADE){
        auto drive = new command::DriveTank;
        drive->Start();
        subsystem::Drivetrain::currentDriveStyle = TANK;
    }
    else{
        auto drive = new command::DriveArcade;
        drive->Start();
        subsystem::Drivetrain::currentDriveStyle = ARCADE;
    }
}


