#include <stdio.h>

// Function to translate a 3D object
void translate3D(int x[], int y[], int z[], int n, int tx, int ty, int tz) {
    for (int i = 0; i < n; i++) {
        x[i] += tx;
        y[i] += ty;
        z[i] += tz;
    }
}

int main() {
    int n;

    printf("Enter number of vertices of the 3D object: ");
    scanf("%d", &n);

    int x[n], y[n], z[n];

    printf("Enter coordinates (x y z) of each vertex:\n");
    for (int i = 0; i < n; i++) {
        printf("Vertex %d: ", i + 1);
        scanf("%d %d %d", &x[i], &y[i], &z[i]);
    }

    int tx, ty, tz;
    printf("\nEnter translation factors (tx ty tz): ");
    scanf("%d %d %d", &tx, &ty, &tz);

    printf("\nBefore Translation:\n");
    for (int i = 0; i < n; i++) {
        printf("Vertex %d: (%d, %d, %d)\n", i + 1, x[i], y[i], z[i]);
    }

    translate3D(x, y, z, n, tx, ty, tz);

    printf("\nAfter Translation:\n");
    for (int i = 0; i < n; i++) {
        printf("Vertex %d: (%d, %d, %d)\n", i + 1, x[i], y[i], z[i]);
    }

    return 0;
}
