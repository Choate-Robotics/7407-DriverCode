#include "OI.h"
#include <frc/Joystick.h>
#include <frc/buttons/JoystickButton.h>
#include "RobotMap.h"

OI::OI()
{
    using namespace RobotMap;
    frc::Joystick * joystick[2] = {new frc::Joystick(0), new frc::Joystick(1)};
    joystick[joystick::primaryDrive]->GetAxis(frc::Joystick::kXAxis);

}

OI::OI(int i){}