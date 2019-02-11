#pragma once

#include <frc/commands/Subsystem.h>
#include <wpi/Twine.h>

namespace subsystem{

class Intake: public frc::Subsystem {
public:
    Intake(const wpi::Twine);
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