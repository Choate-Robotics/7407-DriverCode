#pragma once

#include <frc/commands/Command.h>

namespace command
{

class IntakeIn : public frc::Command
{
  public:
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};

class IntakeOut : public frc::Command
{
  public:
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};

class IntakeTilt : public frc::Command
{
  public:
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};

} // namespace command