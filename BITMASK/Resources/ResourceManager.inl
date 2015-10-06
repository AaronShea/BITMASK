template <typename Resource>
void ResourceManager<Resource>::load(std::string id, std::string filePath)
{
	std::unique_ptr<Resource> resource(new Resource());
	if (!resource->loadFromFile(filePath))
	{
		throw std::runtime_error("ResourceHolder::load - Failed to load " + filePath);
	}

	auto inserted = resource_map.insert(std::make_pair(id, std::move(resource)));
	assert(inserted.second);
}


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