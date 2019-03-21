#pragma once

#include <frc/commands/Command.h>

namespace command
{
class climberFrontToggle : public frc::Command
{
  public:
    climberFrontToggle();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};

class climberBackToggle : public frc::Command
{
  public:
    climberBackToggle();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};
} // namespace command