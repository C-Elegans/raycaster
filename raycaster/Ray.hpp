//
//  Ray.hpp
//  raycaster
//
//  Created by Michael Nolan on 10/27/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#ifndef Ray_hpp
#define Ray_hpp

#include <stdio.h>
#include "Vec2.hpp"
class Ray{
	public:
	Vec2 origin;
	Vec2 direction;
	Ray(Vec2 o, Vec2 d):origin(o), direction(d){

	}
	Ray(float x1,float y1,float radians){
		origin = Vec2(x1,y1);
		direction = Vec2(cosf(radians),sinf(radians));
	}
	Ray rotate(float radians){
		float cs = cosf(radians);
		float ss = sinf(radians);
		return Ray(origin,Vec2(direction.x*cs-direction.y*ss,direction.x*ss+direction.y*cs).normalize());
	}
	~Ray(){
		
	}
};
#endif /* Ray_hpp */
