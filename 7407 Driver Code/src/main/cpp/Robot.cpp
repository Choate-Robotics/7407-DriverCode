#include "Robot.h"
#include <iostream>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/Timer.h>
#include <frc/Joystick.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/PWMVictorSPX.h>
#include <frc/SpeedControllerGroup.h>
#include <frc/DoubleSolenoid.h>
#include <string.h>

frc::PWMVictorSPX leftFront{0};
frc::PWMVictorSPX leftBack{1};
frc::PWMVictorSPX rightFront{2};
frc::PWMVictorSPX rightBack{3};

frc::SpeedControllerGroup left{leftFront, leftBack};
frc::SpeedControllerGroup right{rightFront, rightBack};
frc::DifferentialDrive RobotDrive(left, right);

frc::DoubleSolenoid solenoid_top{0, 1};
frc::DoubleSolenoid solenoid_left{2, 3};
frc::DoubleSolenoid solenoid_right{4, 5};

frc::Joystick stick{0};

std::string Logitech_Stick;

void placeHatch()
{
  solenoid_top.Set(frc::DoubleSolenoid::kForward);
  solenoid_left.Set(frc::DoubleSolenoid::kForward);
  solenoid_right.Set(frc::DoubleSolenoid::kForward);
}

void releaseHatch()
{
  solenoid_top.Set(frc::DoubleSolenoid::kForward);
  solenoid_left.Set(frc::DoubleSolenoid::kForward);
  solenoid_right.Set(frc::DoubleSolenoid::kForward);
}

void Robot::RobotInit()
{
  Logitech_Stick = stick.GetName(); 
}

void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic()
{
  if (Logitech_Stick != "Logitech Extreme 3D")
  {
    RobotDrive.TankDrive(stick.GetRawAxis(1), stick.GetRawAxis(5));
  }
  else
  {
    RobotDrive.ArcadeDrive(stick.GetY(), stick.GetX());

    if(stick.GetRawButton(5))
    {
      placeHatch();
    }
    else if (stick.GetRawButton(3))
    {
      releaseHatch();
    }
    else
    {
      solenoid_top.Set(frc::DoubleSolenoid::kOff);
      solenoid_left.Set(frc::DoubleSolenoid::kOff);
      solenoid_right.Set(frc::DoubleSolenoid::kOff);
    }
  }
}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif


