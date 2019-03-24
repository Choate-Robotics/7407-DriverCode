#pragma once

#include <frc/commands/Subsystem.h>
#include <wpi/Twine.h>

namespace subsystem{

class Extake : public frc::Subsystem{
public:

    enum Direction{
            STOPPED,
            FORWARD, 
            FORWARD_SLOW, // out, up
            FORWARD_FAST,
            REVERSED, // in, down
        };

    Extake(const wpi::Twine &);
    void InitDefaultCommand() override;
    void outSlow();
    void outFast();
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