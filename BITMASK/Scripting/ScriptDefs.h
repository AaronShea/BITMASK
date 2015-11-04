#pragma once

struct b2Vec2;

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