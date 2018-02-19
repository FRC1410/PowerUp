#include "AutoCenterScoreSwitchLeftClimber.h"
#include "AutoCenterScoreSwitchLeftClimberCommands/AutoCenterScoreSwitchLeftRotateClimber.h"

AutoCenterScoreSwitchLeftClimber::AutoCenterScoreSwitchLeftClimber() {
	frc::CommandGroup::AddParallel(new AutoCenterScoreSwitchLeftRotateClimber(), 0.5);
}
