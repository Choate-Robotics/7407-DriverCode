#pragma once

#include <frc/TimedRobot.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/PWMVictorSPX.h>
#include <frc/PWMTalonSRX.h>

#include "OI.h"
#include "subsystems/conveyor.h"
#include "subsystems/drivetrain.h"
#include "subsystems/hatchPanel.h"
#include "subsystems/intake.h"
#include "subsystems/extake.h"
#include "subsystems/climber.h"

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
  static OI *oi;
  static subsystem::Conveyor *conveyor;
  static subsystem::Drivetrain *drivetrain;
  static subsystem::Intake *intake;
  static subsystem::HatchPanel *hatchPanel;
  static subsystem::Extake *extake; 
  static subsystem::Climber *climber;
};
