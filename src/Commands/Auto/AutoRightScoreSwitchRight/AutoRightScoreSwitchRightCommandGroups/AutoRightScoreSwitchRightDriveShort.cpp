#include "AutoRightScoreSwitchRightDriveShort.h"
#include "AutoRightScoreSwitchRightDriveShortCommands/AutoRightScoreSwitchRightDriveForwardsShort.h"

AutoRightScoreSwitchRightDriveShort::AutoRightScoreSwitchRightDriveShort() {
	frc::CommandGroup::AddParallel(new AutoRightScoreSwitchRightDriveForwardsShort(), 5.0);
}
