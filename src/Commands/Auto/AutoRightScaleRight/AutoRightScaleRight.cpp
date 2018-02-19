/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "AutoRightScaleRight.h"
#include "AutoRightScaleRightCommandGroups/AutoRightScaleRightDriveFast.h"
#include "AutoRightScaleRightCommandGroups/AutoRightScaleRightDriveSlow.h"
#include "AutoRightScaleRightCommandGroups/AutoRightScaleRightDriveTurn.h"
#include "AutoRightScaleRightCommandGroups/AutoRightScaleRightClaw.h"
#include "AutoRightScaleRightCommandGroups/AutoRightScaleRightClimber.h"
#include "AutoRightScaleRightCommandGroups/AutoRightScaleRightElevator.h"

AutoRightScaleRight::AutoRightScaleRight() {
	frc::CommandGroup::AddSequential(new AutoRightScaleRightClimber, 0.5);
	frc::CommandGroup::AddSequential(new AutoRightScaleRightDriveSlow, 2.0);
	frc::CommandGroup::AddSequential(new AutoRightScaleRightDriveFast, 8.0);
	frc::CommandGroup::AddSequential(new AutoRightScaleRightDriveSlow, 2.0);
	frc::CommandGroup::AddSequential(new AutoRightScaleRightDriveTurn, 4.0);
	frc::CommandGroup::AddSequential(new AutoRightScaleRightElevator, 3.0);
	frc::CommandGroup::AddSequential(new AutoRightScaleRightClaw, 1.0);
}
