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
frc::PWMTalonSRX leftBack{2};
frc::PWMTalonSRX rightFront{1};
frc::PWMTalonSRX rightBack{3};*/

frc::PWMTalonSRX leftFront{0};
frc::PWMVictorSPX leftBack{2};
frc::PWMVictorSPX rightFront{1};
frc::PWMTalonSRX rightBack{3};

frc::PWMVictorSPX conveyorMotor{4};
frc::PWMVictorSPX intakeMotor{5};
frc::PWMVictorSPX intakeAngle{6};
frc::PWMTalonSRX extakeAngle{7};
frc::PWMVictorSPX extakeRight{8};
frc::PWMVictorSPX extakeLeft{9};

frc::SpeedControllerGroup left{leftFront, leftBack};
frc::SpeedControllerGroup right{rightFront, rightBack};
frc::DifferentialDrive RobotDrive(left, right);

frc::SpeedControllerGroup extake{extakeLeft, extakeRight};

frc::DoubleSolenoid solenoid_top{1, 0};
frc::DoubleSolenoid solenoid_front{2, 3};
frc::DoubleSolenoid solenoid_back{4, 5};

frc::Joystick drive_stick{1};
frc::Joystick mech_stick{0};

int extakeOut = 8;
int extakeIn = 7;
int intakeOut = 8;
int intakeIn = 7;
int intakeToggle = 2;
int extakeHigh = 5;
int extakeLow = 6;

static constexpr int kDoubleSolenoidForward = 5;
static constexpr int kDoubleSolenoidReverse = 6;

bool intakeRunning = false;
bool intakeButtonAllow = true;
bool extakeHighRunning = false;
bool extakeHighButtonAllow = true;
bool extakeLowRunning = false;
bool extakeLowButtonAllow = true;
bool frontRunning = true;
bool frontButtonAllow = true;
bool backRunning = true;
bool backButtonAllow = true;


void drive()
{

 RobotDrive.ArcadeDrive(-drive_stick.GetRawAxis(1), drive_stick.GetRawAxis(2)*.80);
 //RobotDrive.ArcadeDrive(-drive_stick.GetRawAxis(1), drive_stick.GetRawAxis(2));
}

void intakeCargo()
{
  if(mech_stick.GetRawButton(intakeToggle) && intakeRunning == false)
  {
    if(intakeButtonAllow == true)
    {
      intakeMotor.Set(-.5);
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
  conveyorMotor.Set(-mech_stick.GetRawAxis(3));
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
    std::cout << "out" << "\n";
  }
  else if (drive_stick.GetRawButton(kDoubleSolenoidReverse))
  {
    solenoid_top.Set(frc::DoubleSolenoid::kReverse);
    std::cout << "in" << "\n";
  }
  else
  {
    solenoid_top.Set(frc::DoubleSolenoid::kOff);
  }
}

void frontHAB(){

    if(mech_stick.GetRawButton(9) && frontRunning == false)
    {
        if(frontButtonAllow == true)
        {
        solenoid_front.Set(frc::DoubleSolenoid::kForward);
        frontRunning = true;
        frontButtonAllow = false;
        }
    }
    else if(mech_stick.GetRawButton(9) && frontRunning == true)
    {
        if(frontButtonAllow == true)
        {
        solenoid_front.Set(frc::DoubleSolenoid::kReverse);
        frontRunning = false;
        frontButtonAllow = false;
        }
    }
    else
    {
        frontButtonAllow = true;
    }

}

void backHAB(){

    if(mech_stick.GetRawButton(10) && backRunning == false)
    {
        if(backButtonAllow == true)
        {
        solenoid_back.Set(frc::DoubleSolenoid::kForward);
        backRunning = true;
        backButtonAllow = false;
        }
    }
    else if(mech_stick.GetRawButton(10) && backRunning == true)
    {
        if(backButtonAllow == true)
        {
        solenoid_back.Set(frc::DoubleSolenoid::kReverse);
        backRunning = false;
        backButtonAllow = false;
        }
    }
    else
    {
        backButtonAllow = true;
    }
}



void Robot::RobotInit()
{
}

void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {
 solenoid_front.Set(frc::DoubleSolenoid::kReverse);
 solenoid_back.Set(frc::DoubleSolenoid::kReverse); 
 }

void Robot::TeleopPeriodic()
{
  drive();
  runHatch();
  runIntake();
  runExtake();
  frontHAB();
  backHAB();
}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif


