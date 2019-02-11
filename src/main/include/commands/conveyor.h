#pragma once

#include <frc/commands/Command.h>

namespace command
{

class ConveyorUp : public frc::Command
{
public:
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};

class ConveyorDown : public frc::Command
{
public:
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};

class ConveyorStop : public frc::Command
{
public:
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
} // namespace command