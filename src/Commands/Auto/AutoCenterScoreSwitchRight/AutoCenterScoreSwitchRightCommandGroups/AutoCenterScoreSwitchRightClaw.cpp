#include "AutoCenterScoreSwitchRightClaw.h"
#include "AutoCenterScoreSwitchRightClawCommands/AutoCenterScoreSwitchRightClawOpen.h"

AutoCenterScoreSwitchRightClaw::AutoCenterScoreSwitchRightClaw() {
	frc::CommandGroup::AddParallel(new AutoCenterScoreSwitchRightClawOpen(), 0.5);
}
