#pragma once

#include <frc/commands/Subsystem.h>
#include <wpi/Twine.h>

namespace subsystem{

class Intake: public frc::Subsystem {
    


    // 0 if the intake is not running, 1 if running forward (in), -1 if running reversed (out)
public:
    enum Direction{
            STOPPED, 
            FORWARD, // in, up
            REVERSED, // out, down
        };
    

    Intake(const wpi::Twine &);
    void InitDefaultCommand() override;
    void in();
    void out();
    void stop();
    void toggle(); //Toggle the state of intake

    inline void tiltUp();
    inline void tiltDown();
    inline void tiltStop();
    void tiltToggle();

    static Intake::Direction runningDirection; 
    static Intake::Direction tiltingDirection;

    // void tilt(double);
    // double getCurrentAngle();
};

}