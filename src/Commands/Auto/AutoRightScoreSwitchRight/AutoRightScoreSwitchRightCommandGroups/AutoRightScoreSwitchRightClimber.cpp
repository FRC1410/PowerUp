#include "AutoRightScoreSwitchRightClimber.h"
#include "AutoRightScoreSwitchRightClimberCommands/AutoRightScoreSwitchRightRotateClimber.h"

AutoRightScoreSwitchRightClimber::AutoRightScoreSwitchRightClimber() {
	frc::CommandGroup::AddParallel(new AutoRightScoreSwitchRightRotateClimber(), 0.5);
}
