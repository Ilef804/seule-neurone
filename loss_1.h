float Loss(float yi, float y) {
       float loss = ((y * log(yi)) + ((1 - y) * log(1 - yi)));

    return -(loss);
}
//y: actual result
//yi: predicted result
