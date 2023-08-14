#include <sys/time.h>
#define CHECK(call)                                                \
    {                                                              \
        const cudaError_t error = call;                            \
        if (error != cudaSuccess) {                                \
            fprintf(stderr, "Error: %s:%d, ", __FILE__, __LINE__); \
            fprintf(stderr, "code: %d, reason: %s\n", error,       \
                    cudaGetErrorString(error));                    \
        }                                                          \
    }

#include <cuda_runtime.h>
#include <stdio.h>

/*
 * kmeans example 3D
 */

void initialData(float *ip, int size) {
    int i;
    for (i = 0; i < size; i += 3) {
        ip[i] = i;
        ip[i + 1] = i;
        ip[i + 2] = i;
    }
    printf("maior valor %d/n", i);
    return;
}
