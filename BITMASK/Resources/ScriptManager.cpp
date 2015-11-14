#include "ScriptManager.h"

std::string bit::ScriptManager::getScriptContent(const std::string& path)
{
	// Try and load the file
	PHYSFS_File *f;
	f = PHYSFS_openRead(path.c_str());

	if (!f)
	{
		throw std::runtime_error("ScriptManager::getScriptContent - Failed to load file into memory :: " + path);
	}

	// Get the size of the file
	const size_t size = static_cast<size_t>(PHYSFS_fileLength(f));

	// Read it into a char buffer
	char* buff = new char[size]();

	PHYSFS_read(f, buff, 1, static_cast<PHYSFS_uint32>(size));
	std::string fileContent(buff);

	return fileContent.substr(0, size);
}

void bit::ScriptManager::loadModules(const std::string& path, chaiscript::ChaiScript* engine)
{
	char** list = PHYSFS_enumerateFiles(path.c_str());
	char** fileName;

	std::string filePathFull = "";

	for (fileName = list; *fileName != NULL; fileName++)
	{
		// For each file, grab its content and eval it into the engine
		filePathFull = path + *fileName;
		engine->eval(getScriptContent(filePathFull));
	}

	PHYSFS_freeList(list);
}
