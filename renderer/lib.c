#include "lib.h"

/**
* Calculate a vector with from two points
* Calculates a vector with from two points
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
* Calculates the sum of two vectors
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
* Calculate the difference beteween two vectors
* Calculates the difference beteween two vectors
*
* @param A: First vector
* @param B: Second vector
*
* @return the difference between the vectors
*/
Vector substractVectors(Vector A, Vector B) {
    Vector V;

    V.x = A.x - B.x;
    V.y = A.y - B.y;
    V.z = A.z - B.z;

    return V;
}

/**
* Calculate the scalarProduct of two vectors
* Calculates the scalarProduct of two vectors
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
* Calculates the norm of a vector
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
* Calculates the angle between two vectors
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
    	printf("Error: dividing by 0");
    	exit(0);
    }

    test = productABAC/(normAB * normAC);

    if (test > 1 || test < -1){
        printf("Not in range -1;1");
        exit(0);
        //exit(0);
    }

    return acos(productABAC/(normAB * normAC));
}

/**
* Verify if 3 points are aligned
* checks if 3 points are aligned
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
* Calculates a normal vector with 3 points
*
* @param A: First point'
* @param A: First point
* @param B: Second point
* @param C: Third point
*
* @return a vector normal of a plan if the 3 points are not aligned
* @return a vector normal of a plane if the 3 points are not aligned
* @return the nul vector if the 3 points are aligned
*/
Vector normalVector(Point A, Point B, Point C) {
    Vector V;

    V = initVectorNaN();
    V = initialisesVectorNaN();

    if (arePointsAligned(A,B,C)) {
        printf("We can't make a plane equation with 3 aligned points");
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
* Calculates a plane equation 3 points
* Calculates a plane equation with 3 points
*
* @param A: First point
* @param B: Second point
* @param C: Third point
*
* @return the equation of the plan formed by the 3 points non aligned
* @return a plan with nul coefficient if the 3 points are aligned
* @return the equation of the plane formed by the 3 points non aligned
* @return a plane with nul coefficient if the 3 points are aligned
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
* Calculate the image of an object on a plane
* Calculates the image of an  object on a plane
* Calculates the image of an object on a plane
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
* Calculates the intersection point between a line and a plane
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

    nominator = P.a * (L.pt.x - P.x) + P.b * (L.pt.y - P.y) + P.c * (L.pt.z - P.z);
    denominator = P.a * L.directionVector.x + P.b * L.directionVector.y + P.c * L.directionVector.z;

    if(denominator == 0) {
        return I;
    }
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
* Give the first plane that the observer sees
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
* Calculates the reflected ray and the refracted ray if it exists
*
* @param O: Observateur point
* @param normal: normal vector of the plane
* @param ray: ray which arrive
* @param refractiveIndexA: refractive index of the first medium
* @param refractiveIndexB: refractive index of the second medium
* @param Normal: Normal vector of the plane
* @param Ray: ray which arrive
* @param RefractiveIndexA: refractive index of the first medium
* @param RefractiveIndexB: refractive index of the second medium
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

/**
* Calculate the refracted ray if it exists
* Calculates the refracted ray if it exists
*
* @param O: Observateur point
* @param normal: normal vector of the plane
* @param ray: ray which arrive
* @param refractiveIndexA: refractive index of the first medium
* @param refractiveIndexB: refractive index of the second medium
* @param ray: Ray which arrive
* @param refractiveIndexA: Refractive index of the first medium
* @param refractiveIndexB: Refractive index of the second medium
*
* @return the refracted ray and the refracted ray if it exists
*/
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
* Check if the point is on the plane
* Checks if the point is on the plane
*
* @param I: Point
* @param P: Plane
*
* @return 1 if the point is on the plane
* @return 0 if the point is not on the plane
*/
int isPointOnPlane(Point I, Plane P) {
    double test;

    test = P.a * (I.x - P.x) + P.b * (I.y - P.y) + P.c * (I.z - P.z);

    if(test == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

/**
* Init a point to NaN
* initialises a point to NaN
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
* initialises a vector to NaN
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
* checks if a point have NaN coordinates
*
* @return a point initialized at NaN
*/
int isPointNaN(Point P) {
    if(isnan(P.x) || isnan(P.y) || isnan(P.z)) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

/**
* Sets a point
*
* @param x: X Component of the point
* @param y: Y Component of the point
* @param z: Z Component of the point
*
* @return a point (x, y, z)
*/
Point setPoint (double x, double y, double z){
    Point P;

    P.x = x;
    P.y = y;
    P.z = z;

    return P;
}

/**
 * Set a rgb color quickly
 * 
 * Sets a rgb color quickly
 *
 * @param r: Red component of the color
 * @param g: Green component of the color
 * @param b: Blue component of the color
 * 
 *
 * @return a rgb object (red = r, green = g, blue = b)
 */
Rgb setColor(unsigned char r, unsigned char g, unsigned char b){
    Rgb color;
    color.red = r;
    color.green = g;
    color.blue = b;
    return color;
}

/**
 * Change a caractere to an integer
 * 
 * @param caractere: the caractere
 * 
 * Changes a caractere to an integer
 *
 * @param caractere: The caractere
 *
 * @return the number corresponding to the caractere
 */
int charToInt(char caractere) {
    int number;
    number = (int)caractere;

    if(number < 58 && number > 47){
        return number - 48;
    }

    return 0;
}

/**
 * Give the vector of a rotation
 * Gives the vector of a rotation
 *
 * @param V: vector to change
 * @param tetaX: angle of rotation on x axe
 * @param tetaY: angle of rotation on y axe
 * @param tetaZ: angle of rotation on z axe
 * @param V: Vector to change
 * @param tetaX: Angle of rotation on x axe
 * @param tetaY: Angle of rotation on y axe
 * @param tetaZ: Angle of rotation on z axe
 *
 * @return vector changed
 */
Vector matriceRotation(Vector V, double tetaX, double tetaY, double tetaZ) {
    Vector vPrime;

    vPrime.x = cos(tetaZ) * (V.x * cos(tetaY) + (V.y * sin(tetaX) + V.z * cos(tetaX)) * sin(tetaY)) - sin(tetaZ) * (V.y * cos(tetaX) - V.z * sin(tetaX));
    vPrime.y = sin(tetaZ) * (V.x * cos(tetaY) + (V.y * sin(tetaX) + V.z * cos(tetaX)) * sin(tetaY)) + cos(tetaZ) * (V.y * cos(tetaX) - V.z * sin(tetaX));
    vPrime.z = -V.x * sin(tetaY) + (V.y * sin(tetaX) + V.z * cos(tetaX)) * cos(tetaY);

    return vPrime;
}}}
}}
