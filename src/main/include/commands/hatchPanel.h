#pragma once

#include <frc/commands/Command.h>

namespace command
{
class hatchPanelIn : public frc::Command
{
  public:
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};

class hatchPanelOut : public frc::Command
{
  public:
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};
} // namespace command