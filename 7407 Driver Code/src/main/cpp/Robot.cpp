/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

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

std::string stick_type;

void Robot::RobotInit() {
  stick_type = m_stick.GetName;
}

void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() {
  if(stick_type == "XboxJoystick")
  {
    //m_RobotDrive.TankDrive(m_stick.GetY(), m_stick.GetX());
  } 
  else {
    m_RobotDrive.ArcadeDrive(m_stick.GetY(), m_stick.GetX());
  }


}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
