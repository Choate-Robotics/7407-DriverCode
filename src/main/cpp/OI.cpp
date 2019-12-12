#include "OI.h"
#include <frc/Joystick.h>
#include <frc/buttons/JoystickButton.h>
#include "RobotMap.h"
#include "commands/drivetrain.h"


frc::Joystick *OI::joystick[2] = {nullptr};

OI::OI()
{
    using namespace RobotMap;
    this->joystick[PRIMARY_JOYSTICK] = new frc::Joystick{joystick::portPrimary};
    this->joystick[SECONDARY_JOYSTICK] = new frc::Joystick{joystick::portSecondary};

}
