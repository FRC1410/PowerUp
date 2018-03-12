#include "AutoRightScoreSwitchRightClaw.h"
#include "AutoRightScoreSwitchRightClawCommands/AutoRightScoreSwitchRightClawOpen.h"

AutoRightScoreSwitchRightClaw::AutoRightScoreSwitchRightClaw() {
	frc::CommandGroup::AddParallel(new AutoRightScoreSwitchRightClawOpen(), 0.5);
}
