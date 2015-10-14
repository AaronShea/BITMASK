#pragma once
#include <map>
#include <memory>
#include <assert.h>
#include "physfs.h"
#include "SFML/Graphics.hpp"

template<typename Resource>
class ResourceManager
{
	private:
		std::map<std::string, std::unique_ptr<Resource>> resource_map;

	public:	
		template <typename Parameter>
		void load(std::string id, std::string filePath, const Parameter& secondParam);

		void load(std::string id, std::string filePath);
		Resource& get(std::string id);
};

#include "ResourceManager.inl"