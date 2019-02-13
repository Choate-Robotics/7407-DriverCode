#pragma once

#include <frc/commands/Subsystem.h>
#include <wpi/Twine.h>

namespace subsystem{

class Extake : public frc::Subsystem{
public:

    enum Direction{
            STOPPED, 
            FORWARD, // in, up
            REVERSED, // out, down
        };

    Extake(const wpi::Twine &);
    void InitDefaultCommand() override;
    void outLow();
    void outHigh();
    void stopSpinning();

    void tiltDown();
    void tiltUp();
    void tiltStop();
    void angle(double); // in degrees

    double getCurrentAngle();

    static Extake::Direction runningDirection; 
    static Extake::Direction tiltingDirection;
};
}