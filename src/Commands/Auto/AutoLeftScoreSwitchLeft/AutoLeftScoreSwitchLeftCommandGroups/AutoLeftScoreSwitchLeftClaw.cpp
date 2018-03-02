#include "AutoLeftScoreSwitchLeftClaw.h"
#include "AutoLeftScoreSwitchLeftClawCommands/AutoLeftScoreSwitchLeftClawOpen.h"

AutoLeftScoreSwitchLeftClaw::AutoLeftScoreSwitchLeftClaw() {
	frc::CommandGroup::AddParallel(new AutoLeftScoreSwitchLeftClawOpen(), 0.5);
}
