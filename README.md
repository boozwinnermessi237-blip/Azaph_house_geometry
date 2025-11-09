#  Bibliothèque de Géométrie 2D en C++

Salut ! Voici mon projet de géométrie 2D que j'ai fait pour apprendre le C++. J'ai suivi des tutos en ligne et lu pas mal de docs C++ pour comprendre comment tout ça fonctionne.

##  C'est quoi ce projet ?

C'est une petite bibliothèque qui permet de manipuler des **points** et des **vecteurs** en 2D. Genre, tu peux déplacer des points, calculer des distances, faire des rotations, etc. Rien de fou mais c'est cool pour apprendre !

## Structure du projet

```
projet/
├── main.cpp                 # Mon fichier de test
└── geometry/
    ├── point.h              # Déclarations pour les points
    ├── point.cpp            # Code des fonctions de points
    ├── vector.h             # Déclarations pour les vecteurs
    ├── vector.cpp           # Code des fonctions de vecteurs
    └── utils.h              # Fonctions utilitaires (Print, ToString)
```

##  Comment compiler et lancer

J'utilise g++ pour compiler. Voilà la commande :

```bash
g++ -std=c++17 main.cpp geometry/point.cpp geometry/vector.cpp -o mon_programme
./mon_programme
```

**Note:** J'utilise C++17 parce que j'ai besoin des "fold expressions" pour ma fonction `Print()`. J'ai appris ça dans un tuto sur les templates.

##  Ce que j'ai appris

### Les Points (point.h / point.cpp)

Un point c'est juste des coordonnées (x, y). J'ai fait des fonctions pour :

- **MakeP2f(x, y)** : Créer un point
- **Translate()** : Déplacer un point
- **Scale()** : Agrandir/rétrécir un point
- **Rotate()** : Faire tourner un point autour de (0, 0)

**Exemple simple :**
```cpp
Point2f p = MakeP2f(3.0f, 4.0f);           // Crée le point (3, 4)
Point2f p2 = Translate(p, 1.0f, 2.0f);     // Le déplace à (4, 6)
```

Pour la rotation, j'ai dû utiliser `cos` et `sin`. J'ai trouvé les formules dans la doc et j'ai compris que ça vient des matrices de rotation. C'était un peu compliqué au début mais ça marche !

### Les Vecteurs (vector.h / vector.cpp)

Un vecteur c'est comme une direction avec une longueur. Genre, "va 3 vers la droite et 2 vers le haut".

Fonctions principales :

- **MakeV2f(x, y)** : Créer un vecteur
- **Add() / Sub()** : Addition et soustraction
- **Length()** : Calculer la longueur (avec Pythagore !)
- **Normalize()** : Transformer en vecteur de taille 1
- **Dot()** : Produit scalaire (pour savoir si deux vecteurs sont perpendiculaires)
- **Determinant()** : Savoir si un vecteur est à gauche ou à droite d'un autre

**Exemple simple :**
```cpp
Vector2f v1 = MakeV2f(3.0f, 4.0f);
float longueur = Length(v1);              // Donne 5.0 (formule : √(3²+4²))
Vector2f v2 = Normalize(v1);              // Donne (0.6, 0.8) de longueur 1
```

Le truc cool que j'ai appris : le **produit scalaire**. Si le résultat est 0, ça veut dire que les vecteurs sont à 90° l'un de l'autre. Pratique pour la physique !

### Les Utilitaires (utils.h)

J'ai créé des fonctions pour afficher mes données facilement. Avant je faisais des `cout` partout et c'était le bordel.

**ToString()** : Convertit n'importe quoi en string
- J'ai utilisé des **templates** pour que ça marche avec tous les types
- J'ai fait des versions spéciales pour `vector` et `map`

**Print()** : Affiche plusieurs trucs en une ligne
- J'utilise des **variadic templates** (j'ai galéré à comprendre ça)
- Et des **fold expressions** C++17 (super pratique !)

**Exemple :**
```cpp
Print("Position:", point, "Vitesse:", vecteur);
// Affiche : Position:, Point(2, 3), Vitesse:, Vector(1, -1)
```

## Les trucs que j'ai appris en faisant ça

### 1. Les structures (struct)

Au lieu de faire plein de variables séparées, je groupe tout :
```cpp
struct Point2f {
    float x;
    float y;
};
```

C'est plus propre et plus facile à manipuler.

### 2. Les templates

Au début j'y comprenais rien, mais en gros ça permet d'écrire une fonction qui marche avec plusieurs types. Genre `ToString()` marche avec `int`, `float`, `Point2f`, etc.

```cpp
template<typename T>
std::string ToString(const T& value) {
    // ...
}
```

Le compilateur génère automatiquement la bonne version selon le type qu'on utilise.

### 3. Le const &

J'ai appris à mettre `const` devant mes paramètres pour dire "je ne vais pas modifier cette valeur". Et le `&` c'est pour éviter de copier les données (plus rapide).

```cpp
Point2f Translate(const Point2f& p, float dx, float dy)
//                ^^^^^^^^^^^^^
//                Ne sera pas modifié + pas de copie
```

### 4. Les fichiers .h et .cpp

J'ai séparé les **déclarations** (dans .h) et les **définitions** (dans .cpp). C'est la façon standard de faire en C++. Comme ça on peut réutiliser le code facilement.

### 5. Les includes guards

Les `#ifndef`, `#define`, `#endif` au début des .h, c'est pour éviter d'inclure plusieurs fois le même fichier. J'ai compris ça quand j'avais des erreurs de "redéfinition".

##  Exemples d'utilisation

### Déplacer un personnage dans un jeu

```cpp
Point2f joueur = MakeP2f(0.0f, 0.0f);
Vector2f deplacement = MakeV2f(5.0f, 3.0f);
joueur = Translate(joueur, deplacement);
```

### Calculer une distance

```cpp
Point2f a = MakeP2f(0.0f, 0.0f);
Point2f b = MakeP2f(3.0f, 4.0f);
Vector2f vecteurAB = MakeV2f(a, b);
float distance = Length(vecteurAB);  // Résultat : 5.0
```

### Vérifier si deux vecteurs sont perpendiculaires

```cpp
Vector2f v1 = MakeV2f(1.0f, 0.0f);
Vector2f v2 = MakeV2f(0.0f, 1.0f);
float dot = Dot(v1, v2);  // Résultat : 0 → ils sont perpendiculaires !
```

## Problèmes que j'ai rencontrés

1. **Division par zéro** : Dans `Normalize()`, il faut vérifier que la longueur n'est pas 0 sinon ça plante
2. **Degrés vs Radians** : Les fonctions `cos` et `sin` utilisent des radians, j'ai dû convertir mes degrés
3. **Dépendances circulaires** : Point.h inclut Vector.h et vice-versa. J'ai réglé ça avec des "forward declarations"

## Ressources que j'ai utilisées

- Documentation C++ sur cppreference.com
- Tutos YouTube sur les templates
- Des forums pour comprendre les fold expressions
- La doc de `<cmath>` pour les fonctions trigonométriques
- Des articles sur la géométrie vectorielle

## 🚀 Améliorations possibles

Si j'ai le temps, je veux ajouter :
- [ ] Des vecteurs 3D (x, y, z)
- [ ] Des matrices de transformation
- [ ] Des fonctions pour les collisions
- [ ] Des tests unitaires (j'ai vu ça dans un tuto)

## 💡 Conclusion

Ce projet m'a vraiment aidé à comprendre :
- Comment organiser du code C++
- Les templates (même si c'est encore un peu flou)
- La géométrie vectorielle
- Comment compiler avec plusieurs fichiers
- Et si vous plait je suis pas max j'ai juste vu des tutos et copier un peu les trucs de Mr teuguia 
- Er si vous voulez mon aide, regarder des tutos

C'est pas parfait mais ça marche et j'ai appris plein de trucs ! Si t'as des questions ou des suggestions, hésite pas.

---