double deriveeLoss(float yi, float y, double xi) {
    return (yi - y) * xi;//c'est la simplification de la formule de derivee de loss par rapport a w
}
//y: actual result
//yi: predicted result
//xi: entree de la neurone (valeur input)
