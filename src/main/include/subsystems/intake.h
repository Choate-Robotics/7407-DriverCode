#pragma once

#include <frc/commands/Subsystem.h>

namespace subsystem{

class Intake: public frc::Subsystem {
public:
    Intake();
    void InitDefaultCommand() override;
    void in();
    void out();
    void stopSpinning();

    void down();
    void up();
    void stop();
    void tilt(double); // in degrees

    double getCurrentAngle();
};

}