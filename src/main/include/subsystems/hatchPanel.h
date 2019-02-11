#pragma once

#include <frc/commands/Subsystem.h>

namespace subsystem{

class HatchPanel: public frc::Subsystem{

public:
    HatchPanel();
    void InitDefaultCommand() override;
    void in();
    void out();
};
}