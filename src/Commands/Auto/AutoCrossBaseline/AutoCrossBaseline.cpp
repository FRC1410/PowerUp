#include <Commands/Auto/AutoCrossBaseline/AutoCrossBaseline.h>
#include "AutoCrossBaselineCommandGroups/AutoCrossBaselineDrive.h"

AutoCrossBaseline::AutoCrossBaseline() {
	frc::CommandGroup::AddSequential(new AutoCrossBaselineDrive(), 10.0);
}
