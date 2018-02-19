#include "AutoCenterScoreSwitchLeftTurnRight.h"
#include "AutoCenterScoreSwitchLeftTurnRightCommands/AutoCenterScoreSwitchLeftTurnRightCommand.h"

AutoCenterScoreSwitchLeftTurnRight::AutoCenterScoreSwitchLeftTurnRight() {
	frc::CommandGroup::AddParallel(new AutoCenterScoreSwitchLeftTurnRightCommand(), 4.0);
}
