#include "hooks.hpp"

#include "../../SDK/IVEngineClient.hpp"
#include "../../SDK/ClientClass.hpp"
#include "../../SDK/interfaces/interfaces.hpp"

#include "../features/prediction/nadepred.hpp"

#include "../globals.hpp"
#include "../game.hpp"
#include "../../config/vars.hpp"

void __stdcall hooks::overrideView::hooked(CViewSetup* view)
{	
	if(!interfaces::engine->isInGame() || !game::localPlayer)
		return original(view);

	if (!game::localPlayer->m_bIsScoped())
		if (auto fov = config.get<float>(vars.fFOV); fov > 0.0f || fov < 0.0f)
			view->m_fov += fov;

	//config.get<bool>(vars.bNoScope)
	//	? view->m_edgeBlur = 0
	//	: view->m_edgeBlur = 4; // 4 is normal

	globals::FOV = view->m_fov;

	nadePred.viewSetup();

	original(view);
}