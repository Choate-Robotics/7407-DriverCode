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

namespace motor{
extern frc::PWMTalonSRX * frontLeft;
extern frc::PWMTalonSRX * frontRight;
extern frc::PWMTalonSRX * backLeft;
extern frc::PWMTalonSRX * backRight;
extern frc::PWMVictorSPX * conveyor;
extern frc::PWMVictorSPX * intake;
extern frc::PWMVictorSPX * intakeTilt;
extern frc::PWMVictorSPX * extakeTilt;
extern frc::PWMVictorSPX * extake;
extern frc::PWMVictorSPX * hatchRoller;
extern frc::SpeedControllerGroup * left;
extern frc::SpeedControllerGroup * right;
extern frc::DifferentialDrive * differentialDrive;


} // namespace motor

namespace solenoid
{
extern frc::DoubleSolenoid * hatchPanel;
extern frc::DoubleSolenoid * climberFront; 
extern frc::DoubleSolenoid * climberBack;

} // namespace solenoid

#if CURRENT_DRIVER == ALEX_AND_PETER
namespace joystick
{

static constexpr int portPrimary = 0;
static constexpr int portSecondary = 1;

static constexpr int drivetrain = PRIMARY_JOYSTICK;
static constexpr int hatchPanel = PRIMARY_JOYSTICK;

static constexpr int intakeTilt = SECONDARY_JOYSTICK;
static constexpr int intake = SECONDARY_JOYSTICK;
static constexpr int extake = SECONDARY_JOYSTICK;
static constexpr int extakeTilt = SECONDARY_JOYSTICK;
static constexpr int conveyor = SECONDARY_JOYSTICK;
static constexpr int climber = SECONDARY_JOYSTICK; 
} // namespace joystick

namespace keymap
{
namespace button
{
static constexpr int extakeTiltDown = 7;
static constexpr int extakeTiltUp = 8;
static constexpr int extakeStop = 5;
static constexpr int extakeLow = 6;
static constexpr int intakeTiltDown = 3;
static constexpr int intakeTiltUp = 1;
static constexpr int intakeToggle = 2;
static constexpr int hatchPanelIn = 6;
static constexpr int hatchPanelOut = 5;
static constexpr int climberFront = 9;
static constexpr int climberBack = 10;
static constexpr int hatchPanelIntake = 8;
static constexpr int hatchPanelExtake = 7;

} // namespace buttons

namespace axis
{
static constexpr int driveX = 1;
static constexpr int driveY = 2;
static int conveyor = 3;
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