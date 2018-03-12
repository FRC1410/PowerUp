#include "AutoStraightSwitchElevator.h"
#include "AutoStraightSwitchElevatorCommands/AutoStraightSwitchRaiseElevator.h"
#include "AutoStraightSwitchElevatorCommands/AutoStraightSwitchRotateClaw.h"

AutoStraightSwitchElevator::AutoStraightSwitchElevator() {
	frc::CommandGroup::AddParallel(new AutoStraightSwitchRaiseElevator, 3.0);
	frc::CommandGroup::AddParallel(new AutoStraightSwitchRotateClaw, 2.0);
}
