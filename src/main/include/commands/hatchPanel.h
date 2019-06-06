#pragma once

#include <frc/commands/Command.h>

namespace command
{
class hatchPanelIn : public frc::Command
{
  public:
    hatchPanelIn();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};

class hatchPanelOut : public frc::Command
{
  public:
    hatchPanelOut();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};

class hatchPanelRollerIntake : public frc::Command
{
  public:
    hatchPanelRollerIntake();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};

class hatchPanelRollerExtake : public frc::Command
{
  public:
    hatchPanelRollerExtake();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};

class hatchPanelRollerHold : public frc::Command
{
  public:
    hatchPanelRollerHold();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};

class hatchPanelRollerOff : public frc::Command
{
  public:
    hatchPanelRollerOff();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};

} // namespace command