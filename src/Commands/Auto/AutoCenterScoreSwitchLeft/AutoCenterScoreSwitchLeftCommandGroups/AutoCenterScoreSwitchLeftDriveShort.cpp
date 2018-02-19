#include "AutoCenterScoreSwitchLeftDriveShort.h"
#include "AutoCenterScoreSwitchLeftDriveShortCommands/AutoCenterScoreSwitchLeftDriveForwardsShort.h"

AutoCenterScoreSwitchLeftDriveShort::AutoCenterScoreSwitchLeftDriveShort() {
	frc::CommandGroup::AddParallel(new AutoCenterScoreSwitchLeftDriveForwardsShort(), 5.0);
}
