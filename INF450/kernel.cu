// #@title Kernel principal e Kernel de Redução - Fixo em 64 numero de blocos
// %%writefile kernel.cu

__global__ void kernel(float *v_r) {

    int stride = gridDim.x * 2;
    for (int s = stride / 2; s > 0; s >>= 1) {

        if (threadIdx.x < s) {
            v_r[threadIdx.x] += v_r[threadIdx.x + s];
            v_r[threadIdx.x + stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 2 * stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 3 * stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 4 * stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 5 * stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 6 * stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 7 * stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 8 * stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 9 * stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 10 * stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 11 * stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 12 * stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 13 * stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 14 * stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 15 * stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 16 * stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 17 * stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 18 * stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 19 * stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 20 * stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 21 * stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 22 * stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 23 * stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 24 * stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 25 * stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 26 * stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 27 * stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 28 * stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 29 * stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 30 * stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 31 * stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 32 * stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 33 * stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 34 * stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 35 * stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 36 * stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 37 * stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 38 * stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 39 * stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 40 * stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 41 * stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 42 * stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 43 * stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 44 * stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 45 * stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 46 * stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 47 * stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 48 * stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 49 * stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 50 * stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 51 * stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 52 * stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 53 * stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 54 * stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 55 * stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 56 * stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 57 * stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 58 * stride] += v_r[threadIdx.x + s + stride];
            v_r[threadIdx.x + 59 * stride] += v_r[threadIdx.x + s + stride];
        }
    } // for
}

__global__ void kmeansReduce(float *input, float *centroids, int *counter, const int n, float *v_r) {
    int Dim = 3;                                                // dim =2 cada thread vai pegar um par x,y (pular de dois em dois)
    long int i = (blockIdx.x * blockDim.x + threadIdx.x) * Dim; // i cada thread pega seu numero thread 0 pega x0y0 thread 1 pega x1y1 ...
    int pulo = gridDim.x * blockDim.x * Dim;

    // K = 4, D = 3 => 4(1+3) = 16 Variáveis K(1+D)
    float nc4_0x = 0;
    float nc4_0y = 0;
    float nc4_0z = 0;

    float nc4_1x = 0;
    float nc4_1y = 0;
    float nc4_1z = 0;

    float nc4_2x = 0;
    float nc4_2y = 0;
    float nc4_2z = 0;

    float nc4_3x = 0;
    float nc4_3y = 0;
    float nc4_3z = 0;

    float cont4_0 = 0;
    float cont4_1 = 0;
    float cont4_2 = 0;
    float cont4_3 = 0;

    // K = 5, D = 3 =: 5(1+3) = 20 Variáveis K(1+D)
    float nc5_0x = 0;
    float nc5_0y = 0;
    float nc5_0z = 0;

    float nc5_1x = 0;
    float nc5_1y = 0;
    float nc5_1z = 0;

    float nc5_2x = 0;
    float nc5_2y = 0;
    float nc5_2z = 0;

    float nc5_3x = 0;
    float nc5_3y = 0;
    float nc5_3z = 0;

    float nc5_4x = 0;
    float nc5_4y = 0;
    float nc5_4z = 0;

    float cont5_0 = 0;
    float cont5_1 = 0;
    float cont5_2 = 0;
    float cont5_3 = 0;
    float cont5_4 = 0;

    // K = 6, D = 3 => 6(1+3) = 24 Variáveis K(1+D)
    float nc6_0x = 0;
    float nc6_0y = 0;
    float nc6_0z = 0;

    float nc6_1x = 0;
    float nc6_1y = 0;
    float nc6_1z = 0;

    float nc6_2x = 0;
    float nc6_2y = 0;
    float nc6_2z = 0;

    float nc6_3x = 0;
    float nc6_3y = 0;
    float nc6_3z = 0;

    float nc6_4x = 0;
    float nc6_4y = 0;
    float nc6_4z = 0;

    float nc6_5x = 0;
    float nc6_5y = 0;
    float nc6_5z = 0;

    float cont6_0 = 0;
    float cont6_1 = 0;
    float cont6_2 = 0;
    float cont6_3 = 0;
    float cont6_4 = 0;
    float cont6_5 = 0;

    float point_d1, point_d2, point_d3;
    float k0_d1, k0_d2, k0_d3, k1_d1, k1_d2, k1_d3, k2_d1, k2_d2, k2_d3, k3_d1, k3_d2, k3_d3, k4_d1, k4_d2, k4_d3, k5_d1, k5_d2, k5_d3;
    float k;

    for (int j = 0; j < WORK; j++) {
        if (i < n) {
            // PARA K = 4
            // map
            point_d1 = input[i + 0];
            point_d2 = input[i + 1];
            point_d3 = input[i + 2];

            k0_d1 = point_d1 - centroids[0]; // primeiro centroide // ler fora pra ler uma vez só
            k0_d2 = point_d2 - centroids[1];
            k0_d3 = point_d3 - centroids[2];

            k1_d1 = point_d1 - centroids[3]; // segundo centroide
            k1_d2 = point_d2 - centroids[4];
            k1_d3 = point_d3 - centroids[5];

            k2_d1 = point_d1 - centroids[6]; // terceiro centroide
            k2_d2 = point_d2 - centroids[7];
            k2_d3 = point_d3 - centroids[8];

            k3_d1 = point_d1 - centroids[9]; // quarto centroide
            k3_d2 = point_d2 - centroids[10];
            k3_d3 = point_d3 - centroids[11];

            // k4_d1 = point_d1 - centroids[12]; // quinto centroide
            // k4_d2 = point_d2 - centroids[13];
            // k4_d3 = point_d3 - centroids[14];

            // k5_d1 = point_d1 - centroids[15]; // sexto centroide
            // k5_d2 = point_d2 - centroids[16];
            // k5_d3 = point_d3 - centroids[17];

            // dist euclidiana eleva ao quad e soma
            k0_d1 *= k0_d1;
            k0_d2 *= k0_d2;
            k0_d3 *= k0_d3;

            k1_d1 *= k1_d1;
            k1_d2 *= k1_d2;
            k1_d3 *= k1_d3;

            k2_d1 *= k2_d1;
            k2_d2 *= k2_d2;
            k2_d3 *= k2_d3;

            // reduce sum
            k0_d1 = k0_d1 + k0_d2 + k0_d3;
            k1_d2 = k1_d1 + k1_d2 + k1_d3;
            k2_d3 = k2_d1 + k2_d2 + k2_d3;

            // reduce min
            k = (k0_d1 < k1_d1) ? 0 : 1;
            k0_d1 = (k0_d1 < k1_d1) ? k0_d1 : k1_d1;
            k = (k0_d1 < k2_d1) ? k : 2;
            k0_d1 = (k0_d1 < k2_d1) ? k0_d1 : k2_d1;
            k = (k0_d1 < k3_d1) ? k : 3;

            if (k == 0) {
                nc4_0x += point_d1;
                nc4_0y += point_d2;
                nc4_0z += point_d3;
                cont4_0++;
            } else if (k == 1) {
                nc4_1x += point_d1;
                nc4_1y += point_d2;
                nc4_1z += point_d3;
                cont4_1++;
            } else if (k == 2) {
                nc4_2x += point_d1;
                nc4_2y += point_d2;
                nc4_2z += point_d3;
                cont4_2++;
            } else {
                nc4_3x += point_d1;
                nc4_3y += point_d2;
                nc4_3z += point_d3;
                cont4_3++;
            }

            // PARA K = 5
            // map
            point_d1 = input[i + 0];
            point_d2 = input[i + 1];
            point_d3 = input[i + 2];

            k0_d1 = point_d1 - centroids[12]; // primeiro centroide // ler fora pra ler uma vez só
            k0_d2 = point_d2 - centroids[13];
            k0_d3 = point_d3 - centroids[14];

            k1_d1 = point_d1 - centroids[15]; // segundo centroide
            k1_d2 = point_d2 - centroids[16];
            k1_d3 = point_d3 - centroids[17];

            k2_d1 = point_d1 - centroids[18]; // terceiro centroide
            k2_d2 = point_d2 - centroids[19];
            k2_d3 = point_d3 - centroids[20];

            k3_d1 = point_d1 - centroids[21]; // quarto centroide
            k3_d2 = point_d2 - centroids[22];
            k3_d3 = point_d3 - centroids[23];

            k4_d1 = point_d1 - centroids[24]; // quinto centroide
            k4_d2 = point_d2 - centroids[25];
            k4_d3 = point_d3 - centroids[26];

            // k5_d1 = point_d1 - centroids[15]; // sexto centroide
            // k5_d2 = point_d2 - centroids[16];
            // k5_d3 = point_d3 - centroids[17];

            // dist euclidiana eleva ao quad e soma
            k0_d1 *= k0_d1;
            k0_d2 *= k0_d2;
            k0_d3 *= k0_d3;

            k1_d1 *= k1_d1;
            k1_d2 *= k1_d2;
            k1_d3 *= k1_d3;

            k2_d1 *= k2_d1;
            k2_d2 *= k2_d2;
            k2_d3 *= k2_d3;

            k3_d1 *= k3_d1;
            k3_d2 *= k3_d2;
            k3_d3 *= k3_d3;

            k4_d1 *= k4_d1;
            k4_d2 *= k4_d2;
            k4_d3 *= k4_d3;

            // reduce sum
            k0_d1 = k0_d1 + k0_d2 + k0_d3;
            k1_d2 = k1_d1 + k1_d2 + k1_d3;
            k2_d3 = k2_d1 + k2_d2 + k2_d3;
            k3_d1 = k3_d1 + k3_d2 + k3_d3;
            k4_d1 = k4_d1 + k4_d2 + k4_d3;

            // reduce min
            k = (k0_d1 < k1_d1) ? 0 : 1;
            k0_d1 = (k0_d1 < k1_d1) ? k0_d1 : k1_d1;
            k = (k0_d1 < k2_d1) ? k : 2;
            k0_d1 = (k0_d1 < k2_d1) ? k0_d1 : k2_d1;
            k = (k0_d1 < k3_d1) ? k : 3;
            k0_d1 = (k0_d1 < k3_d1) ? k0_d1 : k3_d1;
            k = (k0_d1 < k4_d1) ? k : 4;

            if (k == 0) {
                nc5_0x += point_d1;
                nc5_0y += point_d2;
                nc5_0z += point_d3;
                cont5_0++;
            } else if (k == 1) {
                nc5_1x += point_d1;
                nc5_1y += point_d2;
                nc5_1z += point_d3;
                cont5_1++;
            } else if (k == 2) {
                nc5_2x += point_d1;
                nc5_2y += point_d2;
                nc5_2z += point_d3;
                cont5_2++;
            } else if (k == 3) {
                nc5_3x += point_d1;
                nc5_3y += point_d2;
                nc5_3z += point_d3;
                cont5_3++;
            } else {
                nc5_4x += point_d1;
                nc5_4y += point_d2;
                nc5_4z += point_d3;
                cont5_4++;
            }

            // PARA K = 6
            // map
            point_d1 = input[i + 0];
            point_d2 = input[i + 1];
            point_d3 = input[i + 2];

            k0_d1 = point_d1 - centroids[27]; // primeiro centroide // ler fora pra ler uma vez só
            k0_d2 = point_d2 - centroids[28];
            k0_d3 = point_d3 - centroids[29];

            k1_d1 = point_d1 - centroids[30]; // segundo centroide
            k1_d2 = point_d2 - centroids[31];
            k1_d3 = point_d3 - centroids[32];

            k2_d1 = point_d1 - centroids[33]; // terceiro centroide
            k2_d2 = point_d2 - centroids[34];
            k2_d3 = point_d3 - centroids[35];

            k3_d1 = point_d1 - centroids[36]; // quarto centroide
            k3_d2 = point_d2 - centroids[37];
            k3_d3 = point_d3 - centroids[38];

            k4_d1 = point_d1 - centroids[39]; // quinto centroide
            k4_d2 = point_d2 - centroids[40];
            k4_d3 = point_d3 - centroids[41];

            k5_d1 = point_d1 - centroids[42]; // sexto centroide
            k5_d2 = point_d2 - centroids[43];
            k5_d3 = point_d3 - centroids[44];

            // dist euclidiana eleva ao quad e soma
            k0_d1 *= k0_d1;
            k0_d2 *= k0_d2;
            k0_d3 *= k0_d3;

            k1_d1 *= k1_d1;
            k1_d2 *= k1_d2;
            k1_d3 *= k1_d3;

            k2_d1 *= k2_d1;
            k2_d2 *= k2_d2;
            k2_d3 *= k2_d3;

            k3_d1 *= k3_d1;
            k3_d2 *= k3_d2;
            k3_d3 *= k3_d3;

            k4_d1 *= k4_d1;
            k4_d2 *= k4_d2;
            k4_d3 *= k4_d3;

            k5_d1 *= k5_d1;
            k5_d2 *= k5_d2;
            k5_d3 *= k5_d3;

            // reduce sum
            k0_d1 = k0_d1 + k0_d2 + k0_d3;
            k1_d2 = k1_d1 + k1_d2 + k1_d3;
            k2_d3 = k2_d1 + k2_d2 + k2_d3;
            k3_d1 = k3_d1 + k3_d2 + k3_d3;
            k4_d1 = k4_d1 + k4_d2 + k4_d3;
            k5_d1 = k5_d1 + k5_d2 + k5_d3;

            // reduce min
            k = (k0_d1 < k1_d1) ? 0 : 1;
            k0_d1 = (k0_d1 < k1_d1) ? k0_d1 : k1_d1;
            k = (k0_d1 < k2_d1) ? k : 2;
            k0_d1 = (k0_d1 < k2_d1) ? k0_d1 : k2_d1;
            k = (k0_d1 < k3_d1) ? k : 3;
            k0_d1 = (k0_d1 < k3_d1) ? k0_d1 : k3_d1;
            k = (k0_d1 < k4_d1) ? k : 4;
            k0_d1 = (k0_d1 < k4_d1) ? k0_d1 : k4_d1;
            k = (k0_d1 < k5_d1) ? k : 5;

            if (k == 0) {
                nc6_0x += point_d1;
                nc6_0y += point_d2;
                nc6_0z += point_d3;
                cont6_0++;
            } else if (k == 1) {
                nc6_1x += point_d1;
                nc6_1y += point_d2;
                nc6_1z += point_d3;
                cont6_1++;
            } else if (k == 2) {
                nc6_2x += point_d1;
                nc6_2y += point_d2;
                nc6_2z += point_d3;
                cont6_2++;
            } else if (k == 3) {
                nc6_3x += point_d1;
                nc6_3y += point_d2;
                nc6_3z += point_d3;
                cont6_3++;
            } else if (k == 4) {
                nc6_4x += point_d1;
                nc6_4y += point_d2;
                nc6_4z += point_d3;
                cont6_4++;
            } else {
                nc6_5x += point_d1;
                nc6_5y += point_d2;
                nc6_5z += point_d3;
                cont6_5++;
            }
        }
        i = i + pulo;
    }

    // usando Redução na memória compartilhada
    __shared__ float partial_sum[BLOCO * 60];
    partial_sum[threadIdx.x] = nc4_0x;
    partial_sum[threadIdx.x + blockDim.x] = nc4_0y; // guarda o x de todo mundo, depois o y de todo mundo, depois o z de todo mundo, depois o cont de todos
    partial_sum[threadIdx.x + 2 * blockDim.x] = nc4_0z;
    partial_sum[threadIdx.x + 3 * blockDim.x] = nc4_1x;
    partial_sum[threadIdx.x + 4 * blockDim.x] = nc4_1y;
    partial_sum[threadIdx.x + 5 * blockDim.x] = nc4_1z;
    partial_sum[threadIdx.x + 6 * blockDim.x] = nc4_2x;
    partial_sum[threadIdx.x + 7 * blockDim.x] = nc4_2y;
    partial_sum[threadIdx.x + 8 * blockDim.x] = nc4_2z;
    partial_sum[threadIdx.x + 9 * blockDim.x] = nc4_3x;
    partial_sum[threadIdx.x + 10 * blockDim.x] = nc4_3y;
    partial_sum[threadIdx.x + 11 * blockDim.x] = nc4_3z;
    partial_sum[threadIdx.x + 12 * blockDim.x] = cont4_0;
    partial_sum[threadIdx.x + 13 * blockDim.x] = cont4_1;
    partial_sum[threadIdx.x + 14 * blockDim.x] = cont4_2;
    partial_sum[threadIdx.x + 15 * blockDim.x] = cont4_3;
    partial_sum[threadIdx.x + 16 * blockDim.x] = nc5_0x;
    partial_sum[threadIdx.x + 17 * blockDim.x] = nc5_0y;
    partial_sum[threadIdx.x + 18 * blockDim.x] = nc5_0z;
    partial_sum[threadIdx.x + 19 * blockDim.x] = nc5_1x;
    partial_sum[threadIdx.x + 20 * blockDim.x] = nc5_1y;
    partial_sum[threadIdx.x + 21 * blockDim.x] = nc5_1z;
    partial_sum[threadIdx.x + 22 * blockDim.x] = nc5_2x;
    partial_sum[threadIdx.x + 23 * blockDim.x] = nc5_2y;
    partial_sum[threadIdx.x + 24 * blockDim.x] = nc5_2z;
    partial_sum[threadIdx.x + 25 * blockDim.x] = nc5_3x;
    partial_sum[threadIdx.x + 26 * blockDim.x] = nc5_3y;
    partial_sum[threadIdx.x + 27 * blockDim.x] = nc5_3z;
    partial_sum[threadIdx.x + 28 * blockDim.x] = nc5_4x;
    partial_sum[threadIdx.x + 29 * blockDim.x] = nc5_4y;
    partial_sum[threadIdx.x + 30 * blockDim.x] = nc5_4z;
    partial_sum[threadIdx.x + 31 * blockDim.x] = cont5_0;
    partial_sum[threadIdx.x + 32 * blockDim.x] = cont5_1;
    partial_sum[threadIdx.x + 33 * blockDim.x] = cont5_2;
    partial_sum[threadIdx.x + 34 * blockDim.x] = cont5_3;
    partial_sum[threadIdx.x + 35 * blockDim.x] = cont5_4;
    partial_sum[threadIdx.x + 36 * blockDim.x] = nc6_0x;
    partial_sum[threadIdx.x + 37 * blockDim.x] = nc6_0y;
    partial_sum[threadIdx.x + 38 * blockDim.x] = nc6_0z;
    partial_sum[threadIdx.x + 39 * blockDim.x] = nc6_1x;
    partial_sum[threadIdx.x + 40 * blockDim.x] = nc6_1y;
    partial_sum[threadIdx.x + 41 * blockDim.x] = nc6_1z;
    partial_sum[threadIdx.x + 42 * blockDim.x] = nc6_2x;
    partial_sum[threadIdx.x + 43 * blockDim.x] = nc6_2y;
    partial_sum[threadIdx.x + 44 * blockDim.x] = nc6_2z;
    partial_sum[threadIdx.x + 45 * blockDim.x] = nc6_3x;
    partial_sum[threadIdx.x + 46 * blockDim.x] = nc6_3y;
    partial_sum[threadIdx.x + 47 * blockDim.x] = nc6_3z;
    partial_sum[threadIdx.x + 48 * blockDim.x] = nc6_4x;
    partial_sum[threadIdx.x + 49 * blockDim.x] = nc6_4y;
    partial_sum[threadIdx.x + 50 * blockDim.x] = nc6_4z;
    partial_sum[threadIdx.x + 51 * blockDim.x] = nc6_5x;
    partial_sum[threadIdx.x + 52 * blockDim.x] = nc6_5y;
    partial_sum[threadIdx.x + 53 * blockDim.x] = nc6_5z;
    partial_sum[threadIdx.x + 54 * blockDim.x] = cont6_0;
    partial_sum[threadIdx.x + 55 * blockDim.x] = cont6_1;
    partial_sum[threadIdx.x + 56 * blockDim.x] = cont6_2;
    partial_sum[threadIdx.x + 57 * blockDim.x] = cont6_3;
    partial_sum[threadIdx.x + 58 * blockDim.x] = cont6_4;
    partial_sum[threadIdx.x + 59 * blockDim.x] = cont6_5;

    __syncthreads();

    for (int s = blockDim.x / 2; s > 0; s >>= 1) {
        if (threadIdx.x < s) {
            partial_sum[threadIdx.x] += partial_sum[threadIdx.x + s];                                     // x0
            partial_sum[threadIdx.x + blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x];           // y0
            partial_sum[threadIdx.x + 2 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 2];   // z0
            partial_sum[threadIdx.x + 3 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 3];   // x1
            partial_sum[threadIdx.x + 4 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 4];   // y1
            partial_sum[threadIdx.x + 5 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 5];   // z1
            partial_sum[threadIdx.x + 6 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 6];   // x2
            partial_sum[threadIdx.x + 7 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 7];   // y2
            partial_sum[threadIdx.x + 8 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 8];   // z2
            partial_sum[threadIdx.x + 9 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 9];   // x3
            partial_sum[threadIdx.x + 10 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 10]; // y3
            partial_sum[threadIdx.x + 11 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 11]; // z3
            partial_sum[threadIdx.x + 12 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 12]; // c0
            partial_sum[threadIdx.x + 13 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 13]; // c1
            partial_sum[threadIdx.x + 14 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 14]; // c2
            partial_sum[threadIdx.x + 15 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 15]; // c3
            partial_sum[threadIdx.x + 16 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 16]; // x0
            partial_sum[threadIdx.x + 17 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 17]; // y0
            partial_sum[threadIdx.x + 18 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 18]; // z0
            partial_sum[threadIdx.x + 19 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 19]; // x1
            partial_sum[threadIdx.x + 20 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 20]; // y1
            partial_sum[threadIdx.x + 21 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 21]; // z1
            partial_sum[threadIdx.x + 22 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 22]; // x2
            partial_sum[threadIdx.x + 23 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 23]; // y2
            partial_sum[threadIdx.x + 24 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 24]; // z2
            partial_sum[threadIdx.x + 25 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 25]; // x3
            partial_sum[threadIdx.x + 26 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 26]; // y3
            partial_sum[threadIdx.x + 27 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 27]; // z3
            partial_sum[threadIdx.x + 28 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 28]; // x4
            partial_sum[threadIdx.x + 29 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 29]; // y4
            partial_sum[threadIdx.x + 30 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 30]; // z4
            partial_sum[threadIdx.x + 31 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 31]; // c0
            partial_sum[threadIdx.x + 32 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 32]; // c1
            partial_sum[threadIdx.x + 33 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 33]; // c2
            partial_sum[threadIdx.x + 34 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 34]; // c3
            partial_sum[threadIdx.x + 35 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 35]; // c4
            partial_sum[threadIdx.x + 36 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 36]; // x0
            partial_sum[threadIdx.x + 37 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 37]; // y0
            partial_sum[threadIdx.x + 38 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 38]; // z0
            partial_sum[threadIdx.x + 39 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 39]; // x1
            partial_sum[threadIdx.x + 40 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 40]; // y1
            partial_sum[threadIdx.x + 41 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 41]; // z1
            partial_sum[threadIdx.x + 42 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 42]; // x2
            partial_sum[threadIdx.x + 43 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 43]; // y2
            partial_sum[threadIdx.x + 44 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 44]; // z2
            partial_sum[threadIdx.x + 45 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 45]; // x3
            partial_sum[threadIdx.x + 46 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 46]; // y3
            partial_sum[threadIdx.x + 47 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 47]; // z3
            partial_sum[threadIdx.x + 48 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 48]; // x4
            partial_sum[threadIdx.x + 49 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 49]; // y4
            partial_sum[threadIdx.x + 50 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 50]; // z4
            partial_sum[threadIdx.x + 51 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 51]; // x5
            partial_sum[threadIdx.x + 52 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 52]; // y5
            partial_sum[threadIdx.x + 53 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 53]; // z5
            partial_sum[threadIdx.x + 54 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 54]; // c0
            partial_sum[threadIdx.x + 55 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 55]; // c1
            partial_sum[threadIdx.x + 56 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 56]; // c2
            partial_sum[threadIdx.x + 57 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 57]; // c3
            partial_sum[threadIdx.x + 58 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 58]; // c4
            partial_sum[threadIdx.x + 59 * blockDim.x] += partial_sum[threadIdx.x + s + blockDim.x * 59]; // c5
        }
        __syncthreads();
    }
    if (threadIdx.x == 0) {
        v_r[blockIdx.x] = partial_sum[0];
        v_r[blockIdx.x + gridDim.x] = partial_sum[blockDim.x];
        v_r[blockIdx.x + 2 * gridDim.x] = partial_sum[2 * blockDim.x]; // X01X02X03...Y01
        v_r[blockIdx.x + 3 * gridDim.x] = partial_sum[3 * blockDim.x];
        v_r[blockIdx.x + 4 * gridDim.x] = partial_sum[4 * blockDim.x];
        v_r[blockIdx.x + 5 * gridDim.x] = partial_sum[5 * blockDim.x];
        v_r[blockIdx.x + 6 * gridDim.x] = partial_sum[6 * blockDim.x];
        v_r[blockIdx.x + 7 * gridDim.x] = partial_sum[7 * blockDim.x];
        v_r[blockIdx.x + 8 * gridDim.x] = partial_sum[8 * blockDim.x];
        v_r[blockIdx.x + 9 * gridDim.x] = partial_sum[9 * blockDim.x];
        v_r[blockIdx.x + 10 * gridDim.x] = partial_sum[10 * blockDim.x];
        v_r[blockIdx.x + 11 * gridDim.x] = partial_sum[11 * blockDim.x];
        v_r[blockIdx.x + 12 * gridDim.x] = partial_sum[12 * blockDim.x];
        v_r[blockIdx.x + 13 * gridDim.x] = partial_sum[13 * blockDim.x];
        v_r[blockIdx.x + 14 * gridDim.x] = partial_sum[14 * blockDim.x];
        v_r[blockIdx.x + 15 * gridDim.x] = partial_sum[15 * blockDim.x];
        v_r[blockIdx.x + 16 * gridDim.x] = partial_sum[16 * blockDim.x];
        v_r[blockIdx.x + 17 * gridDim.x] = partial_sum[17 * blockDim.x];
        v_r[blockIdx.x + 18 * gridDim.x] = partial_sum[18 * blockDim.x];
        v_r[blockIdx.x + 19 * gridDim.x] = partial_sum[19 * blockDim.x];
        v_r[blockIdx.x + 20 * gridDim.x] = partial_sum[20 * blockDim.x];
        v_r[blockIdx.x + 21 * gridDim.x] = partial_sum[21 * blockDim.x];
        v_r[blockIdx.x + 22 * gridDim.x] = partial_sum[22 * blockDim.x];
        v_r[blockIdx.x + 23 * gridDim.x] = partial_sum[23 * blockDim.x];
        v_r[blockIdx.x + 24 * gridDim.x] = partial_sum[24 * blockDim.x];
        v_r[blockIdx.x + 25 * gridDim.x] = partial_sum[25 * blockDim.x];
        v_r[blockIdx.x + 26 * gridDim.x] = partial_sum[26 * blockDim.x];
        v_r[blockIdx.x + 27 * gridDim.x] = partial_sum[27 * blockDim.x];
        v_r[blockIdx.x + 28 * gridDim.x] = partial_sum[28 * blockDim.x];
        v_r[blockIdx.x + 29 * gridDim.x] = partial_sum[29 * blockDim.x];
        v_r[blockIdx.x + 30 * gridDim.x] = partial_sum[30 * blockDim.x];
        v_r[blockIdx.x + 31 * gridDim.x] = partial_sum[31 * blockDim.x];
        v_r[blockIdx.x + 32 * gridDim.x] = partial_sum[32 * blockDim.x];
        v_r[blockIdx.x + 33 * gridDim.x] = partial_sum[33 * blockDim.x];
        v_r[blockIdx.x + 34 * gridDim.x] = partial_sum[34 * blockDim.x];
        v_r[blockIdx.x + 35 * gridDim.x] = partial_sum[35 * blockDim.x];
        v_r[blockIdx.x + 36 * gridDim.x] = partial_sum[36 * blockDim.x];
        v_r[blockIdx.x + 37 * gridDim.x] = partial_sum[37 * blockDim.x];
        v_r[blockIdx.x + 38 * gridDim.x] = partial_sum[38 * blockDim.x];
        v_r[blockIdx.x + 39 * gridDim.x] = partial_sum[39 * blockDim.x];
        v_r[blockIdx.x + 40 * gridDim.x] = partial_sum[40 * blockDim.x];
        v_r[blockIdx.x + 41 * gridDim.x] = partial_sum[41 * blockDim.x];
        v_r[blockIdx.x + 42 * gridDim.x] = partial_sum[42 * blockDim.x];
        v_r[blockIdx.x + 43 * gridDim.x] = partial_sum[43 * blockDim.x];
        v_r[blockIdx.x + 44 * gridDim.x] = partial_sum[44 * blockDim.x];
        v_r[blockIdx.x + 45 * gridDim.x] = partial_sum[45 * blockDim.x];
        v_r[blockIdx.x + 46 * gridDim.x] = partial_sum[46 * blockDim.x];
        v_r[blockIdx.x + 47 * gridDim.x] = partial_sum[47 * blockDim.x];
        v_r[blockIdx.x + 48 * gridDim.x] = partial_sum[48 * blockDim.x];
        v_r[blockIdx.x + 49 * gridDim.x] = partial_sum[49 * blockDim.x];
        v_r[blockIdx.x + 50 * gridDim.x] = partial_sum[50 * blockDim.x];
        v_r[blockIdx.x + 51 * gridDim.x] = partial_sum[51 * blockDim.x];
        v_r[blockIdx.x + 52 * gridDim.x] = partial_sum[52 * blockDim.x];
        v_r[blockIdx.x + 53 * gridDim.x] = partial_sum[53 * blockDim.x];
        v_r[blockIdx.x + 54 * gridDim.x] = partial_sum[54 * blockDim.x];
        v_r[blockIdx.x + 55 * gridDim.x] = partial_sum[55 * blockDim.x];
        v_r[blockIdx.x + 56 * gridDim.x] = partial_sum[56 * blockDim.x];
        v_r[blockIdx.x + 57 * gridDim.x] = partial_sum[57 * blockDim.x];
        v_r[blockIdx.x + 58 * gridDim.x] = partial_sum[58 * blockDim.x];
        v_r[blockIdx.x + 59 * gridDim.x] = partial_sum[59 * blockDim.x];
    }
    __syncthreads();
}
