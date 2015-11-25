#ifndef cube_H
#define cube_H
#include <string.h>

/*						 _____
							|			|
							|	 0	|
				 _____|_____|_____
			  |			|			|			|
				|  1	|	 2	|	 3	|
				|_____|_____|_____|
							|			|
							|	 4	|
							|_____|
							|			|
							|	 5	|
							|_____|
							
 */
#define TOP 		0
#define LEFT 		1
#define FRONT 	2
#define RIGHT 	3
#define BOTTOM	4
#define BACK		5

#define W	 0	//WHITE
#define R	 1	//RED
#define B	 2	//BLUE
#define G	 3	//GREEN
#define O	 4	//ORANGE
#define Y	 5	//YELLOW


typedef struct Face_t Face;
struct Face_t{
	int faceType;
	int faceValue[9];
};

typedef struct Cube_t Cube;
struct Cube_t{
  Face *topFace;
  Face *leftFace;
  Face *frontFace;
  Face *rightFace;
  Face *bottomFace;
  Face *backFace;
};

Face *createFace(int type, int value[9]);
void displayFace(Face *cubeFace);
Cube *createCube(int value[6][9]);

#endif // cube_H
