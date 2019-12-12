#pragma once

#include <frc/TimedRobot.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/PWMVictorSPX.h>
#include <frc/PWMTalonSRX.h>

#include "OI.h"
#include "subsystems/drivetrain.h"

class Robot : public frc::TimedRobot
{

public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  static OI *oi;
  static subsystem::Drivetrain *drivetrain;
};
