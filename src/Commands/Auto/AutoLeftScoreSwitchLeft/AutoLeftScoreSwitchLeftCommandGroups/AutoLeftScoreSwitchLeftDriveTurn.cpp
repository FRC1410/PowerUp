#include "AutoLeftScoreSwitchLeftDriveTurn.h"
#include "AutoLeftScoreSwitchLeftTurnRightCommands/AutoLeftScoreSwitchLeftTurnRight.h"

AutoLeftScoreSwitchLeftDriveTurn::AutoLeftScoreSwitchLeftDriveTurn() {
	frc::CommandGroup::AddParallel(new AutoLeftScoreSwitchLeftTurnRight(), 4.0);
}
