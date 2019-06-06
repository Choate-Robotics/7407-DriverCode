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

class hatchPanelIntake : public frc::Command
{
  public:
    hatchPanelIntake();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};

class hatchPanelExtake : public frc::Command
{
  public:
    hatchPanelExtake();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};

class hatchPanelHold : public frc::Command
{
  public:
    hatchPanelHold();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};

class hatchPanelOff : public frc::Command
{
  public:
    hatchPanelOff();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};

} // namespace command