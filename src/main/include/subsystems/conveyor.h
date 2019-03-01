#pragma once

#include <frc/commands/Subsystem.h>
#include <wpi/Twine.h>

namespace subsystem{

class Conveyor: public frc::Subsystem{

public:
    Conveyor(const wpi::Twine&);
    void InitDefaultCommand() override;
    void move();
};
}