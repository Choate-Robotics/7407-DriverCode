#pragma once

#include <frc/commands/Subsystem.h>

namespace subsystem{

class Drivetrain: public frc::Subsystem{

public:
    Drivetrain();
    void InitDefaultCommand() override;
    void forward(int);
    void reverse(int);
    void stop(); 
};

}