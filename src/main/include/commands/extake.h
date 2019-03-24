#pragma once

#include <frc/commands/Command.h>

namespace command
{

class ExtakeOutSlow : public frc::Command
{
  public:
    ExtakeOutSlow();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};

class ExtakeOutFast : public frc::Command
{
  public:
    ExtakeOutFast();
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