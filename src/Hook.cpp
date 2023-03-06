#include <HookAPI.h>
#include <mc/ServerNetworkHandler.hpp>
#include <mc/NetworkIdentifier.hpp>
#include <mc/SharedConstants.hpp>
#include <LoggerAPI.h>

extern string DisconnectScreen(string reason);

TInstanceHook(void, "?disconnectClient@ServerNetworkHandler@@QEAAXAEBVNetworkIdentifier@@W4SubClientId@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_N@Z", ServerNetworkHandler, NetworkIdentifier* a1, int a2, string a3, bool a4) {
    if (a3 == "disconnectionScreen.disconnected") {
		return original(this, a1, a2 ,a3, a4);
	}
	int cver = *((int*)a1 + 12);
	int sver = SharedConstants::NetworkProtocolVersion;	
	string str = DisconnectScreen(a3);
    if (str == "") {
        return original(this, a1, a2 ,a3, a4);
    }
    else {
        str = ReplaceStr(str, "{Client}", std::to_string(cver));
	    str = ReplaceStr(str, "{Server}", std::to_string(sver));
	    return original(this, a1, a2, str, a4);
    }
}
