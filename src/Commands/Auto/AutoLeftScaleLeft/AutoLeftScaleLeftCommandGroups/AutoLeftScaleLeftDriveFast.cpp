/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "AutoLeftScaleLeftDriveFast.h"
#include "AutoLeftScaleLeftDriveFastCommands/AutoLeftScaleLeftDriveForwardsFast.h"

AutoLeftScaleLeftDriveFast::AutoLeftScaleLeftDriveFast() {
	frc::CommandGroup::AddParallel(new AutoLeftScaleLeftDriveForwardsFast(), 8.0);
}