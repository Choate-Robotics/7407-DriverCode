#include "Robot.h"
#include <iostream>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/Joystick.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/PWMVictorSPX.h>
#include <frc/PWMTalonSRX.h>
#include <frc/SpeedControllerGroup.h>
#include <frc/DoubleSolenoid.h>
#include <string.h>

/*
frc::PWMTalonSRX leftFront{0};
frc::PWMTalonSRX leftBack{1};
frc::PWMTalonSRX rightFront{2};
frc::PWMTalonSRX rightBack{3};
*/

frc::PWMVictorSPX leftFront{1};
frc::PWMVictorSPX leftBack{3};
frc::PWMVictorSPX rightFront{2};
frc::PWMVictorSPX rightBack{4};

frc::SpeedControllerGroup left{leftFront, leftBack};
frc::SpeedControllerGroup right{rightFront, rightBack};
frc::DifferentialDrive RobotDrive(left, right);

frc::DoubleSolenoid solenoid_top{0, 1};
frc::DoubleSolenoid solenoid_left{2, 3};
frc::DoubleSolenoid solenoid_right{4, 5};

frc::Joystick stick{0};

std::string stick_type;

static constexpr int kDoubleSolenoidForward = 5;
static constexpr int kDoubleSolenoidReverse = 3;

void Robot::RobotInit()
{
  stick_type = stick.GetName(); 
}

void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic()
{
  if (stick.GetRawButton(kDoubleSolenoidForward)) 
  {
    solenoid_top.Set(frc::DoubleSolenoid::kForward);
    solenoid_left.Set(frc::DoubleSolenoid::kForward);
    solenoid_right.Set(frc::DoubleSolenoid::kForward);
  } 
  else if (stick.GetRawButton(kDoubleSolenoidReverse)) 
  {
    solenoid_top.Set(frc::DoubleSolenoid::kReverse);
    solenoid_left.Set(frc::DoubleSolenoid::kReverse);
    solenoid_right.Set(frc::DoubleSolenoid::kReverse);
  } 
  else 
  {
    solenoid_top.Set(frc::DoubleSolenoid::kOff);
    solenoid_left.Set(frc::DoubleSolenoid::kOff);
    solenoid_right.Set(frc::DoubleSolenoid::kOff);
  }
  
  if (stick_type == "Controller (Gamepad F310)")
  {
    RobotDrive.TankDrive(-stick.GetRawAxis(1), -stick.GetRawAxis(5));
  }
  else
  {
    RobotDrive.ArcadeDrive(-stick.GetY(), -stick.GetX());
  }
}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif


