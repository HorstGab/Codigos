package codec.transformada;

public class Quantizacao {

    public int[][] quantiza(double[][] resultDCT, int w, int h){
        int [][]Q= new int[][]{null, null};
        int fatorQuantizacao = 4;

        for(int i=0; i<63;i++){
            for(int j=0; j<63;j++){
                Q[i][j] = 1 + (1 + i + j) * fatorQuantizacao;
            }
        }

        int largura;
        int altura;
        int [][]resultadoQ = new int[][]{null, null};
        for(largura =0; largura < w; largura += 8){
            for(altura=0; altura < h; altura += 8){

                for(int m88 = 0; m88 < 7; m88++){
                    for (int n88 =0; n88 < 7; n88++){
                        resultadoQ[m88][n88] = (int) (resultDCT[m88][n88] / Q[m88][n88]);
                    }
                }
            }
        }

        return resultadoQ;
    }

}
