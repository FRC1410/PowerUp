#include "AutoRightScoreSwitchRightElevator.h"
#include "AutoRightScoreSwitchRightElevatorCommands/AutoRightScoreSwitchRightRaiseElevator.h"
#include "AutoRightScoreSwitchRightElevatorCommands/AutoRightScoreSwitchRightRotateClaw.h"

AutoRightScoreSwitchRightElevator::AutoRightScoreSwitchRightElevator() {
	frc::CommandGroup::AddParallel(new AutoRightScoreSwitchRightRaiseElevator, 3.0);
	frc::CommandGroup::AddParallel(new AutoRightScoreSwitchRightRotateClaw, 2.0);
}
