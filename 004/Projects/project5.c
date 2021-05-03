#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _image {
    int** pixels;
    int width;
    int height;
} Image;


Image* readImage(char* filename) {
    Image *userImage;
    userImage = (Image*)malloc(sizeof(Image));
    FILE *f1 = fopen(filename, "r");
    if (!f1) {
        return NULL;
    }
    char fileType[5];
    fscanf(f1, "%s", fileType);
    fscanf(f1, "%d", &userImage->width);
    fscanf(f1, "%d", &userImage->height);
    int maxVal;
    fscanf(f1, "%d", &maxVal);
    userImage->pixels = malloc(sizeof(int *) * userImage->height);
    for (int i = 0; i < userImage->height; i++) {
        userImage->pixels[i] = malloc(sizeof(int *) * userImage->width);
    }
    for (int i = 0; i < userImage->height; i++) {
        for (int j = 0; j < userImage->width; j++) {
            fscanf(f1, "%d", &userImage->pixels[i][j]);
        }
    }
    // for (int i = 0; i < userImage->height; i++) {
    //     for (int j = 0; j < userImage->width; j++) {
    //         printf("%d ", userImage->pixels[i][j]);
    //     }
    // }
    fclose(f1);
    return userImage;
}

Image* edgeDetect(Image* img, int threshold) {
    Image* edges;
    edges = (Image*)malloc(sizeof(Image));
    edges->height = img->height;
    edges->width = img->width;
    edges->pixels = malloc(sizeof(int *) * edges->height);
    for (int i = 0; i < edges->height; i++) {
        edges->pixels[i] = malloc(sizeof(int *) * edges->width);
    }
    for (int i = 0; i < edges->height; i++) {
        for (int j = 0; j < edges->width; j++) {
            edges->pixels[i][j] = 0;
        }
    }

    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            if ((i < (img->height - 1) && (j < (img->width - 1)))) {
                if ((abs(img->pixels[i][j] - img->pixels[i][j + 1]) > threshold) || (abs(img->pixels[i][j] - img->pixels[i + 1][j]) > threshold)) {
                    edges->pixels[i][j] = 255;
                }
            }
        }
    }
    return edges;
}

int saveImage(char* filename, Image* img) {
    FILE* f1 = fopen(filename, "w");
    if (!f1) {
        return 1;
    }
    fprintf(f1, "P2\n");
    fprintf(f1, "%d %d\n", img->width, img->height);
    fprintf(f1, "255\n");
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            fprintf(f1, "%d\n ", img->pixels[i][j]);
        }
    }
    fclose(f1);
    return 0;
}

void freeImage(Image* img) {
    for (int i = 0; i < img->height; i++) {
        free(img->pixels[i]);
    }
    free(img->pixels);
    free(img);
}

int main(int argc, char** argv) {
    if (argc != 4) {
        printf("Usage: ./a.out input.pgm output.pgm threshold\n");
        return 1;
    }
    int threshold = atoi(argv[3]);

    FILE *f1 = fopen(argv[1], "r");
    FILE *f2 = fopen(argv[2], "w");

    if (!f1) {
        printf("Unable to read image: %s\n", argv[1]);
        return 1;
    }
    if (!f2) {
        printf("Unable to write image: %s\n", argv[2]);
        return 1;
    }
    
    Image* img = readImage(argv[1]);
    Image* edge = edgeDetect(img, threshold);
    saveImage(argv[2], edge);
    free(img);
    free(edge);
    return 0;
}
