#pragma once

#include <frc/commands/Subsystem.h>
#include <wpi/Twine.h>

namespace subsystem{

class Drivetrain: public frc::Subsystem{

public:

    enum DriveStyle{
            ARCADE,
            TANK // out, down
        };

    Drivetrain(const wpi::Twine &);
    void InitDefaultCommand() override;
    void forward(int);
    void reverse(int);
    void stop(); 
    void switchDrive();

    static Drivetrain::DriveStyle currentDriveStyle; 
};

}