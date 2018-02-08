#include <Commands/Subsystem.h>
#include <Drive/DifferentialDrive.h>
#include <IterativeRobot.h>
#include <ctre/Phoenix.h>
#include "WPILib.h"
#include <functional>
#include <mutex>
#include <vector>
#include "tables/ITable.h"
#define Limelight_H_
    class Limelight : public Subsystem {
    private:
    	 struct private_init {};

    	     std::string m_path;
    	     std::mutex m_mutex;
    	  typedef std::pair<ITableListener*, unsigned int> Listener;
    	     std::vector<Listener> m_listeners;

    	     static std::vector<std::string> s_ip_addresses;
    	     static std::string s_persistent_filename;
    	     static bool s_client;
    	     static bool s_enable_ds;
    	     static bool s_running;
   public:

    	     //NetworkTable(llvm::StringRef path, const private_init&);
    	     static void SetIPAddress(llvm::StringRef address);
    	     //virtual ~NetworkTable();
    	     	 	 //Get Limelight table to read data
    	     //static std::shared_ptr < NetworkTable > GetTable (llvm::StringRef key);
    	    // std::shared_ptr<NetworkTable> table = NetworkTable::GetTable("limelight");
    	     	 //float KpAim = 0.045;
    	     	 //float KpDist = 0.0f; //0.09
    	     	 //float AimMinCmd = 0.095f;
    	     	 	 //float targetoffsetAngle_Horizontal = table->GetNumber("tx", 0);
    	     	 	 //float targetoffsetAngle_Vertical = table->GetNumber("ty", 0);
    	     	 	 //float targetArea = table->GetNumber("ta", 0);
    	     	 	 //float targetSkew = table-> GetNumber ("ts" , 0);

    };
