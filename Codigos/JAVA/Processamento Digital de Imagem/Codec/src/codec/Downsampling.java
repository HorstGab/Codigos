package codec;

import java.io.IOException;

public class Downsampling {

    public YCbCr downsample (YCbCr img, int w, int h, int n) throws IOException {

        Cb[][] cb = new Cb[w/(n/2)][h/(n/2)];
        Cr[][] cr = new Cr[w/(n/2)][h/(n/2)];
        if(img == null){
            System.err.println("Imagem Nula");
            return null;
        }

        int aux = 1;
        cb[0][0] = new Cb(img.getCb()[0][0].getCb());
        cr[0][0] = new Cr(img.getCr()[0][0].getCr());

        int x = 0;
        int y = 1;
        for(int i = 0; i < w; i++){
            for(int j = 1; j < h; j++){
                aux++;
                if(aux == n) {
                    cb[x][y] = new Cb(img.getCb()[i][j].getCb());
                    cr[x][y] = new Cr(img.getCr()[i][j].getCr());
                    y++;
                }
            }
            x++;
        }
        img.setCb(cb);
        img.setCr(cr);
        return img;
    }

}
