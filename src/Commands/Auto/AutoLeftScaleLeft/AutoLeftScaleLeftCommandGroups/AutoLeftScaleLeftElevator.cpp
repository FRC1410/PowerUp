/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "AutoLeftScaleLeftElevator.h"
#include "AutoLeftScaleLeftElevatorCommands/AutoLeftScaleLeftRaiseElevator.h"
#include "AutoLeftScaleLeftElevatorCommands/AutoLeftScaleLeftRotateClaw.h"

AutoLeftScaleLeftElevator::AutoLeftScaleLeftElevator() {
	frc::CommandGroup::AddParallel(new AutoLeftScaleLeftRaiseElevator, 3.0);
	frc::CommandGroup::AddParallel(new AutoLeftScaleLeftRotateClaw, 2.0);
}
