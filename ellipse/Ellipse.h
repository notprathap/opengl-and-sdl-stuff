#include "LVertexPos2D.h"
#include <vector>

long x;
long y;
long xRadius;
long yRadius;
long xChange;
long yChange;
long ellipseError;
long stoppingX;
long stoppingY;

long twoASquare();
long twoBSquare();
void init(long xRadius, long yRadius); // May be the constructor
void fillUpPoints(std::vector<LVertexPos2D>& points, long x, long y);
std::vector<LVertexPos2D> getFirstSetOfPoints(); // When tangent line slope is > -1
std::vector<LVertexPos2D> getSecondSetOfPoints(); // When tangent line slope is < -1