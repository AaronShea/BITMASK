#pragma once

namespace chaiscript
{
	class ChaiScript;
}

namespace bit
{
	class ScriptDefs
	{
		public:
			static void registerTypes(chaiscript::ChaiScript* engine);
	};
}