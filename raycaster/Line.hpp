//
//  Line.hpp
//  raycaster
//
//  Created by Michael Nolan on 10/27/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#ifndef Line_hpp
#define Line_hpp

#include <stdio.h>
#include "Vec2.hpp"
class Line{
public:
	Vec2 p1;
	Vec2 p2;
	Line():p1(),p2(){
		
	}
	Line(float x1,float y1,float x2,float y2):p1(Vec2(x1,y1)),p2(Vec2(x2,y2)){

	}
	Line(Vec2 point1, Vec2 point2):p1(point1), p2(point2){

	}
	~Line(){
		
	}
};
struct Wall{
	public:
	Line line;
	int color;
	Wall(Line l, int c):line(l),color(c){

	}
};
#endif /* Line_hpp */
