/* Fichier : TP 2 - A
 
 Auteur : Daniel Kessler
 Cours IFT 1810 section A
 
 But du programme :
 Calculer des sommes avec les boucles : while, do ... while & for
 Suite a ceci, on veut egalement les afficher.
 
 
    Dernière mise a jour 20 10 2022
 
*/

//  PARTIE A

#include <stdio.h>

int main()

{
    
    // Calcul et affichage de la somme 1 - boucle while
    
    {
        
        const int DEBUT_1 = 20;
        const int FIN_1 = 100;
        const int LE_PAS_1 = 5;
        int somme_1 = 0;
        int valeur = DEBUT_1;
        while (valeur <= FIN_1)
            
        {
            
            somme_1 += valeur;
            valeur += LE_PAS_1;
            
        }
        
        printf("Avec la boucle while, la premiere somme donne : %d\n", somme_1);
        
    }
    
    // Calcul et affichage de la somme 2 - boucle do ... while
    
    {
        
        int deno = 5; // Denomimateur au debut
        const int FIN_2 = 9999; // Denominateur a la fin
        float somme_2 = 0.0;
        // Le pas est correspond a denominateur + 2 (lorsque la somme augmente)
        
        do {
            somme_2 += 1.0 / deno;
            deno += 2;
        } while (deno <= FIN_2);
        
        printf("\nAvec la boucle do ... while, la deuxieme somme donne : %.3f\n", somme_2);
        
    }
    
    // Affichage du nombre de diviseurs de 720 - boucle for
    
    {
        
        const int NombreDesire = 720;
        int Diviseur = 0;
        for(int candi=1; candi <= NombreDesire; candi++) {
            if(NombreDesire % candi == 0) {
                Diviseur++; }
        } printf("\nAvec la boucle for, le nombre 720 a %d diviseurs.\n\n", Diviseur);
        
    }

    return 0;
    
}

/*

 Execution :
 
 Avec la boucle while, la premiere somme donne : 1020

 Avec la boucle do ... while, la deuxieme somme donne : 3.907

 Avec la boucle for, le nombre 720 a 30 diviseurs.

 Program ended with exit code: 0
 
 */
