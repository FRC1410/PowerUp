#include "AutoCenterScoreSwitchRightTurnLeft.h"
#include "AutoCenterScoreSwitchRightTurnLeftCommands/AutoCenterScoreSwitchRightTurnLeftCommand.h"

AutoCenterScoreSwitchRightTurnLeft::AutoCenterScoreSwitchRightTurnLeft() {
	frc::CommandGroup::AddParallel(new AutoCenterScoreSwitchRightTurnLeftCommand(), 4.0);
}
