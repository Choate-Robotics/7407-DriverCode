#pragma once

#include <frc/Joystick.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/PWMVictorSPX.h>
#include <frc/PWMTalonSRX.h>
#include <frc/DoubleSolenoid.h>
#include <frc/SpeedControllerGroup.h>

#define ALEX_AND_PETER 1
#define BELLA_AND_KNUTE 2
#define DI_TIERI 3

#define PRIMARY_JOYSTICK 0
#define SECONDARY_JOYSTICK 1

#include "current_driver.h"

#ifndef CURRENT_DRIVER
#error CURRENT_DRIVER is undefined.
#endif

namespace RobotMap
{

namespace motor
{

static frc::PWMTalonSRX frontLeft = frc::PWMTalonSRX{0};
static frc::PWMTalonSRX frontRight = frc::PWMTalonSRX{1};
static frc::PWMTalonSRX backLeft = frc::PWMTalonSRX{2};
static frc::PWMTalonSRX backRight = frc::PWMTalonSRX{3};

static frc::PWMVictorSPX conveyor = frc::PWMVictorSPX{4};
static frc::PWMVictorSPX intake = frc::PWMVictorSPX{5};
static frc::PWMVictorSPX intakeTilt = frc::PWMVictorSPX{6};
static frc::PWMVictorSPX extakeTilt = frc::PWMVictorSPX{7};
static frc::PWMVictorSPX extakeLeft = frc::PWMVictorSPX{8};
static frc::PWMVictorSPX extakeRight = frc::PWMVictorSPX{9};

static frc::SpeedControllerGroup left = frc::SpeedControllerGroup{frontLeft,backLeft};
static frc::SpeedControllerGroup right = frc::SpeedControllerGroup{frontRight,backRight};

} // namespace motor

namespace solenoid
{
static frc::DoubleSolenoid top = frc::DoubleSolenoid{1, 0};
static frc::DoubleSolenoid left = frc::DoubleSolenoid{2, 3};
static frc::DoubleSolenoid right = frc::DoubleSolenoid{4, 5};
} // namespace solenoid

#if CURRENT_DRIVER == ALEX_AND_PETER
namespace joystick
{

static constexpr int portPrimary = 0;
static constexpr int portSecondary = 1;

static constexpr int drivetrain = PRIMARY_JOYSTICK;
static constexpr int intakeTilt = PRIMARY_JOYSTICK;
static constexpr int hatchPanel = PRIMARY_JOYSTICK;

static constexpr int intake = SECONDARY_JOYSTICK;
static constexpr int extake = SECONDARY_JOYSTICK;
static constexpr int extakeTilt = SECONDARY_JOYSTICK;
static constexpr int conveyor = SECONDARY_JOYSTICK;
} // namespace joystick

namespace keymap
{
namespace button
{
static constexpr int extakeTiltDown = 7;
static constexpr int extakeTiltUp = 8;
static constexpr int extakeHigh = 5;
static constexpr int extakeLow = 6;
static constexpr int intakeTiltDown = 8;
static constexpr int intakeTiltUp = 7;
static constexpr int intakeToggle = 2;
static constexpr int hatchPanelIn = 5;
static constexpr int hatchPanelOut = 6;

} // namespace buttons

namespace axis
{
static constexpr int driveX = 0;
static constexpr int driveY = 1;
static constexpr int conveyor = 3;
} // namespace axis
} // namespace keymap

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