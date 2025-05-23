#pragma once

#include "../ECS/Registry.h"
#include "../ECS/COMPONENTS/ScriptComponent.h"
#include "../ECS/COMPONENTS/TransformComponent.h"
#include "../ECS/COMPONENTS/SpriteComponent.h"
#include "../ECS/Components/AnimationComponent.h"
#include "../ECS/Components/BoxColliderComponent.h"
#include "../ECS/Components/CircleColliderComponent.h"
#include "../ECS/Components/PhysicsComponent.h"
#include "../ECS/Components/SoundEmitter.h"
#include "../ECS/Components/SoundListener.h"
#include "../ECS/COMPONENTS/TextComponent.h"
#include "../ECS/COMPONENTS/RigidBodyComponent.h"
#include "../ECS/COMPONENTS/OpenALSoundComponent.h"
#include "../ECS/Entity.h"

#include "../LOGGER/log.h"
#include "../LOGGER/LuaLogBinding.h"

#include "../SCRIPTING/GLMLuaBindings.h"
#include "../SCRIPTING/InputManager.h"
#include "../SCRIPTING/RendererBindings.h"
#include "../SCRIPTING/UserDataBinding.h"
#include "../SCRIPTING/ContactListenerBind.h"
#include "../SCRIPTING/SensorListenerBind.h"

#include "../RESOURCES/AssetManager.h"

#include "../UTILITIES/Timer.h"
#include "../UTILITIES/RandomGenerator.h"

#include "../RENDERER/CORE/CoreEngineData.h"
#include "../RENDERER/CORE/FollowCamera.h"

#include "../STATES/State.h"
#include "../STATES/StateStack.h"
#include "../STATES/StateMachine.h"
#include "../STATES/StateSubMachine.h"

#include <sol/sol.hpp>

class ScriptingSystem
{
public:
	ScriptingSystem(Registry& registry);
	~ScriptingSystem() = default;
	bool LoadMainScript(sol::state& lua);
	void Update();
	void Render();

	static void RegisterLuaBindings(sol::state& lua, Registry& registry);

	static void RegisterLuaFunctions(sol::state& lua, Registry& registry);


private:
	Registry& m_Registry;
	bool m_bMainLoaded;
};
