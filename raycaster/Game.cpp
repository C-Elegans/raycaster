//
//  Game.cpp
//  raycaster
//
//  Created by Michael Nolan on 10/27/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#include "Game.hpp"
#include <cmath>
#include <cassert>
const float FOV = 75 * M_PI/180.0;
Game::Game(){
	level.push_back(Wall(Line(-2,5,1,3),0xFF0000FF));
	level.push_back(Wall(Line(-20,10,20,10),0xFF00FF00));
}

float intersect(Ray r, Line l){
	Vec2 v1,v2,v3;
	v1 = r.origin - l.p1;
	v2 = l.p2 -l.p1;
	v3 = Vec2(-r.direction.y, r.direction.x);
	float t1 = v2.cross(v1) / v2.dot(v3);
	float t2 = v1.dot(v3) / v2.dot(v3);
	return t1>=0 && 0<=t2&& t2<=1?t1:-1;
}
void renderColumn(Framebuffer& fb,int x,int height, int color){
	int* pixels = (int*)fb.getPointer();
	height = SDL_min(fb.height, height);
	for(int i=fb.height/2-height/2;i<fb.height/2+height/2;i++){
		pixels[x+i*fb.width] = color;
	}
}
void Game::handleEvent(Ray &Player, float dtime){
	SDL_Event event;
	Vec2 velocity;
	while(SDL_PollEvent(&event)){
		if(event.type == SDL_KEYDOWN){
			switch (event.key.keysym.sym) {
				case SDLK_w:
					velocity.y = 1;

					break;
				case SDLK_s:
					velocity.y = -1;
					break;
				case SDLK_a:
					velocity.x = -1;
					break;
				default:
					break;
			}
		}else if(event.type == SDL_KEYUP){
			switch (event.key.keysym.sym) {
				case SDLK_w:
					if(velocity.y == 1){
						velocity.y = 0;
					}

					break;
				case SDLK_s:
					if(velocity.y == -1){
						velocity.y = 0;
					}

					break;
				case SDLK_a:
					if(velocity.x == -1){
						velocity.x = 0;
					}
					break;
				default:
					break;
			}
		}
		else if(event.type == SDL_QUIT) SDL_Quit();
	}
	Player.origin = Player.origin + velocity*dtime;
}

void Game::render(Framebuffer& fb, Ray Player){
	fb.clear();
	Ray test(Player);
	test = test.rotate(-FOV/2);
	float t1;

	for(int i=0;i<fb.width;i++){
		float distance = __FLT_MAX__;
		int color = 0;
		for(auto it=level.begin();it!=level.end();++it){
			if((t1 =intersect(test, it->line)) > 0){
				Vec2 distToWall = test.direction*t1;
				float d = Player.direction.dot(distToWall);
				if(d<distance){
					distance = d;
					color = it->color;
				}

			}
		}
		renderColumn(fb, i, fb.height/distance,color);
		test = test.rotate(FOV/fb.width);
	}
	fb.update();
	
}
