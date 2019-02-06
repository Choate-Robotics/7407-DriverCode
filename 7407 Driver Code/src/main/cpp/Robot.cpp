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

/* Intake: On (3), Off (5)
   Extake: On (4), Off (6)
   Conveyor: On (Trigger), Off (2)
   Intake arm: Forward(11), Off(9), Backward(7)
   Extake arm: Forward(12), Off(10), Backward(8)
   Pneumatics: Forward(Toggle forward), Backward(Toggle backward)

frc::PWMTalonSRX leftFront{0};
frc::PWMTalonSRX leftBack{2};
frc::PWMTalonSRX rightFront{1};
frc::PWMTalonSRX rightBack{3};
*/

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

frc::DoubleSolenoid solenoid_top{0, 1};
frc::DoubleSolenoid solenoid_left{2, 3};
frc::DoubleSolenoid solenoid_right{4, 5};

frc::Joystick stick{2};

std::string stick_type;

static constexpr int kDoubleSolenoidForward = 5;
static constexpr int kDoubleSolenoidReverse = 6;

bool intakeVar = true;
bool intakeButtonAllow = true;
bool extakeVar = true;
bool extakeButtonAllow = true;

void drive()
{

 RobotDrive.TankDrive(-stick.GetRawAxis(1), -stick.GetRawAxis(5));

}

void intakeCargo()
{
  if(stick.GetRawButton(1) && intakeVar == true)
  {
    if(intakeButtonAllow == true){
    intakeMotor.Set(.5);
    intakeVar = false;
    intakeButtonAllow = false;
    }
  }
  else if(stick.GetRawButton(1) && intakeVar == false)
  {
    if(intakeButtonAllow == true)
    {
      intakeMotor.Set(0);
      intakeVar = true;
      intakeButtonAllow = false;
    }
  }else
  {
    intakeButtonAllow = true;
  }
}

void carryCargo()
{
  if(stick.GetRawAxis(2) > 0)
  {
   conveyorMotor.Set(-stick.GetRawAxis(2));
  }else if(stick.GetRawAxis(3) > 0)
  {
    conveyorMotor.Set(stick.GetRawAxis(3));
  }else
  {
    conveyorMotor.Set(0);
  }
}

void extakeCargo()
{
  if(stick.GetRawButton(3) && extakeVar == true)
  {
    if(extakeButtonAllow == true)
    {
      extakeRight.Set(-.5);
      extakeLeft.Set(.5);
      extakeVar = false;
      extakeButtonAllow = false;
    }
  }else if(stick.GetRawButton(4))
  {
    if(extakeButtonAllow == true)
    {
      extakeRight.Set(-.75);
      extakeLeft.Set(.75);
      extakeVar = false;
      extakeButtonAllow = false;
    }
  }else if(stick.GetRawButton(3) && extakeVar == false)
  {
    if(extakeButtonAllow == true)
    {
      extakeRight.Set(0);
      extakeLeft.Set(0);
      extakeVar = true;
      extakeButtonAllow = false;
    }
  }else
  {
    extakeButtonAllow = true;
  }
}

void angleIntake()
{
  if (stick.GetRawButton(5))
  {
    intakeAngle.Set(.3);
  }
  else if (stick.GetRawButton(6))
  {
    intakeAngle.Set(-.5);
  }
  else
  {
    intakeAngle.Set(-.05);
  }
}

void angleExtake()
{
  if (stick.GetRawButton(7))
  {
    extakeAngle.Set(.25);
  }
  else if (stick.GetRawButton(8))
  {
    extakeAngle.Set(-.25);
  }
  else
  {
    extakeAngle.Set(0);
  }
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
  if (stick.GetPOV() == 180)
  {
    solenoid_top.Set(frc::DoubleSolenoid::kForward);
    solenoid_left.Set(frc::DoubleSolenoid::kForward);
    solenoid_right.Set(frc::DoubleSolenoid::kForward); 
    std::cout << "out" << "\n";
  }
  else if (stick.GetPOV() == 0)
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


