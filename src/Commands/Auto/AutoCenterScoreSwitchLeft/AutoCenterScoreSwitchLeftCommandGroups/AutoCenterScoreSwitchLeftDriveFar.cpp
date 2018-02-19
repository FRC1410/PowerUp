#include "AutoCenterScoreSwitchLeftDriveFar.h"
#include "AutoCenterScoreSwitchLeftDriveFarCommands/AutoCenterScoreSwitchLeftDriveForwardsFar.h"

AutoCenterScoreSwitchLeftDriveFar::AutoCenterScoreSwitchLeftDriveFar() {
	frc::CommandGroup::AddParallel(new AutoCenterScoreSwitchLeftDriveForwardsFar(), 10.0);
}
