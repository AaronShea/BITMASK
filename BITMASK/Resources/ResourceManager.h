#pragma once
#include <map>
#include <memory>
#include <assert.h>

#include "physfs.h"
#include "SFML/Graphics.hpp"

namespace bit
{
	struct ResourceMemLocation
	{
		unsigned char* data;
		size_t dataSize;
	};

	class PhysFSManager
	{
		public:
			static int mountArchive(const std::string& filePath, const std::string& mountPath)
			{
				return PHYSFS_mount(filePath.c_str(), mountPath.c_str(), true);
			};

			static void initPhysFS()
			{
				PHYSFS_init(".");
			};

			static void deinit()
			{
				PHYSFS_deinit();
			};
	};

	template<typename Resource>
	class ResourceManager
	{
	private:
		std::map<std::string, std::unique_ptr<Resource>> resource_map;
		ResourceMemLocation loadIntoMemory(const std::string& filePath);

	public:
		template <typename Parameter>
		void load(const std::string& id, const std::string& filePath, const Parameter& secondParam);

		void load(const std::string& id, const std::string& filePath);
		Resource& get(const std::string& id);
	};

	#include "ResourceManager.inl"
}

