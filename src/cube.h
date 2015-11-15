#ifndef cube_H
#define cube_H
#include <string.h>

/*						 _____
							|			|
							|	 1	|
				 _____|_____|_____
			  |			|			|			|
				|  2	|	 0	|	 3	|
				|_____|_____|_____|
							|			|
							|	 4	|
							|_____|
							|			|
							|	 5	|
							|_____|
							
 */
#define FRONT 	0
#define TOP 		1
#define LEFT 		2
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
	char faceValue[9];
	Face *topSide;
	Face *leftSide;
	Face *rightSide;
	Face *bottomSide;
};
Face createFace(int type, char value[9]);
void displayFace(Face cubeFace);

#endif // cube_H
