#include "AutoCenterScoreSwitchLeft.h"
#include "AutoCenterScoreSwitchLeftCommandGroups/AutoCenterScoreSwitchLeftDriveFar.h"
#include "AutoCenterScoreSwitchLeftCommandGroups/AutoCenterScoreSwitchLeftDriveShort.h"
#include "AutoCenterScoreSwitchLeftCommandGroups/AutoCenterScoreSwitchLeftTurnLeft.h"
#include "AutoCenterScoreSwitchLeftCommandGroups/AutoCenterScoreSwitchLeftTurnRight.h"
#include "AutoCenterScoreSwitchLeftCommandGroups/AutoCenterScoreSwitchLeftClaw.h"
#include "AutoCenterScoreSwitchLeftCommandGroups/AutoCenterScoreSwitchLeftClimber.h"
#include "AutoCenterScoreSwitchLeftCommandGroups/AutoCenterScoreSwitchLeftElevator.h"

AutoCenterScoreSwitchLeft::AutoCenterScoreSwitchLeft() {
	frc::CommandGroup::AddSequential(new AutoCenterScoreSwitchLeftClimber, 0.5);
	frc::CommandGroup::AddSequential(new AutoCenterScoreSwitchLeftDriveShort, 5.0);
	frc::CommandGroup::AddSequential(new AutoCenterScoreSwitchLeftTurnLeft, 4.0);
	frc::CommandGroup::AddSequential(new AutoCenterScoreSwitchLeftDriveFar, 10.0);
	frc::CommandGroup::AddSequential(new AutoCenterScoreSwitchLeftTurnRight, 4.0);
	frc::CommandGroup::AddSequential(new AutoCenterScoreSwitchLeftDriveShort, 5.0);
	frc::CommandGroup::AddSequential(new AutoCenterScoreSwitchLeftElevator, 0.5);
	frc::CommandGroup::AddSequential(new AutoCenterScoreSwitchLeftClaw, 0.5);
}
