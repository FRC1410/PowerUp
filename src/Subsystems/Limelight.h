#include <Commands/Subsystem.h>
#include <Drive/DifferentialDrive.h>
#include <IterativeRobot.h>
#include <ctre/Phoenix.h>
#include "WPILib.h"
#include <functional>
#include <mutex>
#include <vector>
#include "tables/ITable.h"
#define LimeLight_H_
    class LimeLight : public Subsystem {
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
    	     LimeLight();
    	     static CameraServer * GetInstance();

    	     static void SetIPAddress(llvm::StringRef address);
    	     void StartAutomaticCapture(const cs::VideoSource& camera);

    	    // cs::CvSink CameraServer::GetVideo (const cs::VideoSource & camera);
    	     //virtual ~NetworkTable();
    	     	 	 //Get Limelight table to read


    };
