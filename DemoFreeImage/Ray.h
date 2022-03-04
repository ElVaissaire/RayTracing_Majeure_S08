#pragma once
#include "Vector3.h"
#include "CLight.h"

class CSphere;

class Ray
{
public:
	Ray();
	Ray(Vector3 *origin, Vector3 *direction);
	Vector3 *intersection(CSphere* s);
	bool intersectionLight(CLight* l);
	Vector3 *getOrigin();
	Vector3 *getDirection();

private:
	Vector3* m_origin;
	Vector3* m_direction;
};