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

<<<<<<< HEAD
static constexpr int kDoubleSolenoidForward = 3;
static constexpr int kDoubleSolenoidReverse = 5;
=======
void operateHatch(int button_1, int button_2){
  if (stick.GetRawButton(button_1))
  {
    solenoid_top.Set(frc::DoubleSolenoid::kForward);
    solenoid_left.Set(frc::DoubleSolenoid::kForward);
    solenoid_right.Set(frc::DoubleSolenoid::kForward);
  }
  else if (stick.GetRawButton(button_2))
  {
    solenoid_top.Set(frc::DoubleSolenoid::kForward);
    solenoid_left.Set(frc::DoubleSolenoid::kForward);
    solenoid_right.Set(frc::DoubleSolenoid::kForward);
  }
  else
  {
    solenoid_top.Set(frc::DoubleSolenoid::kOff);
    solenoid_left.Set(frc::DoubleSolenoid::kOff);
    solenoid_right.Set(frc::DoubleSolenoid::kOff);
  }
}
>>>>>>> 588027d8586dde6f71fedb1c0ad317fe6d60e3fa

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
<<<<<<< HEAD
  if (stick.GetRawButton(kDoubleSolenoidForward)) 
  {
    solenoid_top.Set(frc::DoubleSolenoid::kForward);
  } 
  else if (stick.GetRawButton(kDoubleSolenoidReverse)) 
  {
    solenoid_top.Set(frc::DoubleSolenoid::kReverse);
  } 
  else 
  {
    solenoid_top.Set(frc::DoubleSolenoid::kOff);
  }
  /*
  if (Logitech_Stick == "Controller (Gamepad F310)")
=======
  if (stick_type == "Controller (Gamepad F310)")
>>>>>>> 588027d8586dde6f71fedb1c0ad317fe6d60e3fa
  {
    RobotDrive.TankDrive(-stick.GetRawAxis(1), -stick.GetRawAxis(5));
  }
  else
  {
    RobotDrive.ArcadeDrive(-stick.GetY(), -stick.GetX());
<<<<<<< HEAD
    */
=======
    operateHatch(5,3);
  }
>>>>>>> 588027d8586dde6f71fedb1c0ad317fe6d60e3fa
}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif


