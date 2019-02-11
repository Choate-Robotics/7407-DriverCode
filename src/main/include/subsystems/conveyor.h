#pragma once

#include <frc/commands/Subsystem.h>

namespace subsystem{

class Conveyor: public frc::Subsystem{

public:
    Conveyor();
    void InitDefaultCommand() override;
    void forward();
    void reverse();
    void stop(); 
};
}