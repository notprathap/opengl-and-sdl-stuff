#include "LVertexPos2D.h"
#include <vector>

extern long x;
extern long y;
extern long cx;
extern long cy;
extern long xRadius;
extern long yRadius;
extern long xChange;
extern long yChange;
extern long ellipseError;
extern long stoppingX;
extern long stoppingY;

long twoASquare();
long twoBSquare();
void initEllipse(long xRadius, long yRadius, long cx, long cy); // May be the constructor
void fillUpPoints(std::vector<LVertexPos2D>& points, long x, long y);
std::vector<LVertexPos2D> getFirstSetOfPoints(); // When tangent line slope is > -1
std::vector<LVertexPos2D> getSecondSetOfPoints(); // When tangent line slope is < -1