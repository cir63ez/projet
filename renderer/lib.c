#include "lib.h"

/**
* Calculate a vector with from two points
*
* @param A: First point
* @param B: Second point
*                    ->
* @return the vector AB
*/
Vector pointsToVector(Point A, Point B) {
    Vector V;

    V.x = B.x - A.x;
    V.y = B.y - A.y;
    V.z = B.z - A.z;

    return V;
}

/**
* Calculate the sum of two vectors
*
* @param A: First vector
* @param B: Second vector
*
* @return the sum of the vectors
*/
Vector sumVectors(Vector A, Vector B) {
    Vector V;

	V.x = A.x + B.x;
    V.y = A.y + B.y;
    V.z = A.z + B.z;

    return V;
}

/**
* Calculate the difference of two vectors
*
* @param A: First vector
* @param B: Second vector
*
* @return the difference between the vectors
*/
Vector differenceVectors(Vector A, Vector B) {
    Vector V;

    V.x = A.x - B.x;
    V.y = A.y - B.y;
    V.z = A.z - B.z;

    return V;
}

/**
* Calculate the scalarProduct of two vectors
*
* @param A: First vector
* @param B: Second vector
*
* @return the scalar product
*/
double scalarProduct(Vector A, Vector B) {
    double scalar;

    scalar = A.x * B.x + A.y * B.y + A.z * B.z;

    return scalar;
}

/**
* Calculate the norm of a vector
*
* @param A: Vector
*
* @return the norm of the vector
*/
double norm(Vector A) {
    return (sqrt(pow(A.x,2) + pow(A.y,2) + pow(A.z,2)));
}


/**
* Calculate the angle between two vectors
*
* @param A: First vector
* @param B: Second vector
*
* @return the angle between the vector
*/
double angle(Vector AB, Vector AC) {
    double productABAC;
    double normAB;
    double normAC;
    double test;

	productABAC = scalarProduct(AB,AC);
    normAB = norm(AB);
    normAC = norm(AC);

    if(normAB == 0 || normAC == 0) {
    	printf("TODO: Error div by 0\n");
    	return 0;
    }

    test = productABAC/(normAB * normAC);

    if (test > 1 || test < -1){
        printf("TODO: Fix test not in range (-1,1)\n");
        return 0;
    }

    return acos(productABAC/(normAB * normAC));
}

/**
* Verify if 3 points are aligned
*
* @param A: First point
* @param B: Second point
* @param C: Third point
*
* @return TRUE if the 3 points are aligned
* @return FALSE if the 3 points are not aligned
*/
char arePointsAligned(Point A, Point B, Point C) {
	Vector AB;
	Vector AC;
	double scalar;
    double angleCos;

    AB = pointsToVector(A,B);
    AC = pointsToVector(A,C);
    scalar = scalarProduct(AB,AC);
    angleCos = scalar/(norm(AB)*norm(AC));

    if(FEQUAL(norm(AB)*norm(AC), 0)) {return FALSE;}

    if(FEQUAL(angleCos, 1) || FEQUAL(angleCos, -1)) {
        return TRUE;
    }

    return FALSE;
}

/**
* Calculate a normal vector with 3 points
*
* @param A: First point'
* @param B: Second point
* @param C: Third point
*
* @return a vector normal of a plan if the 3 points are not aligned
* @return the nul vector if the 3 points are aligned
*/
Vector normalVector(Point A, Point B, Point C) {
    Vector V;

    V = initVectorNaN();

    if (arePointsAligned(A,B,C)) {
        printf("We can't make a plane equation with 3 aligned points\n");
    } else {
        V.x = ((B.y - A.y)*(C.z - A.z)-(B.z - A.z)*(C.y - A.y));
        V.y = -((B.x - A.x)*(C.z - A.z)-(B.z - A.z)*(C.x - A.x));
        V.z = ((B.x - A.x)*(C.y - A.y)-(B.y - A.y)*(C.x - A.x));
    }

    return V;
}

/**
* Calculate a plan equation 3 points
* Calculate a plan equation with 3 points
*
* @param A: First point
* @param B: Second point
* @param C: Third point
*
* @return the equation of the plan formed by the 3 points non aligned
* @return a plan with nul coefficient if the 3 points are aligned
*/
Plane planeEquationFromPoints(Point A, Point B, Point C) {
    Plane P;
    Vector V;

    P.a = 0;
    P.b = 0;
    P.c = 0;

    if (arePointsAligned(A,B,C)){
        printf("We can't make a plane equation with 3 aligned points\n");
    } else {
        V = normalVector(A,B,C);

        P.a = V.x;
        P.b = V.y;
        P.c = V.z;
        P.x = A.x;
        P.y = A.y;
        P.z = A.z;
        //P.d = -( P.a * A.x + P.b * A.y + P.c * A.z);
    }

    return P;
}

/**
* Calculate the image of an  object on a plane
* Calculate the image of an object on a plane
*
* @param O: Observateur point
* @param B: Object point
* @param Q: Plane
*
* @return the position of the  object's image on a plane
* @return the position of the object's image on a plane
*/
//Point imagePointOnPlane(Point O, Point B, Plane Q) {
/*Point imagePointOnPlane(Point O, Point B, Plane Q) {
    Point I;
    double t;
    double denominator;
    double nominator;

    I.x = NaN;
    I.y = NaN;
    I.z = NaN;

    t = 0;
    nominator = Q.a * B.x + Q.b * O.y + Q.c * O.z + Q.d;
    denominator = Q.a * (B.x - O.x) + Q.b * (B.y - O.y)  + Q.c * (B.z - O.z);

    if(denominator == 0){
        return I;
    } else {
        t = - nominator/denominator;
        if(t < 0){
            return I;
        }
        else {
            I.x = (B.x - O.x) * t + O.x;
            I.y = (B.y - O.y) * t + O.y;
            I.z = (B.z - O.z) * t + O.z;

            return I;
        }
    }
}
}*/

/**
* Calculate the intersection point between a line and a plane
*
* @param L: Line
* @param B: First plane
*
* @return the intersection between a line and a plane
* @return point with NaN coordinates if the point doesn't exist
*/
Point pointIntersectionLineAndPlane(Line L, Plane P) {
    double t = 0;
    Point I;
    double nominator;
    double denominator;

    I.x = NaN;
    I.y = NaN;
    I.z = NaN;

    nominator = ((P.a - P.x) * L.pt.x + (P.b - P.y) * L.pt.y + (P.c - P.z) * L.pt.z);
    denominator =((P.a - P.x) * L.directionVector.x + (P.b - P.y) * L.directionVector.y + (P.c - P.z) * L.directionVector.z);
    t = -( nominator / denominator);

    if(t < 0) {
        return I;
    }
    else {
        I.x = (L.directionVector.x) * t + L.pt.x;
        I.y = (L.directionVector.y) * t + L.pt.y;
        I.z = (L.directionVector.z) * t + L.pt.z;
        return I;
    }


}

/**
* Give the first plan that the observer sees
*
* @param L: Ray
* @param B: First plane
* @param Q: Second plane
*
* @return the plane the observer sees first
*/
Plane firstPlaneSeen(Line L, Plane P, Plane Q) {
    Point O;
    Vector direction;
    Plane test;
    Point IA;
    Point IB;
    Vector OIA;
    Vector OIB;

    O = L.pt;
    direction = L.directionVector;

    IA = pointIntersectionLineAndPlane(L, P);
    IB = pointIntersectionLineAndPlane(L, Q);

    if(isPointNaN(IA) && isPointNaN(IB)) {
        test.a = NaN;
        test.b = NaN;
        test.c = NaN;
        return test;
    }

    else if(isPointNaN(IA)) {
        return Q;
    }

    else if(isPointNaN(IB)) {
        return P;
    }

    else {
        OIA = pointsToVector(O, IA);
        OIB = pointsToVector(O, IB);
        if(norm(OIA) > norm(OIB)) {
            return Q;
        } else {
            return P;
        }
    }
}



/**
* Calculate the reflected ray and the refracted ray if it exists
*
* @param O: Observateur point
* @param normal: normal vector of the plane
* @param ray: ray which arrive
* @param refractiveIndexA: refractive index of the first medium
* @param refractiveIndexB: refractive index of the second medium
*
* @return the reflected ray and the refracted ray if it exists
*/
Line reflectedRay(Point I, Vector normal, Vector ray, double refractiveIndexA, double refractiveIndexB) {
    double thetaA;
    double thetaB;
    Vector rayReflected;
    Line reflected;
    double radicand = 0;

    radicand = 1 - pow(refractiveIndexA/refractiveIndexB,2) * (1 - pow(cos(thetaA),2));

    thetaA = acos(scalarProduct(ray, normal));


    reflected.pt = I;

    if(radicand < 0){
        rayReflected.x = ray.x + (2 * cos(thetaA)) * normal.x;
        rayReflected.y = ray.y + (2 * cos(thetaA)) * normal.y;
        rayReflected.z = ray.z + (2 * cos(thetaA)) * normal.z;
    }

    else if(cos(thetaA) >= 0){
        thetaB = sqrt(radicand);
        rayReflected.x = ray.x + (2 * cos(thetaA)) * normal.x;
        rayReflected.y = ray.y + (2 * cos(thetaA)) * normal.y;
        rayReflected.z = ray.z + (2 * cos(thetaA)) * normal.z;
    }
    else {
        thetaB = sqrt(radicand);
        rayReflected.x = ray.x + (2 * cos(thetaA)) * normal.x;
        rayReflected.y = ray.y + (2 * cos(thetaA)) * normal.y;
        rayReflected.z = ray.z + (2 * cos(thetaA)) * normal.z;
    }
    reflected.directionVector = rayReflected;
    return reflected;
}

Line refractedRay(Point I, Vector normal, Vector ray, double refractiveIndexA, double refractiveIndexB) {
    double thetaA;
    double thetaB;
    Vector rayRefracted;
    Line refracted;
    double radicand = 0;

    radicand = 1 - pow(refractiveIndexA/refractiveIndexB,2) * (1 - pow(cos(thetaA),2));

    thetaA = acos(scalarProduct(ray, normal));

    refracted.pt = I;

    if(radicand < 0){
        rayRefracted = initVectorNaN();
    }

    else if(cos(thetaA) >= 0){
        thetaB = sqrt(radicand);
        rayRefracted.x = (refractiveIndexA / refractiveIndexB) * ray.x + ((refractiveIndexA / refractiveIndexB) * cos(thetaA) - cos(thetaB))* normal.x;
        rayRefracted.y = (refractiveIndexA / refractiveIndexB) * ray.y + ((refractiveIndexA / refractiveIndexB) * cos(thetaA) - cos(thetaB))* normal.y;
        rayRefracted.z = (refractiveIndexA / refractiveIndexB) * ray.z + ((refractiveIndexA / refractiveIndexB) * cos(thetaA) - cos(thetaB))* normal.z;

    }
    else {
        thetaB = sqrt(radicand);
        rayRefracted.x = (refractiveIndexA / refractiveIndexB) * ray.x + ((refractiveIndexA / refractiveIndexB) * cos(thetaA) + cos(thetaB))* normal.x;
        rayRefracted.y = (refractiveIndexA / refractiveIndexB) * ray.y + ((refractiveIndexA / refractiveIndexB) * cos(thetaA) + cos(thetaB))* normal.y;
        rayRefracted.z = (refractiveIndexA / refractiveIndexB) * ray.z + ((refractiveIndexA / refractiveIndexB) * cos(thetaA) + cos(thetaB))* normal.z;

    }
    refracted.directionVector = rayRefracted;
    return refracted;
}

/**
* Check if the point is on the polygon
*
* @param A: list of point
* @param B: test point
*                    ->
* @return the vector AB
*/
int isOnPolygon(Point *li,double numberOfPoint,Point t){
    double *listOfNorm;

    if(isPointNaN(t)) {
        return FALSE;
    }

    listOfNorm = (double*)malloc(sizeof(double) * numberOfPoint);

    for (int actualPoint = 0; actualPoint < numberOfPoint; actualPoint++) {
        for (int otherPoint = 0; otherPoint < numberOfPoint; otherPoint++) {
            if(actualPoint != otherPoint){
                if(listOfNorm[actualPoint] < norm(pointsToVector(li[actualPoint], li[otherPoint]))) {
                    listOfNorm[actualPoint] = norm(pointsToVector(li[actualPoint], li[otherPoint]));
                }
            }
        }
    }

    for (int testPoint = 0; testPoint < numberOfPoint; testPoint++) {
        if(listOfNorm[testPoint] < norm(pointsToVector(li[testPoint],t))){
            free(listOfNorm);
            return FALSE;
        }
    }

    free(listOfNorm);
    return TRUE;
}

/**
* Init a point to NaN
*
*
* @return a point initialized at NaN
*/
Point initPointNaN() {
    Point P;
    P.x = NaN;
    P.y = NaN;
    P.z = NaN;
    return P;
}

/**
* Init a vector to NaN
*
*
* @return a point initialized at NaN
*/
Vector initVectorNaN() {
    Vector V;
    V.x = NaN;
    V.y = NaN;
    V.z = NaN;
    return V;
}

/**
* Verify if a point have NaN coordinates
*
*
* @return a point initialized at NaN
*/
int isPointNaN(Point P) {
    if(isnan(P.x) || isnan(P.y) || isnan(P.z)) {
        return FALSE;
    }
    else {
        return TRUE;
    }
}

//en travaux

int testIfLightCutEllipse(double *object,light li,point c){
    Ellipse e;
    e=decodeEllipse(object);

    free(e);
}

int testIfLightCutBrick(double *object,light li,point c){
    Brick b;
    b=decodeBrick(object);

    free(b);
}

int testIfLightCutTetrahedron(double *object,light li,point c){
    Brick t;
    t=decode(object);

    free(t);
}

int testIfLightCutObject(light li,List listOfObject,point c){
    for (int actualObject = 0; actualObject < *(listOfObject)->nbElement; actualObject++) {
        if(*(listOfObject+actualObject)->type==ELLIPSE_TYPE){

        }
        else if(*(listOfObject+actualObject)->type==BRICK_TYPE){

        }
        else if(*(listOfObject+actualObject)->type==TETRAHEDRON_TYPE)){
        }
    }
}

int isLit(Point c,liste *listOfObject,Light *listOfLight,double numberOfLight){
	Object* objectWithContact;
	int actualLight=0;
		for (int actualObject = 0; actualObject < *(listOfObject)->nbElement; actualObject++) {
			if(pointsToVector(c,listOfLight[actualLight])){
				break;
			}
		}
	return FALSE;
 }
