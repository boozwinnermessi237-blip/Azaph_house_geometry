#include "vector.h"
#include "point.h"
#include <cmath>
#include <sstream>

// ========================================
// FONCTIONS DE CRÉATION DE VECTEURS
// ========================================

// Crée un vecteur simplement avec deux nombres
// Exemple: MakeV2f(3.0f, 4.0f) crée le vecteur (3, 4)
Vector2f MakeV2f(float x, float y) {
    // On crée une variable de type Vector2f
    Vector2f v;
    
    // On remplit ses coordonnées
    v.x = x;
    v.y = y;
    
    // On retourne le vecteur créé
    return v;
}

// Crée un vecteur qui va du point A vers le point B
// Exemple: si A = (1, 2) et B = (4, 6)
//          alors le vecteur AB = (4-1, 6-2) = (3, 4)
Vector2f MakeV2f(const Point2f& a, const Point2f& b) {
    Vector2f v;
    
    // Pour aller de A vers B, on fait: B - A
    v.x = b.x - a.x;
    v.y = b.y - a.y;
    
    return v;
}

// ========================================
// OPÉRATIONS ARITHMÉTIQUES DE BASE
// ========================================

// Addition de deux vecteurs
// Exemple: (2, 3) + (1, 4) = (2+1, 3+4) = (3, 7)
Vector2f Add(const Vector2f& a, const Vector2f& b) {
    Vector2f result;
    
    // On additionne chaque composante séparément
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    
    return result;
}

// Soustraction de deux vecteurs
// Exemple: (5, 8) - (2, 3) = (5-2, 8-3) = (3, 5)
Vector2f Sub(const Vector2f& a, const Vector2f& b) {
    Vector2f result;
    
    // On soustrait chaque composante séparément
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    
    return result;
}

// Multiplication d'un vecteur par un nombre (scalaire)
// Exemple: (2, 3) * 2 = (2*2, 3*2) = (4, 6)
// Cela agrandit ou rétrécit le vecteur
Vector2f Scale(const Vector2f& v, float scalar) {
    Vector2f result;
    
    // On multiplie chaque composante par le nombre
    result.x = v.x * scalar;
    result.y = v.y * scalar;
    
    return result;
}

// ========================================
// OPÉRATIONS GÉOMÉTRIQUES AVANCÉES
// ========================================

// Produit scalaire (dot product)
// C'est une opération qui donne un NOMBRE (pas un vecteur)
// Formule: a.x * b.x + a.y * b.y
// 
// À quoi ça sert ?
// - Si le résultat = 0 : les vecteurs sont PERPENDICULAIRES (angle de 90°)
// - Si le résultat > 0 : les vecteurs vont dans des directions similaires
// - Si le résultat < 0 : les vecteurs vont dans des directions opposées
//
// Exemple: (3, 0) • (0, 4) = 3*0 + 0*4 = 0 → perpendiculaires !
float Dot(const Vector2f& a, const Vector2f& b) {
    return a.x * b.x + a.y * b.y;
}

// Calcule la longueur (norme) d'un vecteur
// C'est la distance entre l'origine (0,0) et le point (x,y)
// Formule: √(x² + y²)  → c'est Pythagore !
//
// Exemple: vecteur (3, 4)
//          longueur = √(3² + 4²) = √(9 + 16) = √25 = 5
float Length(const Vector2f& v) {
    // x² + y²
    float sommeDesCarres = v.x * v.x + v.y * v.y;
    
    // √(x² + y²)
    return std::sqrt(sommeDesCarres);
}

// Normalise un vecteur = le transforme en vecteur de longueur 1
// Il garde la MÊME DIRECTION mais sa longueur devient exactement 1
// 
// Pourquoi ? C'est utile quand on veut juste la direction sans la distance
// Formule: diviser chaque composante par la longueur du vecteur
//
// Exemple: (3, 4) a une longueur de 5
//          normalisé: (3/5, 4/5) = (0.6, 0.8)
//          vérification: √(0.6² + 0.8²) = 1 ✓
Vector2f Normalize(const Vector2f& v) {
    // On calcule d'abord la longueur du vecteur
    float len = Length(v);
    
    Vector2f result;
    
    // ATTENTION: on ne peut pas diviser par 0 !
    // Si le vecteur a une longueur de 0, on retourne (0, 0)
    if (len > 0.0f) {
        // On divise chaque composante par la longueur
        result.x = v.x / len;
        result.y = v.y / len;
    } else {
        // Cas spécial: vecteur nul (0, 0)
        result.x = 0.0f;
        result.y = 0.0f;
    }
    
    return result;
}

// Interpolation linéaire (Linear intERPolation = LERP)
// Crée un vecteur "entre" deux autres vecteurs
// 
// Le paramètre t contrôle la position:
// - t = 0.0   → on obtient le vecteur a (point de départ)
// - t = 1.0   → on obtient le vecteur b (point d'arrivée)
// - t = 0.5   → on obtient le milieu entre a et b
// - t = 0.25  → on est à 25% du chemin de a vers b
//
// Formule: a + t * (b - a)
// ou équivalent: a * (1-t) + b * t
//
// Exemple: a = (0, 0), b = (10, 0), t = 0.3
//          résultat = (0, 0) + 0.3 * (10, 0) = (3, 0)
Vector2f Lerp(const Vector2f& a, const Vector2f& b, float t) {
    Vector2f result;
    
    // Pour chaque composante: début + t * (fin - début)
    result.x = a.x + t * (b.x - a.x);
    result.y = a.y + t * (b.y - a.y);
    
    return result;
}

// Déterminant = produit vectoriel en 2D (cross product)
// Donne un NOMBRE qui indique la position relative de deux vecteurs
// Formule: a.x * b.y - a.y * b.x
//
// À quoi ça sert ?
// - Si résultat > 0 : le vecteur b est à GAUCHE de a
// - Si résultat < 0 : le vecteur b est à DROITE de a
// - Si résultat = 0 : les vecteurs sont PARALLÈLES (même direction)
//
// Exemple: a = (1, 0), b = (0, 1)
//          det = 1*1 - 0*0 = 1 > 0
//          donc b est à gauche de a (c'est vrai: (0,1) est au-dessus!)
float Determinant(const Vector2f& a, const Vector2f& b) {
    return a.x * b.y - a.y * b.x;
}

// ========================================
// CONVERSION EN TEXTE
// ========================================

// Convertit le vecteur en chaîne de caractères pour l'affichage
// Format: "Vector(x, y)"
// Exemple: vecteur (3.5, -2.1) → "Vector(3.5, -2.1)"
std::string ToString(const Vector2f& v) {
    // ostringstream permet de construire une chaîne facilement
    std::ostringstream oss;
    
    // On construit la chaîne morceau par morceau
    oss << "Vector(" << v.x << ", " << v.y << ")";
    
    // On retourne la chaîne complète
    return oss.str();
}