#include "Robot.h"
#include "OI.h"
#include "RobotMap.h"
#include "subsystems/drivetrain.h"
#include <iostream>
#include <frc/commands/Scheduler.h>

using namespace std;
using namespace RobotMap;

OI *Robot::oi = new OI;

frc::PWMTalonSRX * motor::left1;
frc::PWMTalonSRX * motor::left2;
frc::PWMTalonSRX * motor::left3;
frc::PWMTalonSRX * motor::right1;
frc::PWMTalonSRX * motor::right2;
frc::PWMTalonSRX * motor::right3;
frc::SpeedControllerGroup * motor::left;
frc::SpeedControllerGroup * motor::right;
frc::DifferentialDrive * motor::differentialDrive;

subsystem::Drivetrain* Robot::drivetrain = nullptr;

void Robot::RobotInit()
{

    motor::left1 = new frc::PWMTalonSRX{0};
    motor::left2 = new frc::PWMTalonSRX{1};
    motor::left3 = new frc::PWMTalonSRX{2};
    motor::right1 = new frc::PWMTalonSRX{3};
    motor::right2 = new frc::PWMTalonSRX{4};
    motor::right3 = new frc::PWMTalonSRX{5};

    motor::left = new frc::SpeedControllerGroup{*motor::left1, *motor::left2, *motor::left3};
    motor::right = new frc::SpeedControllerGroup{*motor::right1, *motor::right2, *motor::right3};
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
