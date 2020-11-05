package codec.transformada;

public class Quantizacao {

    public int[][] quantiza(double[][] resultDCT, int w, int h){
        int [][]Q= new int[w][h];
        int fatorQuantizacao = 4;




        int [][]resultadoQ = new int[][]{null, null};
                for(int m88 = 0; m88 < w; m88++){
                    for (int n88 =0; n88 < h; n88++){

                        Q[m88][n88] = 1 + (1 + m88 + n88) * fatorQuantizacao;
                        resultadoQ[m88][n88] = (int) (resultDCT[m88][n88] / Q[m88][n88]);
                    }
                }

        return resultadoQ;
    }

}
