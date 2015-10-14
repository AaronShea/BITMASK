cmake_minimum_required (VERSION 2.6)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
project (BITMASK C CXX)

# Set base include directory
include_directories(
	"BITMASK/"
)

# Engine
set(BITMASK_MAIN_SRC
	"BITMASK/Game.h"
	"BITMASK/Game.cpp"
	"BITMASK/Main.cpp"
)
source_group("Engine" FILES ${BITMASK_MAIN_SRC})

# Components
set(BITMASK_CMP_SRC
	"BITMASK/Components/Component.h"
	"BITMASK/Components/ComponentIndex.h"
	"BITMASK/Components/TransformComponent.h"
	"BITMASK/Components/TransformComponent.cpp"
)
source_group("Components" FILES ${BITMASK_CMP_SRC})

# Systems
set(BITMASK_SYS_SRC
	"BITMASK/Systems/System.h"
	"BITMASK/Systems/InputSystem.h"
	"BITMASK/Systems/InputSystem.cpp"
)
source_group("Systems" FILES ${BITMASK_SYS_SRC})

# GameObjects
set(BITMASK_OBJ_SRC
	"BITMASK/GameObjects/GameObject.h"
)
source_group("GameObjects" FILES ${BITMASK_OBJ_SRC})

# Resources
set(BITMASK_RES_SRC
	"BITMASK/Resources/ResourceManager.h"
	"BITMASK/Resources/ResourceManager.inl"
)
source_group("Resources" FILES ${BITMASK_RES_SRC})

# Managers
set(BITMASK_MGR_SRC
	"BITMASK/Managers/SystemManager.h"
	"BITMASK/Managers/SystemManager.cpp"
)
source_group("Managers" FILES ${BITMASK_MGR_SRC})

# Add to the project generation
add_executable(BITMASK 
	"${BITMASK_MAIN_SRC}"
	"${BITMASK_CMP_SRC}"
	"${BITMASK_OBJ_SRC}"
	"${BITMASK_SYS_SRC}"
	"${BITMASK_RES_SRC}"
	"${BITMASK_MGR_SRC}"
)

# If on Windows we need "winmm.lib"
if(WIN32)
	target_link_libraries(BITMASK winmm.lib)
	set(SFML_STATIC_LIBRARIES true)
endif()

# If UNIX, we need to use c++11 and libc++
if(UNIX)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -stdlib=libc++")
	target_link_libraries(BITMASK "-lc++abi -v")
endif()

# We require OpenGL
find_package(OpenGL REQUIRED)
target_link_libraries(BITMASK ${OPENGL_LIBRARIES})

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
find_package(PhysicsFS REQUIRED)
if(SFML_FOUND)
	include_directories(${SFML_INCLUDE_DIR})
	target_link_libraries(BITMASK ${SFML_LIBRARIES})
	target_link_libraries(BITMASK ${SFML_DEPENDENCIES})
endif()

# if(PHYSFS_FOUND)
	target_link_libraries(BITMASK ${PHYSFS_LIBRARY})
	include_directories(${PHYSFS_INCLUDE_DIR})
# endif()