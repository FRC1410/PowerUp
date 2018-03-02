#include "AutoLeftScoreSwitchLeftDriveFar.h"
#include "AutoLeftScoreSwitchLeftDriveFarCommands/AutoLeftScoreSwitchLeftDriveForwardsFar.h"

AutoLeftScoreSwitchLeftDriveFar::AutoLeftScoreSwitchLeftDriveFar() {
	frc::CommandGroup::AddParallel(new AutoLeftScoreSwitchLeftDriveForwardsFar(), 5.0);
}
