#include "inputSystem.hpp"

#include "../cheats/globals.hpp"
#include "utilities.hpp"
#include "../SDK/IVEngineClient.hpp"
#include "../SDK/interfaces/interfaces.hpp"

void KeysHandler::run(UINT message, WPARAM wparam)
{
	if (globals::isInHotkey)
		return;

	if (utilities::isChatOpen() || interfaces::engine->isConsoleVisible())
		return;

	// init starting keys, undefined
	int key = 0;
	auto state = KeyState::OFF;

	switch (message)
	{
	case WM_KEYDOWN:
	case WM_SYSKEYDOWN:
	{
		if (wparam < KEYS_SIZE)
		{
			key = wparam;
			state = KeyState::DOWN;
		}
	}
	break;
	case WM_KEYUP:
	case WM_SYSKEYUP:
	{
		if (wparam < KEYS_SIZE)
		{
			key = wparam;
			state = KeyState::UP;
		}
	}
	break;
	case WM_LBUTTONDOWN:
	case WM_LBUTTONUP:
	case WM_LBUTTONDBLCLK:
	{
		key = VK_LBUTTON;
		state = message == WM_LBUTTONUP ? KeyState::UP : KeyState::DOWN;
	}
	break;
	case WM_RBUTTONDOWN:
	case WM_RBUTTONUP:
	case WM_RBUTTONDBLCLK:
	{
		key = VK_RBUTTON;
		state = message == WM_RBUTTONUP ? KeyState::UP : KeyState::DOWN;
	}
	break;
	case WM_MBUTTONDOWN:
	case WM_MBUTTONUP:
	case WM_MBUTTONDBLCLK:
	{
		key = VK_MBUTTON;
		state = message == WM_MBUTTONUP ? KeyState::UP : KeyState::DOWN;
	}
	break;
	case WM_XBUTTONDOWN:
	case WM_XBUTTONUP:
	case WM_XBUTTONDBLCLK:
	{
		key = (GET_XBUTTON_WPARAM(wparam) == XBUTTON1 ? VK_XBUTTON1 : VK_XBUTTON2);
		state = message == WM_XBUTTONUP ? KeyState::UP : KeyState::DOWN;
	}
	break;
	default:
		break;
	}

	// save the key
	if (state == KeyState::UP && m_keys.at(key) == KeyState::DOWN)
		m_keys.at(key) = KeyState::PRESS;
	else
		m_keys.at(key) = state;
}

bool KeysHandler::isKeyDown(UINT vKey) const
{
	return m_keys.at(vKey) == KeyState::DOWN;
}

bool KeysHandler::isKeyPressed(UINT vKey)
{
	if (m_keys.at(vKey) == KeyState::PRESS)
	{
		m_keys.at(vKey) = KeyState::UP;
		return true;
	}

	return false;
}