#pragma once
#include "Vector3.h"

class CSphere;

class Ray
{
public:
	Ray();
	Ray(Vector3 *origin, Vector3 *direction);
	bool intersection(CSphere* s);
	Vector3 *getOrigin();
	Vector3 *getDirection();

private:
	Vector3* m_origin;
	Vector3* m_direction;
};