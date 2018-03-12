#include "AutoRightScoreSwitchRightDriveTurn.h"
#include "AutoRightScoreSwitchRightTurnLeftCommands/AutoRightScoreSwitchRightTurnLeft.h"

AutoRightScoreSwitchRightDriveTurn::AutoRightScoreSwitchRightDriveTurn() {
	frc::CommandGroup::AddParallel(new AutoRightScoreSwitchRightTurnLeft(), 4.0);
}
