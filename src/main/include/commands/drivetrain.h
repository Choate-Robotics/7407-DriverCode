#pragma once

#include <frc/commands/Command.h>
#include <frc/drive/DifferentialDrive.h>

namespace command
{

class Drive : public frc::Command
{
  frc::DifferentialDrive * differentialDrive=nullptr;
  public:
    Drive();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};
} // namespace command