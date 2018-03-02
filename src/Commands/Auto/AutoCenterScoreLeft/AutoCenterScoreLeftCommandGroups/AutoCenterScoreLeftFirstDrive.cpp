#include <Commands/Auto/AutoCenterScoreLeft/AutoCenterScoreLeftCommandGroups/AutoCenterScoreLeftFirstDrive.h>
#include "AutoCenterScoreLeftFirstDriveCommands/AutoCenterScoreLeftFirstDriveWheels.h"

AutoCenterScoreLeftFirstDrive::AutoCenterScoreLeftFirstDrive() {
	frc::CommandGroup::AddParallel(new AutoCenterScoreLeftFirstDriveWheels(), 10.0);
}
