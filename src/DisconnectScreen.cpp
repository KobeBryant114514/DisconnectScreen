#include <LoggerAPI.h>

extern Logger logger;

string DisconnectScreen(string reason){
	try {
		nlohmann::json json;
		std::ifstream jsonfile("plugins/DisconnectScreen/Language.json");
		if (jsonfile) {
			jsonfile >> json;
            jsonfile.close();
            return json[reason].get<string>();
		}
		else {
			return "";
		}
	}
	catch(std::exception& ex) {
		return "";
	}
    catch(...){
		return "";
    }
}

void GenerateLanguage(){
    if (!std::filesystem::exists("./plugins/DisconnectScreen")){
        std::filesystem::create_directories("plugins/DisconnectScreen");
    }
    if(!std::filesystem::exists("./plugins/DisconnectScreen/Language.json")){
        std::ofstream DefaultFile("./plugins/DisconnectScreen/Language.json");
        logger.warn("语言文件不存在，正在自动创建！");
        if (!DefaultFile.is_open()) {
            logger.error("语言文件创建失败！");
            return;
        }
        nlohmann::json json;
        json["disconnectionScreen.editionMismatchEduToVanilla"] = "连接失败！\n你使用的是教育版客户端。\n请使用正常基岩版客户端。";
	    json["disconnectionScreen.editionMismatchVanillaToEdu"] = "连接失败！\n请使用教育版服务端加入服务器。";
	    json["disconnectionScreen.invalidSkin"] = "连接失败！\n无效的皮肤！";
        json["disconnectionScreen.invalidTenant"] = "无法连接。非法的访客！";
	    json["disconnectionScreen.multiplayerDisabled"] = "连接失败！\n此世界已禁用多人游戏。";
	    json["disconnectionScreen.notAllowed"] = "你没有服务器白名单！\n请先添加QQ群申请白名单\n服务器QQ群号： 114514";
    	json["disconnectionScreen.notAuthenticated"] = "你没有通过 Microsoft 身份验证。\n请尝试重启游戏或更换网络环境。";
    	json["disconnectionScreen.outdatedClient"] = "无法连接：不兼容的客户端版本。\n服务器兼容的客户端版本： {Server}\n你正在使用的客户端版本： {Client}";
    	json["disconnectionScreen.outdatedServer"] = "无法连接：不兼容的客户端版本。\n服务器兼容的客户端版本： {Server}\n你正在使用的客户端版本： {Client}";
	    json["disconnectionScreen.serverIdConflict"] = "无法加入服务器！\n您的账户目前正在另一个设备上游玩此服务器。";
        DefaultFile << json.dump(4);
        DefaultFile.close();
    }
}