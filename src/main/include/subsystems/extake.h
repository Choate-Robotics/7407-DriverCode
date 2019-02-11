#pragma once

#include <frc/commands/Subsystem.h>
#include <wpi/Twine.h>

namespace subsystem{

class Extake : public frc::Subsystem{
public:
    Extake(const wpi::Twine &);
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