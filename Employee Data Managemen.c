#include <stdio.h>
#include <limits.h>



// i. FONCTIONS

// 1. Afficher le contenu des trois tableaux avant le tri.

void afficher(char poste[], int cafe[], int age[], int nbPers)
{
    printf("     Poste     Age     Cafe\n\n");
    for(int i = 0; i < nbPers; i++)
    {
        printf("%3d) %3c %8d %8d\n", i, poste[i], age[i], cafe[i]);
    }
}

// 2. Fonction pour compter le nombre de programmeurs, analystes et operateurs.

int compteur(char statutVoulu, char poste[], int nbPers)
{ int compteur = 0, i;
    for(i = 0; i < nbPers; i++) {
        if (poste[i] == statutVoulu) {
            compteur++; }
    }
        return compteur;
}

// 3. Fonction pour determiner le nombre d'employes ayant 30 ans ou plus ainsi que le nombre d-employes consommant 3 ou plus tasses de cafe par jour.

int combienEntier(int entier[], int nbElem, int borne)
{ int combien = 0, i;
    for(i = 0; i < nbElem; i++) {
        if (entier[i] >= borne) {
            combien++; }
    }
    return combien;
}

// 4. Fonction pour determiner la consommation maximale de cafe et l'age maximal parmi tous les employes.

int maxi(int tableau[], int nbPers)
{ int plusGrand = tableau[0], i;
    for(i = 1; i < nbPers; i++) {
        if (tableau[i] > plusGrand) {
            plusGrand = tableau[i]; }
    }
    return plusGrand;
}

// 5. Fonction pour trier les 3 tableaux selon l'age.

void trier(char poste[], int nbCafe[], int age[], int nbPers)
{
    int i;
    for(i = 0; i < nbPers; i++) {
        int indMin = i, j;
        for(j = i+1; j < nbPers; j++)
            if(age[j] < age[indMin])
                indMin = j;
        if(indMin != j) // permuteur
        {
            int tempo = age[i];
            age[i] = age [indMin];
            age[indMin] = tempo;
            
            tempo = nbCafe[i];
            nbCafe[i] = nbCafe[indMin];
            nbCafe[indMin] = tempo;
            
            char tempo2 = poste[i];
            poste[i] = poste[indMin];
            poste[indMin] = tempo2; }
        }
}


int main ()

{
    
    // ii. NOMENCLATURE ET TABLEAUX
    
    const int BORNE_1 = 30;
    const int BORNE_2 = 3;
    char poste [] = {'P', 'P', 'O', 'A', 'P', 'A', 'P', 'P'};
    int cafe [] = {3, 1, 5, 0, 3, 4, 0, 3};
    int age [] = {25, 19, 27, 30, 65, 24, 59, 29};
    
    int nbPers = (sizeof(age) / sizeof(int));
    
    
    // iii. PROGRAMME
    
    // Afficher le contenu des trois tableaux avant le tri.
    
    printf("Affichage du contenu des trois tableaux avant le tri\n\n");
    afficher(poste, cafe, age, nbPers);
    
    /* Compter par une fonction avec return et ses appels pour afficher le nombre de :
     programmeurs, analystes et operateurs. */
    
    {
        printf("\n\nIl y a %d programmeurs\n", compteur('P', poste, nbPers));
        printf("Il y a %d analystes\n", compteur('A', poste, nbPers));
        printf("Il y a %d operateurs\n", compteur('O', poste, nbPers));
    }
    
    /* Compter par une fonction avec return et ses appels pour afficher le nombre d'employes :
     - Ayant 30 ans ou plus
     - Consommant 3 tasses de cafe ou plus par jour */
    
    {
        printf("\nLe nombre de personnes dont\n");
        printf("    - L'age depasse 30 ans est de : %d\n", combienEntier(age, nbPers, BORNE_1));
        printf("    - La consommation de cafe est de 3 tasses ou plus par jour : %d\n\n", combienEntier(cafe, nbPers, BORNE_2));
    }
    
    /* 4. Determiner par une fonction et afficher :
     - La consommation maximale de cafe de tous les employes
     - L'age maximal de tous les employes */
    
    {
        printf("Parmi tous les employes\n");
        printf("    - La consommation maximale de cafe est de : %d tasse(s)\n", maxi(cafe, nbPers));
        printf("    - L'age maximal est de : %d ans\n\n", maxi(age, nbPers));
    }
        
    // 5. Afficher les tableaux apres le tri
    
    {
        printf("\nAffichage du contenu des trois tableaux apres le tri en fonction de l'age :\n\n");
        trier(poste, cafe, age, nbPers);
        afficher(poste, cafe, age, nbPers);
    }
    
}
