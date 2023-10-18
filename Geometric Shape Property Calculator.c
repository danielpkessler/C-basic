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
