#ifndef POINT_H
#define POINT_H

#include <string>

// Déclaration anticipée pour éviter les dépendances circulaires
struct Vector2f;

// Structure représentant un point 2D avec coordonnées x et y
struct Point2f {
    float x;
    float y;
};

// Crée un point à partir de coordonnées x et y
Point2f MakeP2f(float x, float y);

// Translate (déplace) un point avec des déplacements dx et dy
Point2f Translate(const Point2f& p, float dx, float dy);

// Translate un point avec un vecteur
Point2f Translate(const Point2f& p, const Vector2f& v);

// Met à l'échelle un point par rapport à l'origine (0,0)
Point2f Scale(const Point2f& p, float sx, float sy);

// Met à l'échelle un point avec un vecteur d'échelle
Point2f Scale(const Point2f& p, const Vector2f& s);

// Effectue une rotation d'un point autour de l'origine
// angleDegree: angle en degrés
Point2f Rotate(const Point2f& p, float angleDegree);

// Convertit un point en chaîne de caractères pour l'affichage
std::string ToString(const Point2f& p);

#endif