#include <filesystem>
#include "config.hpp"
#include "../utilities/utilities.hpp"
#include "../cheats/menu/vars.hpp"

namespace fs = std::filesystem;

namespace config
{
	void save()
	{
		CSimpleIniA ini;
		const std::string location = __PATH + XOR("\\settings.ini");

		if (auto err = ini.LoadFile(location.c_str()); !__PATH.empty() && !err)
		{
			ini.SetBoolValue(XOR("HACK"), XOR("BUNNYHOP"), vars::bBunnyHop, "", false);
			ini.SetLongValue(XOR("HACK"), XOR("CHAMS TYPE"), vars::iChams, "", false);
			ini.SetLongValue(XOR("HACK"), XOR("ESP TYPE"), vars::iEsp, "", false);
			ini.SetBoolValue(XOR("HACK"), XOR("GLOW"), vars::bGlow, "", false);
			ini.SetBoolValue(XOR("HACK"), XOR("SOUND ESP"), vars::bSoundEsp, "", false);
			ini.SetLongValue(XOR("HACK"), XOR("FOV AMOUNT"), vars::iFOV, "", false);
			ini.SetBoolValue(XOR("HACK"), XOR("THIRD PERSON"), vars::bThirdp, "", false);
			ini.SetLongValue(XOR("HACK"), XOR("AIMBOT TYPE"), vars::iAimbot, "", false);
			ini.SetLongValue(XOR("HACK"), XOR("AIMBOT FOV"), vars::iFovAimbot, "", false);
			ini.SetLongValue(XOR("HACK"), XOR("AIMBOT SMOOTH"), vars::iSmooth, "", false);
			ini.SetLongValue(XOR("HACK"), XOR("RCS XY VALUE"), vars::iRCS, "", false);
			ini.SetLongValue(XOR("HACK"), XOR("CROSSHAIR TYPE"), vars::iCrosshair, "", false);
			ini.SetBoolValue(XOR("HACK"), XOR("TRIGGERBOT"), vars::bTriggerbot, "", false);
			ini.SetLongValue(XOR("HACK"), XOR("TRIGGERBOT MS"), vars::iTriggerDelay, "", false);
			ini.SetBoolValue(XOR("HACK"), XOR("BACKTRACK"), vars::bBacktrack, "", false);
			ini.SetLongValue(XOR("HACK"), XOR("BACKTRACK TICKS"), vars::iBacktrackTick, "", false);
			ini.SetBoolValue(XOR("HACK"), XOR("MENU OPENED"), vars::bMenuOpen, "", false);
			ini.SetBoolValue(XOR("HACK"), XOR("RADAR 2D"), vars::bRadar, "", false);
			ini.SetBoolValue(XOR("HACK"), XOR("SHOW INFO"), vars::bShowInfo, "", false);
			ini.SetBoolValue(XOR("HACK"), XOR("SHOW ESP FLAGS"), vars::bShowFlags, "", false);
			ini.SetLongValue(XOR("HACK"), XOR("BT CHAMS TYPE"), vars::iBacktrackChams, "", false);
			ini.SetBoolValue(XOR("HACK"), XOR("ESP INFO"), vars::bDrawInfos, "", false);
			ini.SetBoolValue(XOR("HACK"), XOR("ESP SKELETON"), vars::bDrawSkeleton, "", false);
			ini.SetBoolValue(XOR("HACK"), XOR("DL LIGHT"), vars::bDLight, "", false);
			ini.SetBoolValue(XOR("HACK"), XOR("NIGHTMODE"), vars::bRunNight, "", false);
			ini.SetBoolValue(XOR("HACK"), XOR("ESP LASERS"), vars::bEspLasers, "", false);
			ini.SetBoolValue(XOR("HACK"), XOR("SHOW PLOTS"), vars::bShowPlots, "", false);
			ini.SetLongValue(XOR("HACK"), XOR("HAND CHAMS"), vars::iHandChams, "", false);
			ini.SetLongValue(XOR("HACK"), XOR("WEAPON CHAMS"), vars::iWeaponChams, "", false);
			if (auto check = ini.SaveFile(location.c_str()); !check)
				LOG(LOG_INFO, XOR("Saved the config without error"));
			else
			{
				throw std::runtime_error(XOR("Config save error"));
			}
		}
		else
			throw std::runtime_error(XOR("Config could not reach the path or loaded file turned to be an error"));
	}

	void init()
	{
		CSimpleIniA ini;
		const std::string location = __PATH + XOR("\\settings.ini");

		if (auto err = ini.LoadFile(location.c_str()); !__PATH.empty() && !err)
		{
			vars::bBunnyHop = ini.GetBoolValue(XOR("HACK"), XOR("BUNNYHOP"));
			vars::iChams = ini.GetLongValue(XOR("HACK"), XOR("CHAMS TYPE"));
			vars::iEsp = ini.GetLongValue(XOR("HACK"), XOR("ESP TYPE"));
			vars::bGlow = ini.GetBoolValue(XOR("HACK"), XOR("GLOW"));
			vars::bSoundEsp = ini.GetBoolValue(XOR("HACK"), XOR("SOUND ESP"));
			vars::iFOV = ini.GetLongValue(XOR("HACK"), XOR("FOV AMOUNT"));
			vars::bThirdp = ini.GetBoolValue(XOR("HACK"), XOR("THIRD PERSON"));
			vars::iAimbot = ini.GetLongValue(XOR("HACK"), XOR("AIMBOT TYPE"));
			vars::iFovAimbot = ini.GetLongValue(XOR("HACK"), XOR("AIMBOT FOV"));
			vars::iSmooth = ini.GetLongValue(XOR("HACK"), XOR("AIMBOT SMOOTH"));
			vars::iRCS = ini.GetLongValue(XOR("HACK"), XOR("RCS XY VALUE"));
			vars::iCrosshair = ini.GetLongValue(XOR("HACK"), XOR("CROSSHAIR TYPE"));
			vars::bTriggerbot = ini.GetBoolValue(XOR("HACK"), XOR("TRIGGERBOT"));
			vars::iTriggerDelay = ini.GetLongValue(XOR("HACK"), XOR("TRIGGERBOT MS"));
			vars::bBacktrack = ini.GetBoolValue(XOR("HACK"), XOR("BACKTRACK"));
			vars::iBacktrackTick = ini.GetLongValue(XOR("HACK"), XOR("BACKTRACK TICKS"));
			vars::bMenuOpen = ini.GetBoolValue(XOR("HACK"), XOR("MENU OPENED"));
			vars::bRadar = ini.GetBoolValue(XOR("HACK"), XOR("RADAR 2D"));
			vars::bShowInfo = ini.GetBoolValue(XOR("HACK"), XOR("SHOW INFO"));
			vars::bShowFlags = ini.GetBoolValue(XOR("HACK"), XOR("SHOW ESP FLAGS"));
			vars::iBacktrackChams = ini.GetLongValue(XOR("HACK"), XOR("BT CHAMS TYPE"));
			vars::bDrawInfos = ini.GetBoolValue(XOR("HACK"), XOR("ESP INFO"));
			vars::bDrawSkeleton = ini.GetBoolValue(XOR("HACK"), XOR("ESP SKELETON"));
			vars::bDLight = ini.GetBoolValue(XOR("HACK"), XOR("DL LIGHT"));
			vars::bRunNight = ini.GetBoolValue(XOR("HACK"), XOR("NIGHTMODE"));
			vars::bEspLasers = ini.GetBoolValue(XOR("HACK"), XOR("ESP LASERS"));
			vars::bShowPlots = ini.GetBoolValue(XOR("HACK"), XOR("SHOW PLOTS"));
			vars::iHandChams = ini.GetLongValue(XOR("HACK"), XOR("HAND CHAMS"));
			vars::iWeaponChams = ini.GetLongValue(XOR("HACK"), XOR("WEAPON CHAMS"));
			LOG(LOG_INFO, XOR("Config loaded success"));
		}
		else
			throw std::runtime_error(XOR("Config could not reach the path or loaded file turned to be an error"));
	}
}