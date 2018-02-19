#include "AutoCenterScoreSwitchRight.h"
#include "AutoCenterScoreSwitchRightCommandGroups/AutoCenterScoreSwitchRightDriveFar.h"
#include "AutoCenterScoreSwitchRightCommandGroups/AutoCenterScoreSwitchRightDriveShort.h"
#include "AutoCenterScoreSwitchRightCommandGroups/AutoCenterScoreSwitchRightTurnLeft.h"
#include "AutoCenterScoreSwitchRightCommandGroups/AutoCenterScoreSwitchRightTurnRight.h"
#include "AutoCenterScoreSwitchRightCommandGroups/AutoCenterScoreSwitchRightClaw.h"
#include "AutoCenterScoreSwitchRightCommandGroups/AutoCenterScoreSwitchRightClimber.h"
#include "AutoCenterScoreSwitchRightCommandGroups/AutoCenterScoreSwitchRightElevator.h"

AutoCenterScoreSwitchRight::AutoCenterScoreSwitchRight() {
	frc::CommandGroup::AddSequential(new AutoCenterScoreSwitchRightClimber, 0.5);
	frc::CommandGroup::AddSequential(new AutoCenterScoreSwitchRightDriveFar, 5.0);
	frc::CommandGroup::AddSequential(new AutoCenterScoreSwitchRightTurnRight, 4.0);
	frc::CommandGroup::AddSequential(new AutoCenterScoreSwitchRightDriveShort, 3.0);
	frc::CommandGroup::AddSequential(new AutoCenterScoreSwitchRightTurnLeft, 4.0);
	frc::CommandGroup::AddSequential(new AutoCenterScoreSwitchRightDriveFar, 5.0);
	frc::CommandGroup::AddSequential(new AutoCenterScoreSwitchRightElevator, 0.5);
	frc::CommandGroup::AddSequential(new AutoCenterScoreSwitchRightClaw, 0.5);
}
