#include "AutoRightScoreSwitchRightDriveFar.h"
#include "AutoRightScoreSwitchRightDriveFarCommands/AutoRightScoreSwitchRightDriveForwardsFar.h"

AutoRightScoreSwitchRightDriveFar::AutoRightScoreSwitchRightDriveFar() {
	frc::CommandGroup::AddParallel(new AutoRightScoreSwitchRightDriveForwardsFar(), 12.0);
}
