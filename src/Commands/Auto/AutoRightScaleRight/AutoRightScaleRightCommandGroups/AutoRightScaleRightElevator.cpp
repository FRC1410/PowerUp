/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "AutoRightScaleRightElevator.h"
#include "AutoRightScaleRightElevatorCommands/AutoRightScaleRightRaiseElevator.h"
#include "AutoRightScaleRightElevatorCommands/AutoRightScaleRightRotateClaw.h"

AutoRightScaleRightElevator::AutoRightScaleRightElevator() {
	frc::CommandGroup::AddParallel(new AutoRightScaleRightRaiseElevator, 3.0);
	frc::CommandGroup::AddParallel(new AutoRightScaleRightRotateClaw, 2.0);
}
