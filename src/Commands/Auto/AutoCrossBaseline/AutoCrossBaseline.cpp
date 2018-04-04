#include <Commands/Auto/AutoCrossBaseline/AutoCrossBaseline.h>
#include "AutoCrossBaselineCommandGroups/AutoCrossBaselineDrive.h"
#include "AutoCrossBaselineCommandGroups/AutoCrossBaselineRobonautsDelay.h"

AutoCrossBaseline::AutoCrossBaseline() {
	frc::CommandGroup::AddSequential(new AutoCrossBaselineRobonautsDelay(), 10.0);
	frc::CommandGroup::AddSequential(new AutoCrossBaselineDrive(), 10.0);
}
