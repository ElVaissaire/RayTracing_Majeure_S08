#include "Vector3.h"
#include "FreeImage.h"
#include "CCamera.h"
#include "CSphere.h"
#include "Ray.h"
#include "CLight.h"
#include "CMaterial.h"

int main(int argc, char** argv)
{
	RGBQUAD color;
	RGBQUAD black, white;
	FIBITMAP* image;
	int w=0, h=0;

	//1er étape
	
	CCamera *c = new CCamera(640, 480, 90.0f);
	Vector3 *s1_position = new Vector3(0.0f, 0.0f, -5.0f);
	Vector3 *s2_position = new Vector3(-1.0f, -1.0f, -7.3f);
	CSphere *s1 = new CSphere(s1_position, 1.5f);
	CSphere *s2 = new CSphere(s2_position, 1.5f);
	
	w = c->getWidth();
	h = c->getHeight();

	//2eme étape
	
	Vector3* l1_pos = new Vector3(2.5f, 2.5f, -2.5f);
	CLight *l1 = new CLight(l1_pos, 255, 255, 255);
	CMaterial *m1 = new CMaterial(0, 0, 255, 0.5f, 0.7f, 0.3f, 21.0f);
	s1->setMaterial(m1);
	s2->setMaterial(m1);

	//3ème étape
	// On ajoute des objets, des lumières

	image = FreeImage_Allocate(w, h, 32);

	white.rgbBlue = 255;
	white.rgbGreen = 255;
	white.rgbRed = 255;

	black.rgbBlue = 0;
	black.rgbGreen = 0;
	black.rgbRed = 0;

	color.rgbGreen = (BYTE)0;
	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
		{
			// --- 1ere étape ---
			// On définit les valeurs de ray (dx, dy et dz)

			//Y a t'il intersection entre ray et s1
			//Si oui
			//		FreeImage_SetPixelColor(image, i, j, &white);
			// sinon
			//		FreeImage_SetPixelColor(image, i, j, &black);


			Vector3* r_origin = new Vector3(0.0f, 0.0f, 0.0f);
			Vector3* r_direction = new Vector3(0.0f, 0.0f, 0.0f);
			Vector3* pix_position = new Vector3(i-(c->getWidth()/2.0f), j - (c->getHeight()/2.0f), - c->getFocale());
			
			r_direction = r_origin->vectorDirection(pix_position);
			
			Ray *r = new Ray(r_origin, r_direction);
			
			if (r->intersection(s1))
			{
				FreeImage_SetPixelColor(image, i, j, &white);
			}
			else
			{
				FreeImage_SetPixelColor(image, i, j, &black);
			}

			
			// --- 2ème étape ---
			// On calcul les intersections
			// On cherche la plus proche
			//
			// On envoie un rayon de ce point d'intersection (x0, y0, z0) vers la lumière l1
			// On recherche encore les intersection
			// Si pas d'intersection ENTRE LES POINTS
			//		On calcul la couleur avec ka*Ia + kd*Id + ks*Is
			// Sinon
			//		On calcul le couleur avec seulement ka*Ia

//			FreeImage_SetPixelColor(image, i, j, &color);
		}
	}

	FreeImage_Save(FIF_BMP, image, "out.bmp");

	return EXIT_SUCCESS;
}