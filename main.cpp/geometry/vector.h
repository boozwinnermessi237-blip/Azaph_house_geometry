#ifndef VECTOR_H
#define VECTOR_H

#include <string>

// Déclaration anticipée pour éviter les dépendances circulaires
struct Point2f;

// Structure représentant un vecteur 2D
struct Vector2f {
    float x;
    float y;
};

// Crée un vecteur à partir de coordonnées x et y
Vector2f MakeV2f(float x, float y);

// Crée un vecteur à partir de deux points (du point a vers le point b)
Vector2f MakeV2f(const Point2f& a, const Point2f& b);

// Additionne deux vecteurs
Vector2f Add(const Vector2f& a, const Vector2f& b);

// Soustrait deux vecteurs (a - b)
Vector2f Sub(const Vector2f& a, const Vector2f& b);

// Multiplie un vecteur par un scalaire (nombre)
Vector2f Scale(const Vector2f& v, float scalar);

// Calcule le produit scalaire de deux vecteurs
float Dot(const Vector2f& a, const Vector2f& b);

// Calcule la longueur (norme) d'un vecteur
float Length(const Vector2f& v);

// Normalise un vecteur (le rend de longueur 1)
Vector2f Normalize(const Vector2f& v);

// Interpolation linéaire entre deux vecteurs
// t=0 retourne a, t=1 retourne b, t=0.5 retourne le milieu
Vector2f Lerp(const Vector2f& a, const Vector2f& b, float t);

// Calcule le déterminant (produit vectoriel 2D)
// Utile pour savoir si un vecteur est à gauche ou à droite d'un autre
float Determinant(const Vector2f& a, const Vector2f& b);

// Convertit un vecteur en chaîne de caractères
std::string ToString(const Vector2f& v);

#endif