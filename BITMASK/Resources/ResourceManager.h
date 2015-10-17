#pragma once
#include <map>
#include <memory>
#include <assert.h>

#include "physfs.h"
#include "SFML/Graphics.hpp"

struct ResourceMemLocation
{
	unsigned char* data;
	size_t dataSize;
};

template<typename Resource>
class ResourceManager
{
	private:
		std::map<std::string, std::unique_ptr<Resource>> resource_map;
		ResourceMemLocation loadIntoMemory(std::string filePath);

	public:	
		template <typename Parameter>
		void load(std::string id, std::string filePath, const Parameter& secondParam);

		void load(std::string id, std::string filePath);
		Resource& get(std::string id);
};

#include "ResourceManager.inl"