#pragma once
#include <iostream>


class Vector3
{
protected:
	float m_x;
	float m_y;
	float m_z;

public:
	Vector3();
	Vector3(float x, float y, float z);
	
	float scalarProduct(Vector3 b);
	Vector3 vectorielProduct(Vector3 b);
	Vector3 *vectorDirection(Vector3 *pos2);

	float getX();
	float getY();
	float getZ();

private:
	
};