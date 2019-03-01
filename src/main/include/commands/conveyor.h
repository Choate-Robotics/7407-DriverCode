#pragma once

#include <frc/commands/Command.h>

namespace command
{
  class ConveyorMove : public frc::Command
  {
  public:
    ConveyorMove();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
  };
}