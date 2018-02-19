#include "AutoCenterScoreSwitchLeftTurnLeft.h"
#include "AutoCenterScoreSwitchLeftTurnLeftCommands/AutoCenterScoreSwitchLeftTurnLeftCommand.h"

AutoCenterScoreSwitchLeftTurnLeft::AutoCenterScoreSwitchLeftTurnLeft() {
	frc::CommandGroup::AddParallel(new AutoCenterScoreSwitchLeftTurnLeftCommand(), 4.0);
}
