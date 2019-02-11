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

void RobotInit()
{
    subsystem::Conveyor *conveyor = new subsystem::Conveyor;
    subsystem::Extake *extake = new subsystem::Extake;
    subsystem::Drivetrain *drivetrain = new subsystem::Drivetrain;
    subsystem::Intake *intake = new subsystem::Intake;
    subsystem::HatchPanel *hatchPanel = new subsystem::HatchPanel;
}

void RobotPeriodic(){}
void AutonomousInit(){}
void AutonomousPeriodic(){}
void TeleopInit(){}
void TeleopPeriodic(){
    frc::Scheduler::GetInstance()->Run();
}
void TestPeriodic(){}