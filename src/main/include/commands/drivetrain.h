#pragma once

#include <frc/commands/Command.h>
#include <frc/drive/DifferentialDrive.h>

namespace command
{

class DriveArcade : public frc::Command
{
  public:

    DriveArcade();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
    bool IsInterruptable() override;
};

class DriveTank : public frc::Command
{
  public:

    DriveTank();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
    bool IsInterruptable() override;
    
};

} // namespace command