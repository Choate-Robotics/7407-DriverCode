#include "Robot.h"
#include "OI.h"
#include "RobotMap.h"
#include "subsystems/drivetrain.h"
#include <iostream>
#include <frc/commands/Scheduler.h>

using namespace std;
using namespace RobotMap;

OI *Robot::oi = new OI;

frc::PWMTalonSRX * motor::frontLeft;
frc::PWMTalonSRX * motor::frontRight;
frc::PWMTalonSRX * motor::backLeft;
frc::PWMTalonSRX * motor::backRight;
frc::SpeedControllerGroup * motor::left;
frc::SpeedControllerGroup * motor::right;
frc::DifferentialDrive * motor::differentialDrive;

subsystem::Drivetrain* Robot::drivetrain = nullptr;

void Robot::RobotInit()
{

    motor::frontLeft = new frc::PWMTalonSRX{0};
    motor::frontRight = new frc::PWMTalonSRX{1};
    motor::backLeft = new frc::PWMTalonSRX{2};
    motor::backRight = new frc::PWMTalonSRX{3};

    motor::left = new frc::SpeedControllerGroup{*motor::frontLeft,*motor::backLeft};
    motor::right = new frc::SpeedControllerGroup{*motor::frontRight,*motor::backRight};
    motor::differentialDrive = new frc::DifferentialDrive{*motor::left, *motor::right};

    Robot::drivetrain = new subsystem::Drivetrain("Drivetrain");

    frc::Scheduler::GetInstance()->RegisterSubsystem(this->drivetrain);
}

void Robot::RobotPeriodic(){
    frc::Scheduler::GetInstance()->Run();
}
void Robot::DisabledInit(){}
void Robot::DisabledPeriodic(){}
void Robot::AutonomousInit(){}
void Robot::AutonomousPeriodic(){
    frc::Scheduler::GetInstance()->Run();
}
void Robot::TeleopInit(){}
void Robot::TeleopPeriodic(){
    frc::Scheduler::GetInstance()->Run();
}
void Robot::TestPeriodic(){}

int main(){return frc::StartRobot<Robot>();}
