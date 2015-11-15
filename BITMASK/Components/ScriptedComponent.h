#pragma once
#include "Component.h"
#include "chaiscript\chaiscript.hpp"
#include <functional>
#include <memory>

namespace bit
{
	class ScriptedComponent : public Component
	{
		private:
			chaiscript::ChaiScript* scriptEngine;
			chaiscript::Boxed_Value scriptInstance;

			// Is this ready to be run?
			bool loaded = false;

			// Path to the source file/resource
			std::string moduleConstructor;

		public:
			explicit ScriptedComponent(const std::string& moduleConstructor);
			~ScriptedComponent() override;

			void added() override;
			void removed() override;

			// Init the script component
			void init(chaiscript::ChaiScript* scriptEngine);

			// Load a function from the module
			void callFunction(std::string functionName) const;
	};
}