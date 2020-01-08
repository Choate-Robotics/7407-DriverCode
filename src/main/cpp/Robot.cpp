#include "Robot.h"
#include "OI.h"
#include "RobotMap.h"
#include "subsystems/drivetrain.h"
#include <iostream>
#include <frc/commands/Scheduler.h>

#include <frc/smartdashboard/SmartDashboard.h>

#include "rev/ColorSensorV3.h"

#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"

using namespace std;
using namespace RobotMap;

OI *Robot::oi = new OI; 

frc::PWMVictorSPX * motor::frontLeft;
frc::PWMVictorSPX * motor::frontRight;
frc::PWMVictorSPX * motor::backLeft;
frc::PWMVictorSPX * motor::backRight;
frc::SpeedControllerGroup * motor::left;
frc::SpeedControllerGroup * motor::right;
frc::DifferentialDrive * motor::differentialDrive;

subsystem::Drivetrain* Robot::drivetrain = nullptr;

static constexpr auto i2cPort = frc::I2C::Port::kOnboard;

rev::ColorSensorV3 colorSensor{i2cPort};


void Robot::RobotInit()
{

    motor::frontLeft = new frc::PWMVictorSPX{1};
    motor::frontRight = new frc::PWMVictorSPX{2};
    motor::backLeft = new frc::PWMVictorSPX{3};
    motor::backRight = new frc::PWMVictorSPX{4};

    motor::left = new frc::SpeedControllerGroup{*motor::frontLeft,*motor::backLeft};
    motor::right = new frc::SpeedControllerGroup{*motor::frontRight,*motor::backRight};
    motor::differentialDrive = new frc::DifferentialDrive{*motor::left, *motor::right};

    Robot::drivetrain = new subsystem::Drivetrain("Drivetrain");

    frc::Scheduler::GetInstance()->RegisterSubsystem(this->drivetrain);
}

void Robot::RobotPeriodic(){
    frc::Scheduler::GetInstance()->Run();

    frc::Color detectedColor = colorSensor.GetColor();

    double IR = colorSensor.GetIR();
    
    std::shared_ptr<NetworkTable> table = nt::NetworkTableInstance::GetDefault().GetTable("SmartDashboard");
    
    table->PutNumber("Red", detectedColor.red);
    table->PutNumber("Green", detectedColor.green);
    table->PutNumber("Blue", detectedColor.blue);
    table->PutNumber("IR", IR);
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

    // motor::backLeft->Set(0.5);
}
void Robot::TestPeriodic(){}

int main(){return frc::StartRobot<Robot>();}
