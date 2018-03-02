#include "AutoCenterScoreSwitchRightDriveShort.h"
#include "AutoCenterScoreSwitchRightDriveShortCommands/AutoCenterScoreSwitchRightDriveForwardsShort.h"

AutoCenterScoreSwitchRightDriveShort::AutoCenterScoreSwitchRightDriveShort() {
	frc::CommandGroup::AddParallel(new AutoCenterScoreSwitchRightDriveForwardsShort(), 3.0);
}
