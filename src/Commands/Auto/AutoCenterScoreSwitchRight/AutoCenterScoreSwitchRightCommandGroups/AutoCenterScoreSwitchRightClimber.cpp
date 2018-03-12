#include "AutoCenterScoreSwitchRightClimber.h"
#include "AutoCenterScoreSwitchRightClimberCommands/AutoCenterScoreSwitchRightRotateClimber.h"

AutoCenterScoreSwitchRightClimber::AutoCenterScoreSwitchRightClimber() {
	frc::CommandGroup::AddParallel(new AutoCenterScoreSwitchRightRotateClimber(), 0.5);
}
