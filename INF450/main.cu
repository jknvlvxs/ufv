// #@title Código da Main (parcialmente Genérico, 64 blocos...)
// %%writefile main.cu

int main(int argc, char **argv) {
    printf("%s Starting...\n", argv[0]);
    // set up device
    int dev = 0;
    cudaDeviceProp deviceProp;
    CHECK(cudaGetDeviceProperties(&deviceProp, dev));
    printf("Using Device %d: %s\n", dev, deviceProp.name);
    CHECK(cudaSetDevice(dev));

    // set up data size of vectors
    int Dim = 3;
    int k = 15;
    int nElem = (1 << POWER) * Dim;
    printf("Vector Size %d\n", nElem);

    // malloc host memory
    size_t nBytes = nElem * sizeof(float);
    size_t cBytes = Dim * k * sizeof(float);
    size_t tBytes = k * sizeof(int);
    size_t vBytes = GRID * (k * Dim + k) * sizeof(float); // 64 blks, 60 variables k=15, d=3

    float *h_data, *h_centroids;
    float *h_v_r;
    h_data = (float *)malloc(nBytes);
    h_v_r = (float *)malloc(vBytes);
    initialData(h_data, nElem);
    h_centroids = (float *)malloc(cBytes);
    h_centroids[0] = 100;
    h_centroids[1] = 100;
    h_centroids[2] = 100;
    h_centroids[3] = 200;
    h_centroids[4] = 200;
    h_centroids[5] = 200;
    h_centroids[6] = 300;
    h_centroids[7] = 300;
    h_centroids[8] = 300;
    h_centroids[9] = 400;
    h_centroids[10] = 400;
    h_centroids[11] = 400;
    h_centroids[12] = 100;
    h_centroids[13] = 100;
    h_centroids[14] = 100;
    h_centroids[15] = 200;
    h_centroids[16] = 200;
    h_centroids[17] = 200;
    h_centroids[18] = 300;
    h_centroids[19] = 300;
    h_centroids[20] = 300;
    h_centroids[21] = 400;
    h_centroids[22] = 400;
    h_centroids[23] = 400;
    h_centroids[24] = 500;
    h_centroids[25] = 500;
    h_centroids[26] = 500;
    h_centroids[27] = 100;
    h_centroids[28] = 100;
    h_centroids[29] = 100;
    h_centroids[30] = 200;
    h_centroids[31] = 200;
    h_centroids[32] = 200;
    h_centroids[33] = 300;
    h_centroids[34] = 300;
    h_centroids[35] = 300;
    h_centroids[36] = 400;
    h_centroids[37] = 400;
    h_centroids[38] = 400;
    h_centroids[39] = 500;
    h_centroids[40] = 500;
    h_centroids[41] = 500;
    h_centroids[42] = 600;
    h_centroids[43] = 600;
    h_centroids[44] = 600;

    float *h_counter;
    h_counter = (float *)malloc(tBytes);

    h_counter[0] = 0;
    h_counter[1] = 0;
    h_counter[2] = 0;
    h_counter[3] = 0;
    h_counter[4] = 0;
    h_counter[5] = 0;
    h_counter[6] = 0;
    h_counter[7] = 0;
    h_counter[8] = 0;
    h_counter[9] = 0;
    h_counter[10] = 0;
    h_counter[11] = 0;
    h_counter[12] = 0;
    h_counter[13] = 0;
    h_counter[14] = 0;

    // malloc device global memory
    float *d_data, *d_centroids;
    float *v_r;
    CHECK(cudaMalloc((float **)&v_r, vBytes));
    CHECK(cudaMalloc((float **)&d_data, nBytes));
    CHECK(cudaMalloc((float **)&d_centroids, cBytes));
    int *d_counter;
    CHECK(cudaMalloc((int **)&d_counter, tBytes));

    // transfer data from host to device
    CHECK(cudaMemcpy(d_data, h_data, nBytes, cudaMemcpyHostToDevice));
    CHECK(cudaMemcpy(d_centroids, h_centroids, cBytes, cudaMemcpyHostToDevice));
    CHECK(cudaMemcpy(d_counter, h_counter, tBytes, cudaMemcpyHostToDevice));

    // invoke kernel at host side
    int iLen = BLOCO;
    dim3 block(iLen);
    // dim3 grid  (((nElem/Dim + block.x - 1) / block.x));
    dim3 grid2(GRID);

    for (int i = 0; i < 8; i++) {
        kmeansReduce<<<grid2, block>>>(d_data, d_centroids, d_counter, nElem, v_r);
        kernel<<<1, GRID / 2>>>(v_r); // So foi testado com grid=64, 32 threads
        cudaDeviceSynchronize();
        CHECK(cudaMemcpy(h_v_r, v_r, vBytes, cudaMemcpyDeviceToHost));
        h_centroids[0] = h_v_r[0] / h_v_r[4 * GRID];
        h_centroids[1] = h_v_r[GRID] / h_v_r[4 * GRID];
        h_centroids[2] = h_v_r[GRID * 2] / h_v_r[4 * GRID];
        h_centroids[3] = h_v_r[GRID * 3] / h_v_r[5 * GRID];
        h_centroids[4] = h_v_r[GRID * 4] / h_v_r[5 * GRID];
        h_centroids[5] = h_v_r[GRID * 5] / h_v_r[5 * GRID];
        h_centroids[6] = h_v_r[GRID * 6] / h_v_r[6 * GRID];
        h_centroids[7] = h_v_r[GRID * 7] / h_v_r[6 * GRID];
        h_centroids[8] = h_v_r[GRID * 8] / h_v_r[6 * GRID];
        h_centroids[9] = h_v_r[GRID * 9] / h_v_r[7 * GRID];
        h_centroids[10] = h_v_r[GRID * 10] / h_v_r[7 * GRID];
        h_centroids[11] = h_v_r[GRID * 11] / h_v_r[7 * GRID];
        h_centroids[12] = h_v_r[GRID * 12] / h_v_r[8 * GRID];
        h_centroids[13] = h_v_r[GRID * 13] / h_v_r[8 * GRID];
        h_centroids[14] = h_v_r[GRID * 14] / h_v_r[8 * GRID];
        h_centroids[15] = h_v_r[GRID * 15] / h_v_r[9 * GRID];
        h_centroids[16] = h_v_r[GRID * 16] / h_v_r[9 * GRID];
        h_centroids[17] = h_v_r[GRID * 17] / h_v_r[9 * GRID];
        h_centroids[18] = h_v_r[GRID * 18] / h_v_r[10 * GRID];
        h_centroids[19] = h_v_r[GRID * 19] / h_v_r[10 * GRID];
        h_centroids[20] = h_v_r[GRID * 20] / h_v_r[10 * GRID];
        h_centroids[21] = h_v_r[GRID * 21] / h_v_r[11 * GRID];
        h_centroids[22] = h_v_r[GRID * 22] / h_v_r[11 * GRID];
        h_centroids[23] = h_v_r[GRID * 23] / h_v_r[11 * GRID];
        h_centroids[24] = h_v_r[GRID * 24] / h_v_r[12 * GRID];
        h_centroids[25] = h_v_r[GRID * 25] / h_v_r[12 * GRID];
        h_centroids[26] = h_v_r[GRID * 26] / h_v_r[12 * GRID];
        h_centroids[27] = h_v_r[GRID * 27] / h_v_r[13 * GRID];
        h_centroids[28] = h_v_r[GRID * 28] / h_v_r[13 * GRID];
        h_centroids[29] = h_v_r[GRID * 29] / h_v_r[13 * GRID];
        h_centroids[30] = h_v_r[GRID * 30] / h_v_r[14 * GRID];
        h_centroids[31] = h_v_r[GRID * 31] / h_v_r[14 * GRID];
        h_centroids[32] = h_v_r[GRID * 32] / h_v_r[14 * GRID];
        h_centroids[33] = h_v_r[GRID * 33] / h_v_r[15 * GRID];
        h_centroids[34] = h_v_r[GRID * 34] / h_v_r[15 * GRID];
        h_centroids[35] = h_v_r[GRID * 35] / h_v_r[15 * GRID];
        h_centroids[36] = h_v_r[GRID * 36] / h_v_r[16 * GRID];
        h_centroids[37] = h_v_r[GRID * 37] / h_v_r[16 * GRID];
        h_centroids[38] = h_v_r[GRID * 38] / h_v_r[16 * GRID];
        h_centroids[39] = h_v_r[GRID * 39] / h_v_r[17 * GRID];
        h_centroids[40] = h_v_r[GRID * 40] / h_v_r[17 * GRID];
        h_centroids[41] = h_v_r[GRID * 41] / h_v_r[17 * GRID];
        h_centroids[42] = h_v_r[GRID * 42] / h_v_r[18 * GRID];
        h_centroids[43] = h_v_r[GRID * 43] / h_v_r[18 * GRID];
        h_centroids[44] = h_v_r[GRID * 44] / h_v_r[18 * GRID];

        for (int j = 0; j < k * Dim; j += Dim) {
            printf(" centroids dim %d value %f  \n", j, h_centroids[j]);
        }
        CHECK(cudaDeviceSynchronize());
        // check kernel error
        CHECK(cudaGetLastError());
        memset(h_counter, 0, tBytes);
        CHECK(cudaMemcpy(d_centroids, h_centroids, cBytes, cudaMemcpyHostToDevice));
        CHECK(cudaMemcpy(d_counter, h_counter, tBytes, cudaMemcpyHostToDevice));
    }
    // check device results

    // free device global memory
    CHECK(cudaFree(d_data));
    CHECK(cudaFree(d_centroids));
    CHECK(cudaFree(v_r));
    CHECK(cudaFree(d_counter));

    // free host memory
    free(h_data);
    free(h_centroids);
    free(h_v_r);
    free(h_counter);

    return (0);
}