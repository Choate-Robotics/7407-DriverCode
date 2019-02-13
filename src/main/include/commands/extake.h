#pragma once

#include <frc/commands/Command.h>

namespace command
{

class ExtakeOutLow : public frc::Command
{
  public:
    ExtakeOutLow();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};

class ExtakeOutHigh : public frc::Command
{
  public:
    ExtakeOutHigh();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};

class ExtakeStop:public frc::Command{
  public:
  ExtakeStop();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};

class ExtakeTiltUp : public frc::Command
{
  public:
    ExtakeTiltUp();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};

class ExtakeTiltDown : public frc::Command
{
  public:
    ExtakeTiltDown();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};

class ExtakeTiltStop:public frc::Command{
  public:
  ExtakeTiltStop();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};


} // namespace command