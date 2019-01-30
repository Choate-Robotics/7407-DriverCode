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

frc::PWMVictorSPX leftFront{0};
frc::PWMVictorSPX leftBack{2};
frc::PWMVictorSPX rightFront{1};
frc::PWMVictorSPX rightBack{3};

frc::PWMVictorSPX conveyorMotor{4};
frc::PWMVictorSPX intakeMotor{5};
frc::PWMVictorSPX intakeAngle{6};
frc::PWMVictorSPX extakeAngle{7};
frc::PWMVictorSPX extakeRight{8};
frc::PWMVictorSPX extakeLeft{9};

frc::SpeedControllerGroup left{leftFront, leftBack};
frc::SpeedControllerGroup right{rightFront, rightBack};
frc::DifferentialDrive RobotDrive(left, right);

frc::SpeedControllerGroup extake{extakeLeft, extakeRight};

frc::DoubleSolenoid solenoid_top{0, 1};
frc::DoubleSolenoid solenoid_left{2, 3};
frc::DoubleSolenoid solenoid_right{4, 5};

frc::Joystick stick{0};

std::string stick_type;

static constexpr int kDoubleSolenoidForward = 5;
static constexpr int kDoubleSolenoidReverse = 6;

void drive()
{
  if (stick_type == "Controller (Gamepad F310)" or "4 axis 12 button joystick with hat switch")
  {
    RobotDrive.TankDrive(-stick.GetRawAxis(1), -stick.GetRawAxis(5));
  }
  else
  {
    RobotDrive.ArcadeDrive(-stick.GetY(), -stick.GetX());
  }
}

void intakeCargo()
{
  if(stick.GetRawButton(3))
  {
    intakeMotor.Set(.5);
  }
  else if(stick.GetRawButton(5))
  {
    intakeMotor.Set(0);
  }
}

void carryCargo()
{
  if(stick.GetRawButton(1))
  {
    conveyorMotor.Set(.5);
  }
  else if(stick.GetRawButton(2))
  {
    conveyorMotor.Set(0);
  }
}

void extakeCargo()
{
  if(stick.GetRawButton(4))
  {
    intakeMotor.Set(.5);
  }
  else if(stick.GetRawButton(6))
  {
    intakeMotor.Set(0);
  }
}

void angleIntake()
{
  if (stick.GetRawButton(11))
  {
    intakeAngle.Set(.5);
  }
  else if (stick.GetRawButton(7))
  {
    intakeAngle.Set(-.5);
  }
  else if (stick.GetRawButton(9))
  {
    intakeAngle.Set(0);
  }
}

void angleExtake()
{
  if (stick.GetRawButton(12))
  {
    extakeAngle.Set(.5);
  }
  else if (stick.GetRawButton(8))
  {
    extakeAngle.Set(-.5);
  }
  else if (stick.GetRawButton(10))
  {
    extakeAngle.Set(0);
  }
}

void runIntake() 
{
  intakeCargo();
  angleIntake();
}

void runExtake()
{
  extakeCargo();
  angleExtake();
}

void runHatch()
{
  if (stick.GetPOV() == 0)
  {
    solenoid_top.Set(frc::DoubleSolenoid::kForward);
    solenoid_left.Set(frc::DoubleSolenoid::kForward);
    solenoid_right.Set(frc::DoubleSolenoid::kForward); 
    std::cout << "out" << "\n";
  }
  else if (stick.GetPOV() == 180)
  {
    solenoid_top.Set(frc::DoubleSolenoid::kReverse);
    solenoid_left.Set(frc::DoubleSolenoid::kReverse);
    solenoid_right.Set(frc::DoubleSolenoid::kReverse);
    std::cout << "in" << "\n";
  }
  else
  {
    solenoid_top.Set(frc::DoubleSolenoid::kOff);
    solenoid_left.Set(frc::DoubleSolenoid::kOff);
    solenoid_right.Set(frc::DoubleSolenoid::kOff);
  }
}

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
  drive();
  runHatch();
  runIntake();
  runExtake();
}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif


