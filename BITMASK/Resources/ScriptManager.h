#pragma once
#include "physfs.h"
#include <string>

namespace chaiscript
{
	class ChaiScript;
}

namespace bit
{
	class ScriptManager
	{
		public:
			static std::string getScriptContent(const std::string& path);
			static void loadModules(const std::string& path, chaiscript::ChaiScript* engine);
	};

}
