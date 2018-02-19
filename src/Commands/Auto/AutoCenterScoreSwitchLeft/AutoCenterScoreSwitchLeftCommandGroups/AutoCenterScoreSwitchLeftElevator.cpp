#include "AutoCenterScoreSwitchLeftElevator.h"
#include "AutoCenterScoreSwitchLeftElevatorCommands/AutoCenterScoreSwitchLeftRaiseElevator.h"
#include "AutoCenterScoreSwitchLeftElevatorCommands/AutoCenterScoreSwitchLeftRotateClaw.h"

AutoCenterScoreSwitchLeftElevator::AutoCenterScoreSwitchLeftElevator() {
	frc::CommandGroup::AddParallel(new AutoCenterScoreSwitchLeftRaiseElevator);
	//frc::CommandGroup::AddParallel(new AutoCenterScoreSwitchLeftRotateClaw, 2.0);
}
