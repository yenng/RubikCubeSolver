#ifndef rotation_H
#define rotation_H

#include "cube.h"

#define	R		0;		//right side rotate clockwise
#define	Ri	1;		//right side rotate anti-clockwise
#define	L		2;		//left side rotate clockwise
#define	Li	3;		//left side rotate anti-clockwise
#define	B		4;		//back side rotate clockwise
#define	Bi	5;		//back side rotate anti-clockwise
#define	D		6;		//bottom side rotate clockwise
#define	Di	7;		//bottom side rotate anti-clockwise
#define	F		8;		//front side rotate clockwise
#define	Fi	9;		//front side rotate anti-clockwise
#define	U		10;		//top side rotate clockwise
#define	Ui	11;		//top side rotate anti-clockwise

#define CLOCKWISE			0
#define ANTICLOCKWISE	1

void faceRotation(int direction, Face *face);
#endif // rotation_H
