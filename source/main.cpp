// classic API header files
#include <sstream>
#include "c4d_plugin.h"
#include "switch_cams.hpp"

const char* AUTHOR{ "Philipp Bokatius & Henrik S." };
const unsigned MAJOR_VER{ 1 };
const unsigned MINOR_VER{ 0 };

::Bool PluginStart()
{
	if (!SwitchCams::register_class())
	{
		ApplicationOutput("Failed to register SwitchCams command");
		return false;
	}
	std::ostringstream str;
	str << "SwitchCams v" << MAJOR_VER << '.' << MINOR_VER << " by " << AUTHOR;
	ApplicationOutput(str.str().c_str());
	return true;
}

void PluginEnd()
{
	// free resources
}

::Bool PluginMessage(::Int32 id, void* data)
{
	return true;
}
