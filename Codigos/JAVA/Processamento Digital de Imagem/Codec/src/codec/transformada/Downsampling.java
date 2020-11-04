package codec.transformada;

public class Downsampling {

    public YCbCr downsample (YCbCr img, int w, int h, int n) {

        Cb[][] cb = new Cb[w/(n/2)][h/(n/2)];
        Cr[][] cr = new Cr[w/(n/2)][h/(n/2)];
        if(img == null){
            System.err.println("Imagem Nula");
            return null;
        }

        int i, j, x, y;
        for(i = 0; i < w-1; i += n/2) {
            for(j = 0; j < h-1; j += n/2) {
                x = i/(n/2);
                y = j/(n/2);

                cb[x][y] = new Cb(img.getCb()[i][j].getCb());
                cr[x][y] = new Cr(img.getCr()[i][j].getCr());
            }
        }

        img.setCb(cb);
        img.setCr(cr);
        return img;
    }

}
