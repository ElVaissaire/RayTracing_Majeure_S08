#include "Vector3.h"

Vector3::Vector3()
{
	m_x = 0.0f;
	m_y = 0.0f;
	m_z = 0.0f;
}

Vector3::Vector3(float x, float y, float z)
{
	m_x = x;
	m_y = y;
	m_z = z;
}

float Vector3::scalarProduct(Vector3 b)
{
	float res = 0;

	res += m_x * b.m_x;
	res += m_y * b.m_y;
	res += m_z * b.m_z;

	return res;
}

Vector3 Vector3::vectorielProduct(Vector3 b)
{
	Vector3 res;

	res.m_x = m_y * b.m_z - m_z * b.m_y;
	res.m_y = -(m_x * b.m_z - m_z * b.m_x);
	res.m_z = m_x * b.m_y - m_y * b.m_x;

	return res;
}

Vector3 *Vector3::vectorDirection(Vector3 *pos2)
{
	float x = m_x - pos2->m_x;
	float y = m_y - pos2->m_y;
	float z = m_z - pos2->m_z;

	Vector3* direction = new Vector3();;
	
	direction->m_x = x;
	direction->m_y = y;
	direction->m_z = z;

	return direction;
}

float Vector3::getX()
{
	return m_x;
}

float Vector3::getY()
{
	return m_y;
}

float Vector3::getZ()
{
	return m_z;
}