//
//  Vec2.hpp
//  raycaster
//
//  Created by Michael Nolan on 10/27/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#ifndef Vec2_hpp
#define Vec2_hpp

#include <stdio.h>
#include <cmath>
class Vec2 {
	public:
	float x;
	float y;
	Vec2():x(0),y(0){

	}
	Vec2(float _x,float _y) :x(_x),y(_y){

	}
	Vec2 operator+(const Vec2& other){
		return Vec2(x+other.x,y+other.y);
	}
	Vec2 operator-(const Vec2& other){
		return Vec2(x - other.x,y - other.y);
	}
	Vec2 operator/(const float& denom){
		return Vec2(x/denom, y/denom);
	}
	float dot(const Vec2& other){
		return x*other.x + y *other.y;
	}
	Vec2 operator*(const float& flt){
		return Vec2(x*flt,y*flt);
	}
	float length(){
		return sqrtf(x*x+y*y);
	}
	Vec2 normalize(){
		float len = sqrtf(x*x+y*y);
		return *this/len;
	}
	float cross(Vec2& v){
		return x*v.y - v.x*y;
	}


	~Vec2(){

	}
};
#endif /* Vec2_hpp */
