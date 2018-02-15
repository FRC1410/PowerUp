#include "AutoCrossBaselineDrive.h"
#include "AutoCrossBaselineDriveCommands/AutoCrossBaselineDriveWheels.h"

AutoCrossBaselineDrive::AutoCrossBaselineDrive() {
	frc::CommandGroup::AddParallel(new AutoCrossBaselineDriveWheels(), 5.0);
}
