//Library for getting Metrics from userlevel Click
#ifndef CLICKMETRICS
#define CLICKMETRICS

#include <osv/sched.hh>
#include "osv/mount.h"
#include <sys/vfs.h>
#include <time.h>
#include <string>
#include <sys/utsname.h>
#include <sys/sysinfo.h>
#include <osv/power.hh>
#include <osv/sched.hh>
#include <api/unistd.h>
#include "ControlSocket.hh"

#include "autogen/network.json.hh"
#include "../libtools/route_info.hh"
#include "../libtools/network_interface.hh"
#include <vector>

class ClickMetrics {
    private:
    int threadID;
    bool clickToken;
    long prevCPUTime;
    long prevClickTime;
    long prevTXValue;
    long prevCPUTxTime;
    long prevRXValue;
    long prevCPURxTime;
    ControlSocket* clickSocket;
    std::vector<std::string> returnData;
    std::vector<int> rx_ids;
	std::vector<int> tx_ids;
	void findInputAndOutputs();

    public:
    ClickMetrics(int id, bool click);
    void finish();
    int getCPU();
    int getDisk();
    int getMemory();
    long getNetTX(long txValue);
    long getNetRX(long rxValue);
    
    void genericInOutBytes(long *aggregate);
    void clickInOutBytes(long *aggregate);
};

#endif
