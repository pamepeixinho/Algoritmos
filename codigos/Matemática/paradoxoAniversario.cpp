Dada uma sala com n pessoas onde a probabilidade de que no m�nimo duas delas tenham o mesmo anivers�rio � p, retorna n.

int find(double p) {
    return ceil(sqrt(2*365*log(1/(1-p))));
}
