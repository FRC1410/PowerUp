#include "AutoLeftScoreSwitchLeft.h"
#include "AutoLeftScoreSwitchLeftCommandGroups/AutoLeftScoreSwitchLeftDriveFar.h"
#include "AutoLeftScoreSwitchLeftCommandGroups/AutoLeftScoreSwitchLeftDriveShort.h"
#include "AutoLeftScoreSwitchLeftCommandGroups/AutoLeftScoreSwitchLeftDriveTurn.h"
#include "AutoLeftScoreSwitchLeftCommandGroups/AutoLeftScoreSwitchLeftClaw.h"
#include "AutoLeftScoreSwitchLeftCommandGroups/AutoLeftScoreSwitchLeftClimber.h"
#include "AutoLeftScoreSwitchLeftCommandGroups/AutoLeftScoreSwitchLeftElevator.h"

AutoLeftScoreSwitchLeft::AutoLeftScoreSwitchLeft() {
	frc::CommandGroup::AddSequential(new AutoLeftScoreSwitchLeftClimber, 0.5);
	frc::CommandGroup::AddSequential(new AutoLeftScoreSwitchLeftDriveFar, 12.0);
	frc::CommandGroup::AddSequential(new AutoLeftScoreSwitchLeftDriveTurn, 4.0);
	frc::CommandGroup::AddSequential(new AutoLeftScoreSwitchLeftDriveShort, 3.0);
	frc::CommandGroup::AddSequential(new AutoLeftScoreSwitchLeftElevator, 3.0);
	frc::CommandGroup::AddSequential(new AutoLeftScoreSwitchLeftClaw, 0.5);
}
