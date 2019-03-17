#include "Robot.h"
#include "OI.h"
#include "RobotMap.h"
#include "subsystems/conveyor.h"
#include "subsystems/drivetrain.h"
#include "subsystems/intake.h"
#include "subsystems/extake.h"
#include "subsystems/hatchPanel.h"
#include <iostream>
#include <frc/commands/Scheduler.h>

using namespace std;
using namespace RobotMap;

OI *Robot::oi = new OI;

frc::PWMTalonSRX * motor::frontLeft;
frc::PWMTalonSRX * motor::frontRight;
frc::PWMTalonSRX * motor::backLeft;
frc::PWMTalonSRX * motor::backRight;
frc::PWMVictorSPX * motor::conveyor;
frc::PWMVictorSPX * motor::intake;
frc::PWMVictorSPX * motor::intakeTilt;
frc::PWMVictorSPX * motor::extakeTilt;
frc::PWMVictorSPX * motor::extakeLeft;
frc::PWMVictorSPX * motor::extakeRight;
frc::SpeedControllerGroup * motor::left;
frc::SpeedControllerGroup * motor::right;
frc::DifferentialDrive * motor::differentialDrive;


subsystem::Conveyor* Robot::conveyor = 0;
subsystem::Extake* Robot::extake = 0;
subsystem::Drivetrain* Robot::drivetrain = 0;
subsystem::Intake* Robot::intake = 0;
subsystem::HatchPanel* Robot::hatchPanel = 0;

void Robot::RobotInit()
{

    motor::frontLeft = new frc::PWMTalonSRX{0};
    motor::frontRight = new frc::PWMTalonSRX{1};
    motor::backLeft = new frc::PWMTalonSRX{2};
    motor::backRight = new frc::PWMTalonSRX{3};

    motor::conveyor = new frc::PWMVictorSPX{4};
    motor::intake = new frc::PWMVictorSPX{5};
    motor::intakeTilt = new frc::PWMVictorSPX{6};
    motor::extakeTilt = new frc::PWMVictorSPX{7};
    motor::extakeLeft = new frc::PWMVictorSPX{8};
    motor::extakeRight = new frc::PWMVictorSPX{9};

    motor::left = new frc::SpeedControllerGroup{*motor::frontLeft,*motor::backLeft};
    motor::right = new frc::SpeedControllerGroup{*motor::frontRight,*motor::backRight};
    motor::differentialDrive = new frc::DifferentialDrive{*motor::left, *motor::right};

    Robot::conveyor = new subsystem::Conveyor("Conveyor");
    Robot::extake = new subsystem::Extake("Extake");
    Robot::drivetrain = new subsystem::Drivetrain("Drivetrain");
    Robot::intake = new subsystem::Intake("Intake");
    Robot::hatchPanel = new subsystem::HatchPanel("Hatch Panel");

    frc::Scheduler::GetInstance()->RegisterSubsystem(this->drivetrain);
    frc::Scheduler::GetInstance()->RegisterSubsystem(this->conveyor);
    frc::Scheduler::GetInstance()->RegisterSubsystem(this->extake);
    frc::Scheduler::GetInstance()->RegisterSubsystem(this->intake);
    frc::Scheduler::GetInstance()->RegisterSubsystem(this->hatchPanel);
}

void Robot::RobotPeriodic(){
    frc::Scheduler::GetInstance()->Run();
}
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