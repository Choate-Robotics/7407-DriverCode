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

frc::PWMTalonSRX leftFront{0};
frc::PWMTalonSRX leftBack{2};
frc::PWMTalonSRX rightFront{1};
frc::PWMTalonSRX rightBack{3};

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

frc::Joystick drive_stick{2};
frc::Joystick mech_stick{1};

int extakeOut = 8;
int extakeIn = 7;
int intakeOut = 8;
int intakeIn = 7;
int intakeToggle = 2;
int extakeHigh = 6;
int extakeLow = 5;

std::string stick_type;

static constexpr int kDoubleSolenoidForward = 6;
static constexpr int kDoubleSolenoidReverse = 5;

bool intakeRunning = false;
bool intakeButtonAllow = true;
bool extakeRunning = false;
bool extakeButtonAllow = true;

void drive()
{

 RobotDrive.ArcadeDrive(-drive_stick.GetRawAxis(1), drive_stick.GetRawAxis(4)*.70);

}

void intakeCargo()
{
  if(mech_stick.GetRawButton(intakeToggle) && intakeRunning == false)
  {
    if(intakeButtonAllow == true)
    {
      intakeMotor.Set(.5);
      intakeRunning = false;
      intakeButtonAllow = false;
    }
  }
  else if(mech_stick.GetRawButton(intakeToggle) && intakeRunning == true)
  {
    if(intakeButtonAllow == true)
    {
      intakeMotor.Set(0);
      intakeRunning = true;
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

void extakeCargo(int power, int button)
{
  if (mech_stick.GetRawButton(button) && extakeRunning == false)
  {
    if (extakeButtonAllow == true)
    {
      extakeLeft.Set(power);
      extakeRight.Set(-power);
      extakeRunning = true;
      extakeButtonAllow = false;
    }
  }
  else if (mech_stick.GetRawButton(button) && extakeRunning == true)
  {
    if (extakeButtonAllow == true)
    {
      extakeLeft.Set(0);
      extakeRight.Set(0);
      extakeRunning = false;
      extakeButtonAllow = false;
    }
  }
  else
  {
    extakeButtonAllow = true;
  }
}
/*void extakeCargo()
{
  if(drive_stick.GetRawButton(extakeLow) && extakeRunning == false)
  {
    if(extakeButtonAllow == true)
    {
      extakeRight.Set(-.25);
      extakeLeft.Set(.25);
      extakeRunning = true;
      extakeButtonAllow = false;
    }
  } else if(drive_stick.GetRawButton(extakeHigh))
  {
    if(extakeButtonAllow == true)
    {
      extakeRight.Set(-.75);
      extakeLeft.Set(.75);
      extakeRunning = true;
      extakeButtonAllow = false;
    }
  } else if(drive_stick.GetRawButton(3) && extakeRunning == false)
  {
    if(extakeButtonAllow == true)
    {
      extakeRight.Set(0);
      extakeLeft.Set(0);
      extakeRunning = true;
      extakeButtonAllow = false;
    }
  }else
  {
    extakeButtonAllow = true;
  }
}*/

void angleExtake()
{
  while (mech_stick.GetRawButton(extakeOut))
  {
    extakeAngle.Set(.25);
  }
  while (mech_stick.GetRawButton(extakeIn))
  {
    extakeAngle.Set(-.25);
  }
    
  extakeAngle.Set(0);
}

void angleIntake()
{
  while (drive_stick.GetRawButton(intakeOut))
  {
    intakeAngle.Set(.25);
  }
  while (drive_stick.GetRawButton(intakeIn))
  {
    intakeAngle.Set(-.25);
  }
    
  intakeAngle.Set(0);
}

void runIntake() 
{
  intakeCargo();
  angleIntake();
  carryCargo();
}

void runExtake()
{
  extakeCargo(.25, extakeLow);
  extakeCargo(.75, extakeHigh);
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


