#ifndef H_FONCTION
#define H_FONCTION
// Fonction d'activation ReLU(1)
float relu(float x) {
    if(x>0){
        return x;
    }
    else{
        return 0;
    }
}


// Fonction d'activation Sigmoïd(2)
float sigmoid(float x) {
    return 1/(1 + expf(-x));
}
#endif
