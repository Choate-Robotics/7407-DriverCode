#include "Robot.h"
#include <iostream>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/Joystick.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/PWMVictorSPX.h>
#include <frc/PWMTalonSRX.h>
#include <frc/SpeedControllerGroup.h>
#include <frc/DoubleSolenoid.h>
#include <string.h>
#include <chrono>
//#define DEBUG
/*
frc::PWMTalonSRX leftFront{0};
frc::PWMTalonSRX leftBack{2};
frc::PWMTalonSRX rightFront{1};
frc::PWMTalonSRX rightBack{3};*/

frc::PWMTalonSRX leftFront{0};
frc::PWMVictorSPX leftBack{2};
frc::PWMVictorSPX rightFront{1};
frc::PWMTalonSRX rightBack{3};

frc::PWMVictorSPX conveyorMotor{4};
frc::PWMVictorSPX intakeMotor{5};
frc::PWMVictorSPX intakeAngle{6};
frc::PWMTalonSRX extakeAngle{7};
frc::PWMVictorSPX extakeRight{8};
frc::PWMVictorSPX extakeLeft{9};

frc::SpeedControllerGroup left{leftFront, leftBack};
frc::SpeedControllerGroup right{rightFront, rightBack};
frc::DifferentialDrive RobotDrive(left, right);

frc::SpeedControllerGroup extake{extakeLeft, extakeRight};

frc::DoubleSolenoid solenoid_top{1, 0};
frc::DoubleSolenoid solenoid_front{2, 3};
frc::DoubleSolenoid solenoid_back{4, 5};

frc::Joystick drive_stick{1};
frc::Joystick mech_stick{0};

int extakeOut = 8;
int extakeIn = 7;
int intakeOut = 8;
int intakeIn = 7;
int intakeToggle = 2;
int extakeHigh = 6;
int extakeLow = 5;

static constexpr int kDoubleSolenoidForward = 5;
static constexpr int kDoubleSolenoidReverse = 6;

bool intakeRunning = false;
bool intakeButtonAllow = true;
bool extakeHighRunning = false;
bool extakeHighButtonAllow = true;
bool extakeLowRunning = false;
bool extakeLowButtonAllow = true;
bool frontRunning = false;
bool frontButtonAllow = true;
bool backRunning = false;
bool backButtonAllow = true;

double speedRamp(const double rawPower, std::chrono::milliseconds timeChanged)
{
    using namespace std::chrono;
    const static auto threshold = milliseconds(1000);
    if (timeChanged > threshold)
        return rawPower;
    double ratio = (double)timeChanged.count() / (double)threshold.count();
    ratio = ratio > 0.4 ? ratio : 0.4;
    double output = ratio * rawPower;
#ifdef DEBUG
    std::printf("time:%i, Ratio: %f, Raw power: %f, converted: %f\n", timeChanged.count(), ratio, rawPower, output);
    std::cout << rawPower << std::endl;
#endif
    return output;
}

std::chrono::time_point<std::chrono::high_resolution_clock> correctionStarted;

void driveNoSpeedRamp()
{
    double move = -drive_stick.GetRawAxis(1) * 0.84;
    double rotate = drive_stick.GetRawAxis(2) * 0.9;
    RobotDrive.ArcadeDrive(move, rotate);
}

void drive()
{

    using namespace std::chrono;
    static double last_move = 0;

    double move = -drive_stick.GetRawAxis(1);
    double rotate = drive_stick.GetRawAxis(2) * .80;
    if (last_move <= 0.01 && last_move >= -0.01)
    {
        correctionStarted = high_resolution_clock::now();
#ifdef DEBUG
        std::printf("Correction started.\n");
#endif
    }
#ifdef DEBUG
    std::printf("Last move: %f, m*l: %f\n", last_move, move * last_move);
#endif
    last_move = move;

    double corrected = speedRamp(move, duration_cast<milliseconds>(high_resolution_clock::now() - correctionStarted));

    RobotDrive.ArcadeDrive(corrected, rotate);
    //RobotDrive.ArcadeDrive(-drive_stick.GetRawAxis(1), drive_stick.GetRawAxis(2));
}

void intakeCargo()
{
    if (mech_stick.GetRawButton(intakeToggle) && intakeRunning == false)
    {
        if (intakeButtonAllow == true)
        {
            intakeMotor.Set(-.5);
            intakeRunning = true;
            intakeButtonAllow = false;
        }
    }
    else if (mech_stick.GetRawButton(intakeToggle) && intakeRunning == true)
    {
        if (intakeButtonAllow == true)
        {
            intakeMotor.Set(0);
            intakeRunning = false;
            intakeButtonAllow = false;
        }
    }
    else
    {
        intakeButtonAllow = true;
    }
}

void carryCargo()
{
    conveyorMotor.Set(-mech_stick.GetRawAxis(3));
}

void extakeCargo()
{
    if (mech_stick.GetRawButton(extakeLow) && !extakeLowRunning)
    {
        if (extakeLowButtonAllow == true)
        {
            extakeLeft.Set(.25);
            extakeRight.Set(-.25);
            extakeLowRunning = true;
            extakeLowButtonAllow = false;
            std::cout << "low on"
                      << "\n";
        }
    }
    else if (mech_stick.GetRawButton(extakeLow) && extakeLowRunning)
    {
        if (extakeLowButtonAllow == true)
        {
            extakeLeft.Set(0);
            extakeRight.Set(0);
            extakeLowRunning = false;
            extakeLowButtonAllow = false;
            std::cout << "low off"
                      << "\n";
        }
    }
    else
    {
        extakeLowButtonAllow = true;
    }

    if (mech_stick.GetRawButton(extakeHigh) && !extakeHighRunning)
    {
        if (extakeHighButtonAllow == true)
        {
            extakeLeft.Set(.5);
            extakeRight.Set(-.5);
            extakeHighRunning = true;
            extakeHighButtonAllow = false;
            std::cout << "high on"
                      << "\n";
        }
    }
    else if (mech_stick.GetRawButton(extakeHigh) && extakeHighRunning )
       {
        if (extakeHighButtonAllow == true)
        {
            extakeLeft.Set(0);
            extakeRight.Set(0);
            extakeHighRunning = false;
            extakeHighButtonAllow = false;
            std::cout << "high off"
                      << "\n";
        }
    }
    else
    {
        extakeHighButtonAllow = true;
    }
}

void angleExtake()
{
    while (mech_stick.GetRawButton(extakeOut))
    {
        extakeAngle.Set(.3);
    }
    while (mech_stick.GetRawButton(extakeIn))
    {
        extakeAngle.Set(-.3);
    }

    extakeAngle.Set(0);
}

void angleIntake()
{
    while (drive_stick.GetRawButton(intakeOut))
    {
        intakeAngle.Set(.5);
    }
    while (drive_stick.GetRawButton(intakeIn))
    {
        intakeAngle.Set(-.4);
    }

    intakeAngle.Set(-.05);
}

void runIntake()
{
    intakeCargo();
    angleIntake();
    carryCargo();
}

void runExtake()
{
    extakeCargo();
    angleExtake();
}

void runHatch()
{
    if (drive_stick.GetRawButton(kDoubleSolenoidForward))
    {
        solenoid_top.Set(frc::DoubleSolenoid::kForward);
#ifdef DEBUG
        std::cout << "out"
                  << "\n";
#endif
    }
    else if (drive_stick.GetRawButton(kDoubleSolenoidReverse))
    {
        solenoid_top.Set(frc::DoubleSolenoid::kReverse);
#ifdef DEBUG
        std::cout << "in"
                  << "\n";
#endif
    }
    else
    {
        solenoid_top.Set(frc::DoubleSolenoid::kOff);
    }
}

void frontHAB()
{

    if (mech_stick.GetRawButton(9) && frontRunning == false)
    {
        if (frontButtonAllow == true)
        {
            solenoid_front.Set(frc::DoubleSolenoid::kForward);
            frontRunning = true;
            frontButtonAllow = false;
        }
    }
    else if (mech_stick.GetRawButton(9) && frontRunning == true)
    {
        if (frontButtonAllow == true)
        {
            solenoid_front.Set(frc::DoubleSolenoid::kReverse);
            frontRunning = false;
            frontButtonAllow = false;
        }
    }
    else
    {
        frontButtonAllow = true;
    }
}

void backHAB()
{

    if (mech_stick.GetRawButton(10) && backRunning == false)
    {
        if (backButtonAllow == true)
        {
            solenoid_back.Set(frc::DoubleSolenoid::kForward);
            backRunning = true;
            backButtonAllow = false;
        }
    }
    else if (mech_stick.GetRawButton(10) && backRunning == true)
    {
        if (backButtonAllow == true)
        {
            solenoid_back.Set(frc::DoubleSolenoid::kReverse);
            backRunning = false;
            backButtonAllow = false;
        }
    }
    else
    {
        backButtonAllow = true;
    }
}

void Robot::RobotInit()
{
}

void Robot::RobotPeriodic() {}

void Robot::AutonomousInit()
{
    solenoid_front.Set(frc::DoubleSolenoid::kReverse);
    solenoid_back.Set(frc::DoubleSolenoid::kReverse);
}

void Robot::AutonomousPeriodic()
{
    driveNoSpeedRamp();
    runHatch();
    runIntake();
    runExtake();
    frontHAB();
    backHAB();
}

void Robot::TeleopInit()
{
    solenoid_front.Set(frc::DoubleSolenoid::kReverse);
    solenoid_back.Set(frc::DoubleSolenoid::kReverse);
}

void Robot::TeleopPeriodic()
{
    driveNoSpeedRamp();
    runHatch();
    runIntake();
    runExtake();
    frontHAB();
    backHAB();
}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main()
{
    return frc::StartRobot<Robot>();
}
#endif
