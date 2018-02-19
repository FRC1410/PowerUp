#include "AutoCenterScoreSwitchRightDriveFar.h"
#include "AutoCenterScoreSwitchRightDriveFarCommands/AutoCenterScoreSwitchRightDriveForwardsFar.h"

AutoCenterScoreSwitchRightDriveFar::AutoCenterScoreSwitchRightDriveFar() {
	frc::CommandGroup::AddParallel(new AutoCenterScoreSwitchRightDriveForwardsFar(), 12.0);
}
