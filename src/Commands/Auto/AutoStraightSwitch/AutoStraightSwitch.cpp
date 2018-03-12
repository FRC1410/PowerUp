#include "AutoStraightSwitch.h"
#include "AutoStraightSwitchCommandGroups/AutoStraightSwitchDrive.h"
#include "AutoStraightSwitchCommandGroups/AutoStraightSwitchClaw.h"
#include "AutoStraightSwitchCommandGroups/AutoStraightSwitchClimber.h"
#include "AutoStraightSwitchCommandGroups/AutoStraightSwitchElevator.h"

AutoStraightSwitch::AutoStraightSwitch() {
	frc::CommandGroup::AddSequential(new AutoStraightSwitchClimber, 0.5);
	frc::CommandGroup::AddSequential(new AutoStraightSwitchDrive, 10.0);
	frc::CommandGroup::AddSequential(new AutoStraightSwitchElevator, 2.0);
	frc::CommandGroup::AddSequential(new AutoStraightSwitchClaw, 0.5);
}
