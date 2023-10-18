/* Fichier : TP 1 - A
 
 Auteur : Daniel Kessler
 Cours IFT 1810 section A
 But du programme :
 
Saisir les informations d'un patient sedentaire : poids en kg, taille metres et son indice de masse corporelle (imc) selon la formule suivante : imc = poids / (taille x taille).
 
 On veut egalement categoriser et compter les individus traites.
 Le programme traitera les donnees jusqu-au mooment ou l'usager decide d'arreter.
 On compte et affiche:
 - le nombre total de peronnes traitees.
 - le nombre de personnes qui ont un poids maigre, poids normal, poids embonpoint et poids obese.
 
    Dernière mise a jour 26 09 2022
*/

//  PARTIE A

#include <stdio.h>

int main()

{
    
    // i) Nomenclature
    
    float taille, poids, imc;
    
    const float Maigreur = 18.5; // Borne maigreur
    const float Normal = 25; // Borne normal
    const float Embonpoint = 30; // Borne embonpoint
    
    char reponse; // si usager veut continuer : oui ou non
   
    int nbPers = 0; // nb. de personnes
    int nbPersM = 0; // nb. de personnes en maigreur : rsique eleve a accru
    int nbPersN = 0; // nb. de personnes en poids normal : risque faible
    int nbPersE = 0; // nb. de personnes en poids Embonpoint : risque eleve
    int nbPersO = 0; // nb. de personnes en obesite : risque tres eleve
    
    // ii) Programme
    
    do

    {
        
        nbPers++; // Une personne de plus a traiter
        
        // Saisir la taille en nombre de metres
        printf("Tapez la taille en metre(s) : \n");
        scanf("%f", &taille);
        
        // Saisir le poids en nombre de kilogrammes
        printf("Tapez la taille en kilogramme(s) : \n");
        scanf("%f", &poids);
        
        printf("%.2f metre\n", taille);
        printf("%.1f kilogramme(s)\n", poids);
        
        // Convertir en indice de masse corporelle
        imc = poids / (taille * taille);
        printf("L'indice de masse corporelle (imc) est %.1f : \n", imc);
        
        if (imc < Maigreur)
        {
            printf("Maigreur, risque eleve accru\n");
            nbPersM++;
        }
        else if (imc >= Maigreur && imc <= Normal)
        {
            nbPersN++;
            printf("Poids normal, risque faible\n");
        }
        else if (imc >= Normal && imc <= Embonpoint)
        {
            nbPersE++;
            printf("Embonpoint, risque eleve\n");
        }
            else if (imc >= Embonpoint)
        {
            nbPersO++;
            printf("Obesite, risque tres eleve\n");
        }
            
        printf("Voulez-vous continuer? (o ou n) ");
        scanf(" %c", &reponse);
    }   while (reponse == 'o' || reponse == 'O');
    
    // Nombre de personnes traitees et nombre de personnes traitees en fonction de leur categorie.
    
    printf("Au total, on traite %d personne(s)\n", nbPers);
    printf("Il y a %d personne(s) ayant un imc maigre\n", nbPersM);
    printf("Il y a %d personne(s) ayant un imc normal\n", nbPersN);
    printf("Il y a %d personne(s) ayant un imc emboinpoint\n", nbPersE);
    printf("Il y a %d personne(s) ayant un imc obese\n", nbPersO);
    
return 0;

}

/*
 
Execution :

Tapez la taille en metre(s) :
1.98
Tapez la taille en kilogramme(s) :
51
1.98 metre
51.0 kilogramme(s)
L'indice de masse corporelle (imc) est 13.0 :
Maigreur, risque eleve accru
Voulez-vous continuer? (o ou n) o
Tapez la taille en metre(s) :
1.63
Tapez la taille en kilogramme(s) :
69.4
1.63 metre
69.4 kilogramme(s)
L'indice de masse corporelle (imc) est 26.1 :
Embonpoint, risque eleve
Voulez-vous continuer? (o ou n) o
Tapez la taille en metre(s) :
1.65
Tapez la taille en kilogramme(s) :
60
1.65 metre
60.0 kilogramme(s)
L'indice de masse corporelle (imc) est 22.0 :
Poids normal, risque faible
Voulez-vous continuer? (o ou n) o
Tapez la taille en metre(s) :
1.72
Tapez la taille en kilogramme(s) :
100
1.72 metre
100.0 kilogramme(s)
L'indice de masse corporelle (imc) est 33.8 :
Obesite, risque tres eleve
Voulez-vous continuer? (o ou n) n
Au total, on traite 4 personne(s)
Il y a 1 personne(s) ayant un imc maigre
Il y a 1 personne(s) ayant un imc normal
Il y a 1 personne(s) ayant un imc emboinpoint
Il y a 1 personne(s) ayant un imc obese
Program ended with exit code: 0

*/
