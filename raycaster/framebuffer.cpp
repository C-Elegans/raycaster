//
//  framebuffer.cpp
//  raycaster
//
//  Created by Michael Nolan on 10/27/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#include "framebuffer.hpp"
Framebuffer::Framebuffer(int width, int height) :width(width),height(height){

	if(SDL_Init(SDL_INIT_VIDEO)<0){
		printf("SDL Error: %s\n", SDL_GetError());
		exit(1);
	}

	//Create window
	this->window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN );
	if( this->window == NULL )
		{
		printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		exit(1);
		}
	this->screenSurface = SDL_GetWindowSurface(window);
	this->clear();
}
void Framebuffer::clear(){
	memset(this->getPointer(), 0, width*height*4);
}
Framebuffer::~Framebuffer(){
	SDL_DestroyWindow(this->window);
	this->screenSurface = NULL;
}
void * Framebuffer::getPointer(){
	return this->screenSurface->pixels;
}
void Framebuffer::update(){
	SDL_UpdateWindowSurface(this->window);
}
