#include "AutoLeftScoreSwitchLeftElevator.h"
#include "AutoLeftScoreSwitchLeftElevatorCommands/AutoLeftScoreSwitchLeftRaiseElevator.h"
#include "AutoLeftScoreSwitchLeftElevatorCommands/AutoLeftScoreSwitchLeftRotateClaw.h"

AutoLeftScoreSwitchLeftElevator::AutoLeftScoreSwitchLeftElevator() {
	frc::CommandGroup::AddParallel(new AutoLeftScoreSwitchLeftRaiseElevator, 3.0);
	frc::CommandGroup::AddParallel(new AutoLeftScoreSwitchLeftRotateClaw, 2.0);
}
