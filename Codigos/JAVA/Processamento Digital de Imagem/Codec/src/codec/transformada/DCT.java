package codec.transformada;

public class DCT {

    public static double pi = 3.142857;

    static strictfp void dctTransform(YCbCr img){
//        int i, j, k, l;
//        double ci, cj, dct1, sum;
//        double[][] dct = new double[][];

//        for (i = 0; i < m; i++)
//        {
//            for (j = 0; j < n; j++)
//            {
//                // ci and cj depends on frequency as well as
//                // number of row and columns of specified matrix
//                if (i == 0)
//                    ci = 1 / Math.sqrt(m);
//                else
//                    ci = Math.sqrt(2) / Math.sqrt(m);
//
//                if (j == 0)
//                    cj = 1 / Math.sqrt(n);
//                else
//                    cj = Math.sqrt(2) / Math.sqrt(n);
//
//                // sum will temporarily store the sum of
//                // cosine signals
//                sum = 0;
//                for (k = 0; k < m; k++)
//                {
//                    for (l = 0; l < n; l++)
//                    {
//                        dct1 = matrix[k][l] *
//                                Math.cos((2 * k + 1) * i * pi / (2 * m)) *
//                                Math.cos((2 * l + 1) * j * pi / (2 * n));
//                        sum = sum + dct1;
//                    }
//                }
//                dct[i][j] = ci * cj * sum;
//            }
//        }
//
//        for (i = 0; i < m; i++)
//        {
//            for (j = 0; j < n; j++)
//                System.out.printf("%f\t", dct[i][j]);
//            System.out.println();
//        }
//
    }

}
