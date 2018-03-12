#include "AutoLeftScoreSwitchLeftClimber.h"
#include "AutoLeftScoreSwitchLeftClimberCommands/AutoLeftScoreSwitchLeftRotateClimber.h"

AutoLeftScoreSwitchLeftClimber::AutoLeftScoreSwitchLeftClimber() {
	frc::CommandGroup::AddParallel(new AutoLeftScoreSwitchLeftRotateClimber(), 0.5);
}
