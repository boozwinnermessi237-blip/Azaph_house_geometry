#include "point.h"
#include "vector.h"
#include <sstream>
#include <cmath>

// Constante pour convertir degrés en radians
const float PI = 3.14159265358979323846f;

// Crée et retourne un point avec les coordonnées données
Point2f MakeP2f(float x, float y) {
    Point2f p;
    p.x = x;
    p.y = y;
    return p;
}

// Déplace un point de dx sur l'axe X et dy sur l'axe Y
Point2f Translate(const Point2f& p, float dx, float dy) {
    Point2f result;
    result.x = p.x + dx;
    result.y = p.y + dy;
    return result;
}

// Déplace un point selon un vecteur de translation
Point2f Translate(const Point2f& p, const Vector2f& v) {
    Point2f result;
    result.x = p.x + v.x;
    result.y = p.y + v.y;
    return result;
}

// Multiplie les coordonnées du point par des facteurs d'échelle
Point2f Scale(const Point2f& p, float sx, float sy) {
    Point2f result;
    result.x = p.x * sx;
    result.y = p.y * sy;
    return result;
}

// Multiplie les coordonnées du point par un vecteur d'échelle
Point2f Scale(const Point2f& p, const Vector2f& s) {
    Point2f result;
    result.x = p.x * s.x;
    result.y = p.y * s.y;
    return result;
}

// Effectue une rotation du point autour de l'origine (0, 0)
// Formules de rotation: x' = x*cos(θ) - y*sin(θ)
//                       y' = x*sin(θ) + y*cos(θ)
Point2f Rotate(const Point2f& p, float angleDegree) {
    // Conversion degrés -> radians
    float angleRad = angleDegree * PI / 180.0f;
    
    // Calcul du cosinus et sinus
    float cosAngle = std::cos(angleRad);
    float sinAngle = std::sin(angleRad);
    
    // Application de la matrice de rotation
    Point2f result;
    result.x = p.x * cosAngle - p.y * sinAngle;
    result.y = p.x * sinAngle + p.y * cosAngle;
    
    return result;
}

// Convertit un point en chaîne format: Point(x, y)
std::string ToString(const Point2f& p) {
    std::ostringstream oss;
    oss << "Point(" << p.x << ", " << p.y << ")";
    return oss.str();
}