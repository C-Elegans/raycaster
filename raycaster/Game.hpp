//
//  Game.hpp
//  raycaster
//
//  Created by Michael Nolan on 10/27/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp
#include <vector>
#include "Line.hpp"
#include "Ray.hpp"
#include "framebuffer.hpp"
#include <stdio.h>
class Game{
	public:
	std::vector<Wall> level;
	Game();
	void render(Framebuffer& fb, Ray Player);
	void handleEvent(Ray& Player, float dtime);
	~Game(){
		
	}
};

#endif /* Game_hpp */
