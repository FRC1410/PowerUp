#include "AutoCenterScoreSwitchRightElevator.h"
#include "AutoCenterScoreSwitchRightElevatorCommands/AutoCenterScoreSwitchRightRaiseElevator.h"
#include "AutoCenterScoreSwitchRightElevatorCommands/AutoCenterScoreSwitchRightRotateClaw.h"

AutoCenterScoreSwitchRightElevator::AutoCenterScoreSwitchRightElevator() {
	frc::CommandGroup::AddParallel(new AutoCenterScoreSwitchRightRaiseElevator);
	//frc::CommandGroup::AddParallel(new AutoCenterScoreSwitchRightRotateClaw, 2.0);
}
