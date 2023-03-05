#include <LoggerAPI.h>
#include "Version.h"
#include <HookAPI.h>

extern Logger logger;
extern void GenerateLanguage();

void PluginInit()
{
    GenerateLanguage();
}
