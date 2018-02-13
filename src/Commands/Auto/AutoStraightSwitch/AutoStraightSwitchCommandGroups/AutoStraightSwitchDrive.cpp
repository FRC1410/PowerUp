#include "AutoStraightSwitchDrive.h"
#include "AutoStraightSwitchDriveCommands/AutoStraightSwitchDriveWheels.h"

AutoStraightSwitchDrive::AutoStraightSwitchDrive() {
	frc::CommandGroup::AddParallel(new AutoStraightSwitchDriveWheels(), 5.0);
}
