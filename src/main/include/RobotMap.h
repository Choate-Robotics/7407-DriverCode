#pragma once

#include <frc/Joystick.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/PWMVictorSPX.h>
#include <frc/PWMTalonSRX.h>
#include <DoubleSolenoid.h>

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

static const frc::PWMTalonSRX frontLeft = frc::PWMTalonSRX{0};
static const frc::PWMTalonSRX frontRight = frc::PWMTalonSRX{1};
static const frc::PWMTalonSRX backLeft = frc::PWMTalonSRX{2};
static const frc::PWMTalonSRX backRight = frc::PWMTalonSRX{3};

static const frc::PWMVictorSPX conveyor = frc::PWMVictorSPX{4};
static const frc::PWMVictorSPX intake = frc::PWMVictorSPX{5};
static const frc::PWMVictorSPX intakeTilt = frc::PWMVictorSPX{6};
static const frc::PWMVictorSPX extakeTilt = frc::PWMVictorSPX{7};
static const frc::PWMVictorSPX extakeLeft = frc::PWMVictorSPX{8};
static const frc::PWMVictorSPX extakeRight = frc::PWMVictorSPX{9};

static constexpr int solenoidTop[2] = {1, 0};
static constexpr int solenoidLeft[2] = {2, 3};
static constexpr int solenoidRight[2] = {4, 5};
} // namespace motor

namespace solenoid
{
static const frc::DoubleSolenoid top = frc::DoubleSolenoid{1, 0};
static const frc::DoubleSolenoid left = frc::DoubleSolenoid{2, 3};
static const frc::DoubleSolenoid right = frc::DoubleSolenoid{4, 5};
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
static constexpr int extakeTitlDown = 7;
static constexpr int extakeTitlUp = 8;
static constexpr int extakeHigh = 5;
static constexpr int extakeLow = 6;
static constexpr int intakeTitlDown = 8;
static constexpr int intakeTitlUp = 7;
static constexpr int intakeToggle = 2;
static constexpr int hatchPanelIn = 5;
static constexpr int hatchPanelOut = 6;

} // namespace buttons

namespace axis
{
static constexpr int driveX = 1;
static constexpr int driveY = 2;
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