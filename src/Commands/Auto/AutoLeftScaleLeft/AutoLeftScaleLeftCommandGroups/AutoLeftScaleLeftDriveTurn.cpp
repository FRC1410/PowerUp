/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "AutoLeftScaleLeftDriveTurn.h"
#include "AutoLeftScaleLeftTurnRightCommands/AutoLeftScaleLeftTurnRight.h"

AutoLeftScaleLeftDriveTurn::AutoLeftScaleLeftDriveTurn() {
	frc::CommandGroup::AddParallel(new AutoLeftScaleLeftTurnRight(), 4.0);
}
