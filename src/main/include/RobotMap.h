#pragma once

#include <frc/Joystick.h>

#define ALEX_AND_PETER 1
#define BELLA_AND_KNUTE 2
#define DI_TIERI 3

#include "current_driver.h"

#ifndef CURRENT_DRIVER
#error CURRENT_DRIVER is undefined.
#endif

namespace RobotMap
{
namespace port
{
static constexpr int FrontLeft = 0;
static constexpr int FrontRight = 1;
static constexpr int BackLeft = 2;
static constexpr int BackRight = 3;

static constexpr int Conveyor = 4;
static constexpr int Intake = 5;
static constexpr int TiltIn = 6;
static constexpr int TiltOut = 7;
static constexpr int OutRight = 8;
static constexpr int OutLeft = 9;
} // namespace port

#if CURRENT_DRIVER == ALEX_AND_PETER
namespace joystick
{
static constexpr int primaryDrive = 0;
}
namespace key
{
    static constexpr frc::Joystick::AxisType
    axisHorizontal=frc::Joystick::kXAxis;
}
#elif CURRENT_DRIVER == BELLA_AND_KNUTE

#elif CURRENT_DRIVER == DI_TIERI

#else
#error CURRENT_DRIVER not recognized
#endif

} // namespace RobotMap

#undef ALEX_AND_PETER
#undef BELLA_AND_KNUTE
#undef DI_TIERI
#undef CURRENT_DRIVER