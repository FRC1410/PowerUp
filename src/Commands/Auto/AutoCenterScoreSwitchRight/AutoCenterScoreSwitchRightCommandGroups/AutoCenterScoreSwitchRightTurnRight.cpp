#include "AutoCenterScoreSwitchRightTurnRight.h"
#include "AutoCenterScoreSwitchRightTurnRightCommands/AutoCenterScoreSwitchRightTurnRightCommand.h"

AutoCenterScoreSwitchRightTurnRight::AutoCenterScoreSwitchRightTurnRight() {
	frc::CommandGroup::AddParallel(new AutoCenterScoreSwitchRightTurnRightCommand(), 4.0);
}
