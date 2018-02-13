#include "AutoStraightSwitch.h"
#include "AutoStraightSwitchCommandGroups/AutoStraightSwitchDrive.h"
#include "AutoStraightSwitchCommandGroups/AutoStraightSwitchClaw.h"

AutoStraightSwitch::AutoStraightSwitch() {
	frc::CommandGroup::AddSequential(new AutoStraightSwitchDrive(), 5.0);
	frc::CommandGroup::AddSequential(new AutoStraightSwitchClaw(), 2.0);
}
