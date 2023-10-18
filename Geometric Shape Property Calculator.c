/* Fichier : TP 1 - B
 
 Auteur : Daniel Kessler
 Cours IFT 1810 section A
 But du programme :
 
 Saisir un caractere representant le code d'une figure geometrique parmi : un cercle (c ou C), un rectangle (r ou R) ou un carre (k ou K).
 En fonction de la figure, on saisira ses coordonnees : pour le cercle son rayon, pour le rectangle sa largeur et sa longueur et pour le carre ses cotes. Avec ces informations et des formules geometriques on calculera le perimetre et la surface des figures geometriques traitees.
 
 Formules geometriques :
 
 - CERCLE :
    • Perimetre : 2 * π * rayon
    • Surface : π * rayon * rayon
 - RECTANGLE :
    • Perimetre : 2 * (longueur + largeur)
    • Surface : longueur * largeur
 - CARRE :
    • Perimetre : 4 * cotes
    • Surface : cote * cote
 
 π : Constante de type reel qui vaut 3.14159...
 
 Le programme traitera les figures jusqu'au moment ou l'usager decide d'arreter.
 Le programme determinera :
    Le nombre total de rectangles traites, le perimetre le plus grand des cercles traites, la surface la plus grande des rectangles traites, le cote le plus petit des carres traites et le perimetre moyen des rectangles traites.
 
    Dernière mise a jour 29 09 2022
 
*/



//  PARTIE B

#include <stdio.h>
#include <ctype.h>

int main ()

{
    
    // i) Nomenclature
    
    const float π = 3.14159;
    
    char codeFig, reponse;
    
    float rayon, perimetre, surface, longueur, largeur, cote;
    float perimPGC = 0.0; // Perimetre le plus grand des cercles traites.
    float surfSGR = 0.0; // Surface la plus grande des rectangles traites.
    float coteCPK = 20.2f; // Cote le plus petit des carres traites.
    float somPoids = 0.0; // Somme des perimetres des rectangles traites.
    float perimMoyR = 0.0; // Perimetre moyen des rectangles traites.
    float somPerimR; // Moyenne du perimetre des rectangles traites.
    
    int nbRect = 0;
    int nbCercle = 0;
    int nbCarre = 0;
    
    // ii) Programme
    
    do
    
    {
        
        printf("Tapez c ou C pour un cercle\n");
        printf("Tapez r ou R pour un rectangle\n");
        printf("Tapez k ou K pour un carre\n");
        scanf(" %c", &codeFig);
        
        // conversion en lettre MAJUSCULE
        codeFig = toupper(codeFig);
        
        switch (codeFig)
                    
        {
            case 'C' : // Traitement de(s) cercle(s)
                
                nbCercle++;
                printf("Tapez le rayon du cercle ");
                scanf("%f", &rayon);
                perimetre = 2 * π * rayon;
                surface = π * rayon * rayon;
                    printf("Infos du cercle traite :\n");
                       printf(" - rayon     : %.1f\n", rayon);
                       printf(" - perimetre : %.2f\n", perimetre);
                       printf(" - surface   : %.2f\n", surface);
                
                // Affichage du perimetre plus grand des cercles traites
                if (perimetre > perimPGC)
                           perimPGC = perimetre;
                break;
            
            case 'R' : // Traitement de(s) rectangle(s)
                
                nbRect++;
                printf("Tapez la longueur du rectangle ");
                scanf("%f", &longueur);
                printf("Tapez la largeur du rectangle ");
                scanf("%f", &largeur);
                perimetre = 2 * (longueur + largeur);
                surface = longueur * largeur;
                    printf("Infos du rectangle traite :\n");
                       printf(" - longueur  : %.1f\n", longueur);
                       printf(" - largeur   : %.1f\n", largeur);
                       printf(" - perimetre : %.2f\n", perimetre);
                       printf(" - surface   : %.2f\n", surface);
                
                // Calcul de la moyenne du perimetre de(s) rectangle(s) traite(s)
                somPerimR = somPerimR + perimetre;

                // Affichage de la surface plus grande des rectangles traites
                if (surface > surfSGR)
                           surfSGR = surface;
                break;
            
            case 'K' : // Traitement de(s) carre(s)
                
                nbCarre++;
                printf("Tapez le cote du carre ");
                scanf("%f", &cote);
                perimetre = 4 * cote;
                surface = cote * cote;
                    printf("Infos du carre traite :\n");
                       printf(" - cote      : %.1f\n", cote);
                       printf(" - perimetre : %.2f\n", perimetre);
                       printf(" - surface   : %.2f\n", surface);
                
                // Affichage du cote plus petit des carres traites
                if (cote < coteCPK)
                           coteCPK = cote;
                break;
                
            default: printf("Code imprevu\n");
        
        }
        
        printf("\nAvez-vous une autre figure a traiter ? (o ou n) ");
        scanf(" %c", &reponse);
        
    }   while(toupper(reponse) == 'O');
    
    printf("Le nombre total de rectangle(s) traite(s) : %d\n", nbRect);
    
    if (nbRect > 0)
        printf("La surface la plus grande des rectangles traites : %.2f\n", surfSGR);
    else
        printf("Pas de rectangle traite => pas de surfSGR a calculer \n");
    
    if (nbCercle > 0)
        printf("Le perimetre le plus grand des cercles traites : %.2f\n", perimPGC);
    else
        printf("Pas de cercle traite => pas de perimPCG a calculer \n");
    
    if (nbCarre > 0)
        printf("Le cote le plus petit des carres traites : %.1f\n", coteCPK);
    else
        printf("Pas de carre traite => pas de coteCPK a calculer \n");
    
    if (nbRect > 0)
        printf("Le perimetre moyen des rectangles est %.2f\n", somPerimR / nbRect);

    
    return 0;
    
}

/*
 
 Execution :
 
 Tapez c ou C pour un cercle
 Tapez r ou R pour un rectangle
 Tapez k ou K pour un carre
 c
 Tapez le rayon du cercle 7.5
 Infos du cercle traite :
  - rayon     : 7.5
  - perimetre : 47.12
  - surface   : 176.71

 Avez-vous une autre figure a traiter ? (o ou n) o
 Tapez c ou C pour un cercle
 Tapez r ou R pour un rectangle
 Tapez k ou K pour un carre
 r
 Tapez la longueur du rectangle 9.2
 Tapez la largeur du rectangle 4.8
 Infos du rectangle traite :
  - longueur  : 9.2
  - largeur   : 4.8
  - perimetre : 28.00
  - surface   : 44.16

 Avez-vous une autre figure a traiter ? (o ou n) o
 Tapez c ou C pour un cercle
 Tapez r ou R pour un rectangle
 Tapez k ou K pour un carre
 C
 Tapez le rayon du cercle 8.3
 Infos du cercle traite :
  - rayon     : 8.3
  - perimetre : 52.15
  - surface   : 216.42

 Avez-vous une autre figure a traiter ? (o ou n) o
 Tapez c ou C pour un cercle
 Tapez r ou R pour un rectangle
 Tapez k ou K pour un carre
 R
 Tapez la longueur du rectangle 5.3
 Tapez la largeur du rectangle 3.7
 Infos du rectangle traite :
  - longueur  : 5.3
  - largeur   : 3.7
  - perimetre : 18.00
  - surface   : 19.61

 Avez-vous une autre figure a traiter ? (o ou n) o
 Tapez c ou C pour un cercle
 Tapez r ou R pour un rectangle
 Tapez k ou K pour un carre
 c
 Tapez le rayon du cercle 3.9
 Infos du cercle traite :
  - rayon     : 3.9
  - perimetre : 24.50
  - surface   : 47.78

 Avez-vous une autre figure a traiter ? (o ou n) o
 Tapez c ou C pour un cercle
 Tapez r ou R pour un rectangle
 Tapez k ou K pour un carre
 r
 Tapez la longueur du rectangle 15.1
 Tapez la largeur du rectangle 5.9
 Infos du rectangle traite :
  - longueur  : 15.1
  - largeur   : 5.9
  - perimetre : 42.00
  - surface   : 89.09

 Avez-vous une autre figure a traiter ? (o ou n) n
 Le nombre total de rectangle(s) traite(s) : 3
 La surface la plus grande des rectangles traites : 89.09
 Le perimetre le plus grand des cercles traites : 52.15
 Pas de carre traite => pas de coteCPK a calculer
 Le perimetre moyen des rectangles est 29.33
 Program ended with exit code: 0
 
 */
