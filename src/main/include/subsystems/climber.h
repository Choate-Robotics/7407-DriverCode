#pragma once

#include <frc/commands/Subsystem.h>
#include <wpi/Twine.h>

namespace subsystem
{

class Climber : public frc::Subsystem
{

  public:
    Climber(const wpi::Twine &);
    bool frontFired;
    bool backFired;
    void InitDefaultCommand() override;
    void frontToggle();
    void backToggle();
};
} // namespace subsystem