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
	RGBQUAD black, white, purple;
	FIBITMAP* image;
	int w=0, h=0;

	//1ere étape
	
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
	CMaterial *m2 = new CMaterial(255, 0, 255, 0.4f, 0.8f, 0.5f, 21.0f);
	s1->setMaterial(m1);
	s2->setMaterial(m2);

	//3ème étape
	// On ajoute des objets, des lumières

	image = FreeImage_Allocate(w, h, 32);

	white.rgbBlue = 255;
	white.rgbGreen = 255;
	white.rgbRed = 255;

	purple.rgbBlue = 255;
	purple.rgbGreen = 0;
	purple.rgbRed = 255;

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


			// --- 2ème étape ---
			// On calcule les intersections
			// On cherche la plus proche
			//
			// On envoie un rayon de ce point d'intersection (x0, y0, z0) vers la lumière l1
			// On recherche encore les intersections
			// Si pas d'intersection ENTRE LES POINTS
			//		> On calcule la couleur avec ka*Ia + kd*Id + ks*Is
			// Sinon
			//		> On calcule le couleur avec seulement ka*Ia

			Vector3* r_origin = new Vector3(0.0f, 0.0f, 0.0f);
			Vector3* r_direction = new Vector3(0.0f, 0.0f, 0.0f);
			Vector3* pix_position = new Vector3(i-(c->getWidth()/2.0f), j - (c->getHeight()/2.0f), - c->getFocale());
			
			r_direction = r_origin->vectorDirection(pix_position);
			
			Ray *r = new Ray(r_origin, r_direction);
			
			//S'il y a une intersection avec s1
			if (r->intersection(s1) != NULL)
			{
				Vector3* new_r_direction = new Vector3(0.0f, 0.0f, 0.0f);
				new_r_direction = r->intersection(s1)->vectorDirection(l1_pos);
				Ray *new_r = new Ray(r->intersection(s1), new_r_direction);
				
				if (!new_r->intersectionLight(l1)) //s'il n'y a pas d'objet entre la lumière et la sphère
				{
					//maintenant il faut calculer la couleur avec l'équation de Blinn-Phong
					//I = ka*Ia + kd*Id + ks*Is
					FreeImage_SetPixelColor(image, i, j, &white);
				}
				else
				{
					//couleur = ka*Ia
				}
			}
			//Ou s'il y a une intersection avec s2
			else if (r->intersection(s2) != NULL)
			{
				Vector3* new_r_direction = new Vector3(0.0f, 0.0f, 0.0f);
				new_r_direction = r->intersection(s2)->vectorDirection(l1_pos);
				Ray* new_r = new Ray(r->intersection(s2), new_r_direction);

				if (!new_r->intersectionLight(l1))
				{
					FreeImage_SetPixelColor(image, i, j, &purple);
				}
			}

			//Pour ajouter encore plus d'objets à la scène, il suffit de rajouter 
			//ce bloc ci-dessus autant de fois qu'on le souhaite avec la sphère adaptée
			
			else //S'il n'y a pas d'intersection
			{
				FreeImage_SetPixelColor(image, i, j, &black);
			}

			
			

//			FreeImage_SetPixelColor(image, i, j, &color);
		}
	}

	FreeImage_Save(FIF_BMP, image, "out.bmp");

	return EXIT_SUCCESS;
}