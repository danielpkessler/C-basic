/* Fichier : TP 2 - B
 
 Auteur : Daniel Kessler
 Cours IFT 1810 section A
 But du programme :
 
Saisir les declarations et initialisations de 3 tableaux :
 
1 - poste : Correspond au poste des individus traites.
 poste prendra les suivantes valeurs possibles :
    A = Analyste ; P = Programmeur ; O = Operateur ; S = Secretaire
 
2 - nbCafe : Correspond au nombre de cafes consommes par les individus traites.
 nbCafe prendra les valeurs des entiers suivants : 2, 1, 7, 0, 5, 2, 1, 3.

3 - age : Correspond a l'age des individus traites.
 age prendra les valeurs eniters suivants : 25, 19, 27, 26, 49, 24, 56, 29.
 
 Le poste, l'age et la consommation de cafe correspondent aux caracteristiques de chaque individu respectivement.
 
On veut afficher le contenu des trois tableaux, compter et d'afficher le nombre de programmeurs et le nombre de secretaires. On veut aussi determiner et afficher la consommation minimale de cafe des analystes, l'age maximal des programmeurs, la consommation moyenne de cafe des operateurs et l'age moyen de tous les employes. Dernierement, on veut trier les trois tableaux en fonction de l'age (de maniere croissante).
 
    Dernière mise a jour 8 11 2022
 
*/

//  PARTIE B

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

/*
 
 iii) EXECUTION
 
 Le contenu des 3 tableaux avant le tri :

      Poste     Age     Cafe

   0)   P       25        2
   1)   P       19        1
   2)   O       27        7
   3)   A       26        0
   4)   P       49        5
   5)   A       24        2
   6)   P       56        1
   7)   A       29        3


 Il y a 4 programmeur(s).
 Il y a 0 secretaire(s).
 La consommation minimale de tasses de cafe des analystes est de : 0 tasse(s).
 L'age maximal des programmeurs est de : 56 ans.
 La consommation moyenne de cafe des operateurs est de : 7 tasses.
 L'age moyen des employes traites est de : 31 ans.


 Contenu des 3 tableaux apres le tri selon l'age :

      Poste  Age     Cafe

   0)   P    19        1
   1)   A    24        2
   2)   P    25        2
   3)   A    26        0
   4)   O    27        7
   5)   A    29        3
   6)   P    49        5
   7)   P    56        1

 Program ended with exit code: 0
 
 */
