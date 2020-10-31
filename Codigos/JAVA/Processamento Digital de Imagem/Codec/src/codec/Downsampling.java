package codec;

import java.io.IOException;

public class Downsampling {

    public YCbCr[][] downsample (YCbCr[][] img, int w, int h, int n) throws IOException {

        if(img == null)return null;
        YCbCr[][] vec = new YCbCr[w][h];

        int aux = 0;
        vec[0][0] = new YCbCr();
        vec[0][0].setY(img[0][0].getY());
        vec[0][0].setCb(img[0][0].getCb());
        vec[0][0].setCr(img[0][0].getCr());

        for(int i = 0; i < w; i++){
            for(int j = 1; j < h; j++){

                if(aux != n){
                    vec[i][j] = new YCbCr();
                }

                vec[i][j].setY(img[i][j].getY());
                if(aux == n) {
                    vec[i][j].setCb(img[i][j].getCb());
                    vec[i][j].setCr(img[i][j].getCr());
                }
                aux++;
            }
        }
        return vec;
    }

}
