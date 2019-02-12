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

void Robot::RobotInit()
{
    using namespace RobotMap;
    this->conveyor = new subsystem::Conveyor("Conveyor");
    this->extake = new subsystem::Extake("Extake");
    this->drivetrain = new subsystem::Drivetrain("Drivetrain");
    this->intake = new subsystem::Intake("Intake");
    this->hatchPanel = new subsystem::HatchPanel("Hatch Panel");
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