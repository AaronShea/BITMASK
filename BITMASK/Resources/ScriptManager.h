#pragma once
#include "physfs.h"
#include <string>

namespace bit
{
	class ScriptManager
	{
		public:
			static std::string getScriptContent(std::string path);
	};

}
