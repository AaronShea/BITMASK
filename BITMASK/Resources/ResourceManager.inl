template <typename Resource>
void ResourceManager<Resource>::load(std::string id, std::string filePath)
{
	std::unique_ptr<Resource> resource(new Resource());

	// Try and load this from the PhysFS system
	auto locator = loadIntoMemory(filePath);

	if (!resource->loadFromMemory(locator.data, locator.dataSize))
	{
		throw std::runtime_error("ResourceHolder::load - Failed to load " + filePath);
	}

	auto inserted = resource_map.insert(std::make_pair(id, std::move(resource)));
	assert(inserted.second);
};

template <typename Resource>
ResourceMemLocation ResourceManager<Resource>::loadIntoMemory(std::string filePath)
{	
	// Now let's try and load that data
	PHYSFS_File *f;
	f = PHYSFS_openRead(filePath.c_str());

	if (!f)
	{
		throw std::runtime_error("ResourceHolder::loadIntoMemory - Failed to load file into memory :: " + filePath);
	}

	const size_t size = static_cast<size_t>(PHYSFS_fileLength(f));
	ResourceMemLocation memLoc = { new unsigned char[size], static_cast<size_t>(PHYSFS_fileLength(f)) };

	// Load that file into the buffer
	PHYSFS_sint64 length_read = PHYSFS_read(f, memLoc.data, 1, static_cast<PHYSFS_uint32>(PHYSFS_fileLength(f)));

	return memLoc;
};


template <typename Resource>
template <typename Parameter>
void ResourceManager<Resource>::load(std::string id, std::string filePath, const Parameter& secondParam)
{
	std::unique_ptr<Resource> resource(new Resource());
	if (!resource->loadFromFile(filePath, secondParam))
	{
		throw std::runtime_error("ResourceHolder::load - Failed to load " + filePath);
	}

	auto inserted = resource_map.insert(std::make_pair(id, std::move(resource)));
	assert(inserted.second);
}

template <typename Resource>
Resource& ResourceManager<Resource>::get(std::string id)
{
	auto found = resource_map.find(id);
	assert(found != resource_map.end());
	return *found->second;
}