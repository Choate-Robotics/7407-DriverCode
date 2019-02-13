#include "Robot.h"
#include "OI.h"
#include "RobotMap.h"
#include "subsystems/conveyor.h"
#include "subsystems/drivetrain.h"
#include "subsystems/intake.h"
#include "subsystems/extake.h"
#include "subsystems/hatchPanel.h"
#include <frc/commands/Scheduler.h>

OI *Robot::oi = new OI;

subsystem::Conveyor* Robot::conveyor = 0;
subsystem::Extake* Robot::extake = 0;
subsystem::Drivetrain* Robot::drivetrain = 0;
subsystem::Intake* Robot::intake = 0;
subsystem::HatchPanel* Robot::hatchPanel = 0;

void Robot::RobotInit()
{
    using namespace RobotMap;
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