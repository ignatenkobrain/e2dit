/*
 * E2DIT - is a 2D Map Editor to create a levels for 2d games
 * Copyright (C) 2015 Kabylin Andrey <andrey@kabylin.ru>

 * This file is part of E2DIT-UTILITY.

 * E2DIT-UTILITY is free library: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * E2DIT-UTILITY is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public License
 * along with E2DIT-UTILITY.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Author: Kabylin Andrey <andrey@kabylin.ru>
 */

/**
 *  @file application.h
 *  @brief handle application, main parameters and events
 */

#ifndef E2DIT_SYSTEM_APPLICATION_H
#define E2DIT_SYSTEM_APPLICATION_H

#include <SFML/Window.hpp>
#include "utility/logger.h"
#include "utility/input.h"
#include "renderer/camera.h"
#include <string>

class Application {
public:

	/* Window */

	int screenWidth  = 0;
	int screenHeight = 0;
	int windowWidth  = 0;
	int windowHeight = 0;
	std::string exeDir;

	sf::WindowHandle windowHandle;

	/* OpenGL */

	bool VAOEXT   = false;
	int  OGLMajor = 3;
	int  OGLMinor = 3;

	Camera *screenCamera;

	/* Cursor */

	int mouseX, mouseY;
	int clickX, clickY;
	int mouseButton = mouseNone;

	/* Log */

	Logger log;

	/* */

	static Application *getInstance();

};

#endif