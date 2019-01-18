#include "Robot.h"
#include <iostream>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/Joystick.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/PWMVictorSPX.h>
#include <frc/DoubleSolenoid.h>

frc::PWMVictorSPX m_left{0};
frc::PWMVictorSPX m_right{1};
frc::DifferentialDrive m_RobotDrive(m_left, m_right);
frc::Joystick m_stick{0};
frc::DoubleSolenoid m_doubleSolenoid{0,1};

bool Logitech_Stick;

void Robot::RobotInit() {
  Logitech_Stick = true; //m_stick.GetIsXbox();
}

void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() {
  if(Logitech_Stick == false)
  {
    m_RobotDrive.TankDrive(m_stick.GetRawAxis(1), m_stick.GetRawAxis(5)); 
  } 
  else {
    m_RobotDrive.ArcadeDrive(m_stick.GetY(), m_stick.GetX());
  }
}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
