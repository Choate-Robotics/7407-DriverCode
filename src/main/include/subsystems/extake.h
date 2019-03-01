#pragma once

#include <frc/commands/Subsystem.h>
#include <wpi/Twine.h>

namespace subsystem{

class Extake : public frc::Subsystem{
public:

    enum Direction{
            STOPPED, 
            FORWARD, // out, up
            REVERSED, // in, down
        };

    Extake(const wpi::Twine &);
    void InitDefaultCommand() override;
    void outLow();
    void outHigh();
    void stop();

    void tiltDown();
    void tiltUp();
    void tiltStop();
    
    // void angle(double); // in degrees
    // double getCurrentAngle();

    static Extake::Direction runningDirection; 
    static Extake::Direction tiltingDirection;
};
}