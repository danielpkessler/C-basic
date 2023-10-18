#include <stdio.h>
#include <limits.h>

int main ()

{
    
    // i) Nomenclature
    
    char prgrm = 'P', oper = 'O', anlst = 'A', secrtr = 'S';
    char poste [] = {'P', 'P', 'O', 'A', 'P', 'A', 'P', 'A'};
    int cafe [] = {2, 1, 7, 0, 5, 2, 1, 3};
    int age [] = {25, 19, 27, 26, 49, 24, 56, 29};
    
    int nbPrgrm = 0;
    int nbOper = 0;
    int nbAnlst = 0;
    int nbSecret = 0;
    int nbPers = (sizeof(age)/sizeof(int));
    int i; // indice
    
    
    // ii) Programme
    
    
    // Afficher le contenu des trois tableaux :
    
        printf("Le contenu des 3 tableaux avant le tri :\n\n");
        printf("     Poste     Age     Cafe\n\n");
        for(i = 0; i < nbPers; i++)
            printf("%3d) %3c %8d %8d\n", i, poste[i], age[i], cafe[i]);
        printf("\n\n");
    
    {
        
    // Traitement des programmeurs
    
        for(i = 0; i < nbPers; i++)
            if (poste[i] == 'P')
                nbPrgrm++;
        printf("Il y a %d programmeur(s).\n", nbPrgrm);
        
        // Traitement des secretaires
        
        for(i = 0; i < nbPers; i++) {
            if (poste[i] == 'S') {
                nbSecret++;}
        }
        printf("Il y a %d secretaire(s).\n", nbSecret);
        
        
    // Traitement pour la consommation minimale de cafe des analysetes
        
        int cafeMinAnlst = INT_MAX;
        for(i = 0; i < nbPers; i++)
            if (poste[i] == 'A') {
                nbAnlst++;
                if (cafe[i] < cafeMinAnlst)
                    cafeMinAnlst = cafe[i]; }
        if (nbAnlst > 0)
            printf ("La consommation minimale de tasses de cafe des analystes est de : %d tasse(s).\n", cafeMinAnlst);
        else
            printf("Aucun programmeur => pas de traitement necessaire.\n");
        
        
    // Traitement pour determiner et afficher l'age maximal des programmeurs
        
        int ageMaxPrgrm = INT_MIN;
        for(i = 0; i < nbPers; i++)
            
            if (age[i] > ageMaxPrgrm)
                ageMaxPrgrm = age[i];
        printf("L'age maximal des programmeurs est de : %d ans.\n", ageMaxPrgrm);
        
        
    // Traitement pour calculer et afficher la consommation moyenne de cafe des operateurs
        
        int nbCafeOper = 0;
        int somCafeOper = 0;
        for(i = 0; i < nbPers; i++) {
            
            if (poste[i] == 'O') {
                nbCafeOper++;
                somCafeOper += cafe[i];
            }
        }
        if (nbCafeOper > 0)
            printf("La consommation moyenne de cafe des operateurs est de : %d tasses.\n", somCafeOper / nbCafeOper);
        else
            printf("Aucun operateur, => pas necessaire de traiter leur age moyen.\n");
        
        
    // Traitement pour calculer l'age moyen de tous les employes
        
        int somAge = 0;
        for(i = 0; i <nbPers; i++) {
            somAge += age[i];
        }
        printf("L'age moyen des employes traites est de : %d ans.\n\n", somAge / nbPers);
        
        
        
    // Triage des trois tableaux en fonciton de l'age
        
        for (i = 0; i < nbPers-1; i++)
        {   int indMin = i;
            for (int j = i+1; j < nbPers; j++)
                if (age[j] < age[indMin])
                    indMin = j;
            if (indMin != i)
            { int tempo = age[i];
                age[i] = age[indMin];
                age[indMin] = tempo;
                int tempoCafe = cafe[i];
                cafe[i] = cafe[indMin];
                cafe[indMin] = tempoCafe;
                char tempoPoste = poste[i];
                poste[i] = poste[indMin];
                poste[indMin] = tempoPoste;
            }
        }
        
    // Affichage des characteristiques des employes traites apres le tri, selon l'age
        
        printf("\nContenu des 3 tableaux apres le tri selon l'age :\n\n");
        printf("     Poste  Age     Cafe\n\n");
        for (i = 0; i < nbPers; i++)
            printf("%3d) %3c %5d %8d\n", i, poste[i], age[i], cafe[i]);
        printf("\n");
        
    }
    
    return 0;
}
