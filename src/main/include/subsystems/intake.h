#pragma once

#include <frc/commands/Subsystem.h>
#include <wpi/Twine.h>

namespace subsystem{

class Intake: public frc::Subsystem {
    enum Direction{
        STOPPED, 
        FORWARD, // in, up
        REVERSED, // out, down
    };
    static Intake::Direction runningDirection; 
    static Intake::Direction tiltingDirection;

    // 0 if the intake is not running, 1 if running forward (in), -1 if running reversed (out)
public:
    Intake(const wpi::Twine &);
    void InitDefaultCommand() override;
    inline void in();
    inline void out();
    inline void stop();
    void toggle(); //Toggle the state of intake

    inline void tiltUp();
    inline void tiltDown();
    inline void tiltStop();
    void tiltToggle();

    // void tilt(double);
    // double getCurrentAngle();
};

}