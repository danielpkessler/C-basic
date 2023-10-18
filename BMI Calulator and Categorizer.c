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
