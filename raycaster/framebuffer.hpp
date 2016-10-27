//
//  framebuffer.hpp
//  raycaster
//
//  Created by Michael Nolan on 10/27/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#ifndef framebuffer_hpp
#define framebuffer_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
class Framebuffer {
SDL_Window* window;
SDL_Surface* screenSurface;

public:
	int width;
	int height;
	Framebuffer(int width, int height);
	void* getPointer();
	void update();
	void clear();
	
	~Framebuffer();
};

#endif /* framebuffer_hpp */
