#include "AutoStraightSwitchClaw.h"
#include "AutoStraightSwitchClawCommands/AutoStraightSwitchClawOpen.h"

AutoStraightSwitchClaw::AutoStraightSwitchClaw() {
	frc::CommandGroup::AddParallel(new AutoStraightSwitchClawOpen(), 0.5);
}