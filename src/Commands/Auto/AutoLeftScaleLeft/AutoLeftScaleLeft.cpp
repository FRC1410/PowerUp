/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "AutoLeftScaleLeft.h"
#include "AutoLeftScaleLeftCommandGroups/AutoLeftScaleLeftDriveFast.h"
#include "AutoLeftScaleLeftCommandGroups/AutoLeftScaleLeftDriveSlow.h"
#include "AutoLeftScaleLeftCommandGroups/AutoLeftScaleLeftDriveTurn.h"
#include "AutoLeftScaleLeftCommandGroups/AutoLeftScaleLeftClaw.h"
#include "AutoLeftScaleLeftCommandGroups/AutoLeftScaleLeftClimber.h"
#include "AutoLeftScaleLeftCommandGroups/AutoLeftScaleLeftElevator.h"

AutoLeftScaleLeft::AutoLeftScaleLeft() {
	frc::CommandGroup::AddSequential(new AutoLeftScaleLeftClimber, 0.5);
	frc::CommandGroup::AddSequential(new AutoLeftScaleLeftDriveSlow, 2.0);
	frc::CommandGroup::AddSequential(new AutoLeftScaleLeftDriveFast, 8.0);
	frc::CommandGroup::AddSequential(new AutoLeftScaleLeftDriveSlow, 2.0);
	frc::CommandGroup::AddSequential(new AutoLeftScaleLeftDriveTurn, 4.0);
	frc::CommandGroup::AddSequential(new AutoLeftScaleLeftElevator, 3.0);
	frc::CommandGroup::AddSequential(new AutoLeftScaleLeftClaw, 1.0);
}
