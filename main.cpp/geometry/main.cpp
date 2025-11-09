#include <iostream>
#include "point.h"
#include "vector.h"

int main() {
    // Test des points
    Point2f p1 = MakeP2f(3.0f, 4.0f);
    std::cout << "Point 1: " << ToString(p1) << std::endl;
    
    // Test translation
    Point2f p2 = Translate(p1, 2.0f, 3.0f);
    std::cout << "Après translation: " << ToString(p2) << std::endl;
    
    // Test rotation
    Point2f p3 = Rotate(p1, 90.0f);
    std::cout << "Après rotation 90°: " << ToString(p3) << std::endl;
    
    // Test des vecteurs
    Vector2f v1 = MakeV2f(1.0f, 2.0f);
    Vector2f v2 = MakeV2f(3.0f, 4.0f);
    std::cout << "\nVecteur 1: " << ToString(v1) << std::endl;
    std::cout << "Vecteur 2: " << ToString(v2) << std::endl;
    
    // Test addition
    Vector2f v3 = Add(v1, v2);
    std::cout << "Addition: " << ToString(v3) << std::endl;
    
    // Test produit scalaire
    float dot = Dot(v1, v2);
    std::cout << "Produit scalaire: " << dot << std::endl;
    
    // Test longueur
    float len = Length(v1);
    std::cout << "Longueur de v1: " << len << std::endl;
    
    // Test normalisation
    Vector2f v4 = Normalize(v1);
    std::cout << "v1 normalisé: " << ToString(v4) << std::endl;
    
    return 0;
}
