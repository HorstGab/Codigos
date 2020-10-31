package codec;

import java.io.IOException;

public class Downsampling {

    public YCbCr downsample (YCbCr img, int w, int h, int n) throws IOException {

        Cb[][] cb = new Cb[w/n][h/n];
        Cr[][] cr = new Cr[w/n][h/n];

        if(img == null)return null;

        int aux = 0;
        cb[0][0] = new Cb();
        cr[0][0] = new Cr();
        cb[0][0].setCb(img.getCb()[0][0].getCb());
        cr[0][0].setCr(img.getCr()[0][0].getCr());


        for(int i = 0; i < w; i++){
            for(int j = 1; j < h; j++){


                if(aux == n) {
                    cb[i][j] = new Cb(img.getCb()[i][j].getCb());
                    cr[i][j] = new Cr(img.getCr()[i][j].getCr());
                }
                aux++;
            }
        }
        img.setCb(cb);
        img.setCr(cr);
        return img;
    }

}
