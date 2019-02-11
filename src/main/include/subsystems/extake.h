#pragma once

#include <frc/commands/Subsystem.h>

namespace subsystem{

class Extake : public frc::Subsystem{
public:
    Extake();
    void InitDefaultCommand() override;
    void in();
    void out();
    void stopSpinning();

    void down();
    void up();
    void stop();
    void angle(double); // in degrees

    double getCurrentAngle();
};
}