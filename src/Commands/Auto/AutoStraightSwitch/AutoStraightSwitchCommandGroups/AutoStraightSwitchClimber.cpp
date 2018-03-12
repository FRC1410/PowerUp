#include "AutoStraightSwitchClimber.h"
#include "AutoStraightSwitchClimberCommands/AutoStraightSwitchRotateClimber.h"

AutoStraightSwitchClimber::AutoStraightSwitchClimber() {
	frc::CommandGroup::AddParallel(new AutoStraightSwitchRotateClimber(), 0.5);
}
