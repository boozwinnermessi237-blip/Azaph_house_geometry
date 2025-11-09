#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

// Fonction basique pour convertir n'importe quoi en string
// J'utilise un template parce que ça marche avec tous les types
template<typename T>
std::string ToString(const T& value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

// Version pour les vectors (tableaux dynamiques)
// Je veux afficher comme ça: [1, 2, 3]
template<typename T>
std::string ToString(const std::vector<T>& v) {
    std::ostringstream oss;
    oss << "[";
    
    // Je parcours tous les éléments
    for (size_t i = 0; i < v.size(); ++i) {
        oss << ToString(v[i]);  // J'appelle ToString sur chaque élément
        
        // J'ajoute une virgule sauf pour le dernier
        if (i + 1 < v.size()) {
            oss << ", ";
        }
    }
    
    oss << "]";
    return oss.str();
}

// Version pour les maps (dictionnaires)
// Format: {cle1: valeur1, cle2: valeur2}
template<typename K, typename V>
std::string ToString(const std::map<K, V>& m) {
    std::ostringstream oss;
    oss << "{";
    
    // Je parcours avec un iterateur (c'est comme un pointeur)
    for (auto it = m.begin(); it != m.end(); ++it) {
        oss << ToString(it->first) << ": " << ToString(it->second);
        
        // Virgule sauf pour le dernier
        if (std::next(it) != m.end()) {
            oss << ", ";
        }
    }
    
    oss << "}";
    return oss.str();
}

// Fonction Print qui accepte plusieurs arguments
// J'ai appris ça dans un tuto sur les variadic templates
template<typename T, typename... Args>
void Print(const T& first, const Args&... args) {
    // J'affiche le premier
    std::cout << ToString(first);
    
    // J'affiche les autres avec des virgules
    // Cette syntaxe bizarre s'appelle un "fold expression"
    ((std::cout << ", " << ToString(args)), ...);
    
    std::cout << std::endl;
}

#endif