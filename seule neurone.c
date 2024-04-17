#include <stdio.h>
#include <stdlib.h>
#include "loss_1.h"
#include "DeriveeLoss.h"
#include "fonction_activation.h"

typedef struct {   //modelisation pour neurone a deux input avec biais
    double w1;
    double w2;
    double biais;
} Neurone;



void entrainerNeurone(Neurone *neurone, double x1, double x2, double yi,double tauxApprentissage) {
    int iteration = 0;
        double y = sigmoid(x1 * neurone->w1 + x2 * neurone->w2 + neurone->biais);

while (Loss(yi,y) > 0.01 && iteration < 1000){ // Limitez le nombre d'itérations pour éviter une boucle infinie        // y:la prediction de sortie
        double y = sigmoid(x1 * neurone->w1 + x2 * neurone->w2 + neurone->biais);

        // Calcul de loss
        //double loss = Loss(yi,y,1);

        // Mise à jour des poids et du biais
        neurone->w1 -= tauxApprentissage * deriveeLoss(yi, y, x1);
        neurone->w2 -= tauxApprentissage * deriveeLoss(yi, y, x2);
        neurone->biais -= tauxApprentissage * (yi - y);
        iteration++;
}}

int main() {

    double dataset[110][3];//enregistrer dataset de excel dans une matrice
    int row = 0;

    FILE* file = fopen("dataset.xlsx", "r");
    if (file == NULL) {
        printf("Error\n");
        return 0;
    }

    char ligne[100];
    while (fgets(ligne, sizeof(ligne), file)) {//on lit ligne par ligne et chaque ligne va etre deviser en mot par strtok
        char* token = strtok(ligne, ",");
        int col = 0;
        while (token != NULL && col < 3) {
            dataset[row][col] = atof(token);
            token = strtok(NULL, ",");
            col++;
        }
        row++;

        }

    fclose(file);


    // Initialisation du neurone

    Neurone neurone = {0.5, 0.1, 0.01};
    double tauxApprentissage = 0.1;

    // Entraînement du neurone

    int i=0;
   while(i<row){
    entrainerNeurone(&neurone,dataset[i][0], dataset[i][1], dataset[i][2], tauxApprentissage);
    i++;
    }

    printf("%f\n",neurone.w1);

    printf("%f\n",neurone.w2);

    printf("%f\n",neurone.biais);



    }


