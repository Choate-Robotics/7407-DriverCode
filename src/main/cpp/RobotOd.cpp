/*
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

frc::DoubleSolenoid solenoid_top{1, 0};
frc::DoubleSolenoid solenoid_left{2, 3};
frc::DoubleSolenoid solenoid_right{4, 5};

frc::Joystick drive_stick{1};
frc::Joystick mech_stick{0};

int extakeOut = 8;
int extakeIn = 7;
int intakeOut = 8;
int intakeIn = 7;
int intakeToggle = 2;
int extakeHigh = 5;
int extakeLow = 6;

static constexpr int kDoubleSolenoidForward = 6;
static constexpr int kDoubleSolenoidReverse = 5;

bool intakeRunning = false;
bool intakeButtonAllow = true;
bool extakeHighRunning = false;
bool extakeHighButtonAllow = true;
bool extakeLowRunning = false;
bool extakeLowButtonAllow = true;

void drive()
{

 //RobotDrive.ArcadeDrive(-drive_stick.GetRawAxis(1), drive_stick.GetRawAxis(2)*.70);
 RobotDrive.ArcadeDrive(drive_stick.GetRawAxis(0), drive_stick.GetRawAxis(1));
}

void intakeCargo()
{
  if(mech_stick.GetRawButton(intakeToggle) && intakeRunning == false)
  {
    if(intakeButtonAllow == true)
    {
      intakeMotor.Set(.5);
      intakeRunning = true;
      intakeButtonAllow = false;
    }
  }
  else if(mech_stick.GetRawButton(intakeToggle) && intakeRunning == true)
  {
    if(intakeButtonAllow == true)
    {
      intakeMotor.Set(0);
      intakeRunning = false;
      intakeButtonAllow = false;
    }
  }
  else
  {
    intakeButtonAllow = true;
  }
}

void carryCargo()
{
  conveyorMotor.Set(mech_stick.GetRawAxis(3));
}

void extakeCargo()
{
  if (mech_stick.GetRawButton(extakeLow) && extakeLowRunning == false)
  {
    if (extakeLowButtonAllow == true)
    {
      extakeLeft.Set(.25);
      extakeRight.Set(-.25);
      extakeLowRunning = true;
      extakeLowButtonAllow = false;
      std::cout << "low on" << "\n";
    }
  }
  else if (mech_stick.GetRawButton(extakeLow) && extakeLowRunning == true)
  {
    if (extakeLowButtonAllow == true)
    {
      extakeLeft.Set(0);
      extakeRight.Set(0);
      extakeLowRunning = false;
      extakeLowButtonAllow = false;
      std::cout << "low off" << "\n";
    }
  }
  else
  {
    extakeLowButtonAllow = true;
  }

  if (mech_stick.GetRawButton(extakeHigh) && extakeHighRunning == false)
  {
    if (extakeHighButtonAllow == true)
    {
      extakeLeft.Set(.5);
      extakeRight.Set(-.5);
      extakeHighRunning = true;
      extakeHighButtonAllow = false;
      std::cout << "high on" << "\n";
    }
  }
  else if (mech_stick.GetRawButton(extakeHigh) && extakeHighRunning == true)
  {
    if (extakeHighButtonAllow == true)
    {
      extakeLeft.Set(0);
      extakeRight.Set(0);
      extakeHighRunning = false;
      extakeHighButtonAllow = false;
      std::cout << "high off" << "\n";
    }
  }
  else
  {
    extakeHighButtonAllow = true;
  }
}

void angleExtake()
{
  while (mech_stick.GetRawButton(extakeOut))
  {
    extakeAngle.Set(.3);
  }
  while (mech_stick.GetRawButton(extakeIn))
  {
    extakeAngle.Set(-.3);
  }
    
  extakeAngle.Set(0);
}

void angleIntake()
{
  while (drive_stick.GetRawButton(intakeOut))
  {
    intakeAngle.Set(.5);
  }
  while (drive_stick.GetRawButton(intakeIn))
  {
    intakeAngle.Set(-.4);
  }
  
  intakeAngle.Set(-.05);
}

void runIntake() 
{
  intakeCargo();
  angleIntake();
  carryCargo();
}

void runExtake()
{
  extakeCargo();
  angleExtake();
}

void runHatch()
{
  if (drive_stick.GetRawButton(kDoubleSolenoidForward))
  {
    solenoid_top.Set(frc::DoubleSolenoid::kForward);
    solenoid_left.Set(frc::DoubleSolenoid::kForward);
    solenoid_right.Set(frc::DoubleSolenoid::kForward); 
    std::cout << "out" << "\n";
  }
  else if (drive_stick.GetRawButton(kDoubleSolenoidReverse))
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



*/