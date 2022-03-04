#include "Ray.h"
#include "CSphere.h"

Ray::Ray()
{
	m_origin = new Vector3();
	m_direction = new Vector3();
}

Ray::Ray(Vector3* origin, Vector3* direction)
{
	m_origin = origin;
	m_direction = direction;
}

Vector3 *Ray::intersection(CSphere* s)
{
	float X0 = m_origin->getX() - s->getCoord().getX();
	float Y0 = m_origin->getY() - s->getCoord().getY();
	float Z0 = m_origin->getZ() - s->getCoord().getZ();

	float dx = m_direction->getX();
	float dy = m_direction->getY();
	float dz = m_direction->getZ();

	float t0 = (X0 * X0 + Y0 * Y0 + Z0 * Z0) - s->getRayon();
	float t1 = 2 * (X0 * dx + Y0 * dy + Z0 * dz);
	float t2 = dx * dx + dy * dy + dz * dz;

	float discriminant = t1 * t1 - 4.0f * (t2 * t0);

	if (discriminant == 0) //Il n'y a qu'une seule intersection
	{
		float t = -t1 / 2 * t2;
		Vector3* inter = new Vector3(X0 + t*dx, Y0 + t*dy, Z0 + t*dz);
		return inter;
	}
	else if(discriminant > 0)
	{
		float s1 = (-t1 - sqrt(discriminant)) / 2 * t2;
		float s2 = (-t1 + sqrt(discriminant)) / 2 * t2;

		Vector3* inter1 = new Vector3(X0 + s1 * dx, Y0 + s1 * dy, Z0 + s1 * dz);
		Vector3* inter2 = new Vector3(X0 + s2 * dx, Y0 + s2 * dy, Z0 + s2 * dz);
		
		//Camera est en (0, 0, 0) donc l'intersection a plus proche est forcément celle avec les valeurs les plus petites.
		if (inter1 < inter2)
		{
			return inter1;
		}
		else
		{
			return inter2;
		}
	}
	else { //Il n'y a pas d'intersection
		return NULL;
	}
}

bool Ray::intersectionLight(CLight * l)
{
	float X0 = m_origin->getX() - l->getCoord()->getX();
	float Y0 = m_origin->getY() - l->getCoord()->getY();
	float Z0 = m_origin->getZ() - l->getCoord()->getZ();

	float dx = m_direction->getX();
	float dy = m_direction->getY();
	float dz = m_direction->getZ();

	float t0 = (X0 * X0 + Y0 * Y0 + Z0 * Z0); //le rayon de la lumière est de 0
	float t1 = 2 * (X0 * dx + Y0 * dy + Z0 * dz);
	float t2 = dx * dx + dy * dy + dz * dz;

	float discriminant = t1 * t1 - 4.0f * (t2 * t0);

	if (discriminant == 0) //Il n'y a qu'une seule intersection
	{
		float t = -t1 / 2 * t2;
		Vector3* inter = new Vector3(X0 + t * dx, Y0 + t * dy, Z0 + t * dz);
		if (inter == l->getCoord()) //Si l'intersection est égale aux coordonnées de la lumière, il n'y a pas d'intersection d'objet
		{
			return true;
		}
	}
	else if (discriminant > 0)
	{
		float s1 = (-t1 - sqrt(discriminant)) / 2 * t2;
		float s2 = (-t1 + sqrt(discriminant)) / 2 * t2;

		Vector3* inter1 = new Vector3(X0 + s1 * dx, Y0 + s1 * dy, Z0 + s1 * dz);
		Vector3* inter2 = new Vector3(X0 + s2 * dx, Y0 + s2 * dy, Z0 + s2 * dz);

		float distance1 = sqrt(pow((m_origin->getX() - inter1->getX()), 2.0f) + pow((m_origin->getY() - inter1->getY()), 2.0f) + pow((m_origin->getZ() - inter1->getZ()),2.0f));
		float distance2 = sqrt(pow((m_origin->getX() - inter2->getX()), 2.0f) + pow((m_origin->getY() - inter2->getY()), 2.0f) + pow((m_origin->getZ() - inter2->getZ()), 2.0f));

		if (l->getCoord() == inter1 && distance1 < distance1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else { //Il n'y a pas d'intersection
		return false;
	}
}

Vector3 *Ray::getDirection()
{
	return m_direction;
}

Vector3 *Ray::getOrigin()
{
	return m_origin;
}