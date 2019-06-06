#pragma once

#include <frc/commands/Subsystem.h>
#include <wpi/Twine.h>

namespace subsystem{

class HatchPanel: public frc::Subsystem{

public:
    HatchPanel(const wpi::Twine &);
    void InitDefaultCommand() override;
    void in();
    void out();

    void intake();
    void extake();
    void hold();
    void off();
};
}