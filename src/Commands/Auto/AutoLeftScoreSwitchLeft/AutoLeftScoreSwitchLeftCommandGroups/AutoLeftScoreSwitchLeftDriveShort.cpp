#include "AutoLeftScoreSwitchLeftDriveShort.h"
#include "AutoLeftScoreSwitchLeftDriveShortCommands/AutoLeftScoreSwitchLeftDriveForwardsShort.h"

AutoLeftScoreSwitchLeftDriveShort::AutoLeftScoreSwitchLeftDriveShort() {
	frc::CommandGroup::AddParallel(new AutoLeftScoreSwitchLeftDriveForwardsShort(), 3.0);
}
