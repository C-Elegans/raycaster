//
//  main.cpp
//  raycaster
//
//  Created by Michael Nolan on 10/27/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "Game.hpp"
#include "Framebuffer.hpp"
const int SCREEN_WIDTH=640;
const int SCREEN_HEIGHT=480;

int main(int argc, const char * argv[]) {
	Framebuffer fb(SCREEN_WIDTH,SCREEN_HEIGHT);
	Game g;
	Ray player(0, 0, M_PI_2);
	uint32_t ticks = SDL_GetTicks();
	while (1) {
		g.render(fb, player);
		g.handleEvent(player, (float)(SDL_GetTicks()-ticks)/10.0);
		ticks = SDL_GetTicks();
		SDL_Delay(1);
	}


    return 0;
}
