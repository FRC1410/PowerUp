#include "AutoCenterScoreSwitchLeftClaw.h"
#include "AutoCenterScoreSwitchLeftClawCommands/AutoCenterScoreSwitchLeftClawOpen.h"

AutoCenterScoreSwitchLeftClaw::AutoCenterScoreSwitchLeftClaw() {
	frc::CommandGroup::AddParallel(new AutoCenterScoreSwitchLeftClawOpen(), 0.5);
}
