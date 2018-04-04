#include "AutoCrossBaselineRobonautsDelay.h"
#include "AutoCrossBaselineRobonautsDelayCommands/AutoCrossBaselineRobonautsDelayTen.h"

AutoCrossBaselineRobonautsDelay::AutoCrossBaselineRobonautsDelay() {
	frc::CommandGroup::AddParallel(new AutoCrossBaselineRobonautsDelayTen(), 10.0);
}
