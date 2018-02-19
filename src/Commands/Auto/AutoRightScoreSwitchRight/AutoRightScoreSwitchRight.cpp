#include "AutoRightScoreSwitchRight.h"
#include "AutoRightScoreSwitchRightCommandGroups/AutoRightScoreSwitchRightDriveFar.h"
#include "AutoRightScoreSwitchRightCommandGroups/AutoRightScoreSwitchRightDriveShort.h"
#include "AutoRightScoreSwitchRightCommandGroups/AutoRightScoreSwitchRightDriveTurn.h"
#include "AutoRightScoreSwitchRightCommandGroups/AutoRightScoreSwitchRightClaw.h"
#include "AutoRightScoreSwitchRightCommandGroups/AutoRightScoreSwitchRightClimber.h"
#include "AutoRightScoreSwitchRightCommandGroups/AutoRightScoreSwitchRightElevator.h"

AutoRightScoreSwitchRight::AutoRightScoreSwitchRight() {
	frc::CommandGroup::AddSequential(new AutoRightScoreSwitchRightClimber, 0.5);
	frc::CommandGroup::AddSequential(new AutoRightScoreSwitchRightDriveFar, 12.0);
	frc::CommandGroup::AddSequential(new AutoRightScoreSwitchRightDriveTurn, 4.0);
	frc::CommandGroup::AddSequential(new AutoRightScoreSwitchRightDriveShort, 3.0);
	frc::CommandGroup::AddSequential(new AutoRightScoreSwitchRightElevator, 0.5);
	frc::CommandGroup::AddSequential(new AutoRightScoreSwitchRightClaw, 0.5);
}
