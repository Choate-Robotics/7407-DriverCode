#pragma once

#include <frc/commands/Command.h>

namespace command
{

class ExtakeIn : public frc::Command
{
  public:
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};

class ExtakeOut : public frc::Command
{
  public:
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};

class ExtakeTiltUp : public frc::Command
{
  public:
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};

class ExtakeTiltDown : public frc::Command
{
  public:
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};

} // namespace command