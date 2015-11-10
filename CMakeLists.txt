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
	"BITMASK/Components/DrawableComponent.h"
	"BITMASK/Components/ShapeComponent.h"
	"BITMASK/Components/ShapeComponent.cpp"
	"BITMASK/Components/PhysicsBodyComponent.h"
	"BITMASK/Components/PhysicsBodyComponent.cpp"
	"BITMASK/Components/ScriptedComponent.h"
	"BITMASK/Components/ScriptedComponent.cpp"
)
source_group("Components" FILES ${BITMASK_CMP_SRC})

# Systems
set(BITMASK_SYS_SRC
	"BITMASK/Systems/System.h"
	"BITMASK/Systems/InputSystem.h"
	"BITMASK/Systems/InputSystem.cpp"
	"BITMASK/Systems/RenderSystem.h"
	"BITMASK/Systems/RenderSystem.cpp"
	"BITMASK/Systems/PhysicsSystem.h"
	"BITMASK/Systems/PhysicsSystem.cpp"
	"BITMASK/Systems/DebugDrawSystem.h"
	"BITMASK/Systems/DebugDrawSystem.cpp"
	"BITMASK/Systems/BallMovementSystem.h"
	"BITMASK/Systems/BallMovementSystem.cpp"
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
	"BITMASK/Managers/GameObjectManager.h"
	"BITMASK/Managers/GameObjectManager.cpp"
)
source_group("Managers" FILES ${BITMASK_MGR_SRC})

# Debugging
set(BITMASK_DBG_SRC
	"BITMASK/DrawDebug/BoxDebugrender.h"
	"BITMASK/DrawDebug/BoxDebugrender.cpp"
)
source_group("Debug" FILES ${BITMASK_DBG_SRC})

# Scripting
set(BITMASK_SCRIPT_SRC
	"BITMASK/Scripting/ScriptDefs.h"
	"BITMASK/Scripting/ScriptDefs.cpp"
)
source_group("Scripting" FILES ${BITMASK_SCRIPT_SRC})

# Add to the project generation
add_executable(BITMASK 
	"${BITMASK_MAIN_SRC}"
	"${BITMASK_CMP_SRC}"
	"${BITMASK_OBJ_SRC}"
	"${BITMASK_SYS_SRC}"
	"${BITMASK_RES_SRC}"
	"${BITMASK_MGR_SRC}"
	"${BITMASK_DBG_SRC}"
	"${BITMASK_SCRIPT_SRC}"
)

# Used to pack assets on Windows development platforms
if(WIN32)
	add_custom_command(TARGET BITMASK
		POST_BUILD
		COMMAND del DATA.BITMASK && X:/PACKERCLI.exe a -r DATA.BITMASK res/* -tzip
	)
endif()

# If on Windows we need "winmm.lib"
if(WIN32)
	target_link_libraries(BITMASK winmm.lib)
	set(SFML_STATIC_LIBRARIES true)
endif()

# If UNIX, we need to use c++11 and libc++
if(UNIX)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -stdlib=libc++ -Wall")
	target_link_libraries(BITMASK "-lc++abi -lpthread -ldl -v")
endif()

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

# Grab chaiscript as well
if (NOT CHSCRIPT_INCLUDE)
	message(FATAL_ERROR "Please set the CHSCRIPT_INCLUDE to the chaiscript include directory")
endif()
include_directories(${CHSCRIPT_INCLUDE})

# We require OpenGL
find_package(OpenGL REQUIRED)
target_link_libraries(BITMASK ${OPENGL_LIBRARIES})

# Box2D
find_package(BOX2D REQUIRED)
include_directories(${BOX2D_INCLUDE_DIRS})
target_link_libraries(BITMASK ${BOX2D_LIBRARY})

# Detect and add SFML
find_package(SFML 2 REQUIRED system window graphics network audio)
find_package(PhysicsFS REQUIRED)
if(SFML_FOUND)
	include_directories(${SFML_INCLUDE_DIR})
	target_link_libraries(BITMASK ${SFML_LIBRARIES})
	target_link_libraries(BITMASK ${SFML_DEPENDENCIES})
endif()

if(PHYSFS_FOUND)
	target_link_libraries(BITMASK ${PHYSFS_LIBRARY})
	include_directories(${PHYSFS_INCLUDE_DIR})
endif()
