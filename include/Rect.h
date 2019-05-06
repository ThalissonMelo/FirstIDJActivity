#ifndef RECT_H_
#define RECT_H_

#include "Vec2.h"

class Rect {
public:
	float x;
	float y;
	float w;
	float h;
	float rotation;
	Rect();
	Rect(float x, float y, float w, float h);
	~Rect();
	bool Contains(float a, float b);
	Vec2 GetCenter();
	void SetPosition(Vec2 pos);
	// Vec2 RectToVec();
};

#endif