#pragma once
#include "physfs.h"
#include "chaiscript/chaiscript.hpp"
#include <string>

namespace bit
{
	class ScriptManager
	{
		public:
			static std::string getScriptContent(const std::string& path);
			static void loadModules(const std::string& path, chaiscript::ChaiScript* engine);
	};

}
