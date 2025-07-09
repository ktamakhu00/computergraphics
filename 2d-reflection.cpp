#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>

void drawPolygon(int x[], int y[], int n, int color) {
    setcolor(color);
    for (int i = 0; i < n; i++) {
        line(x[i], y[i], x[(i + 1) % n], y[(i + 1) % n]);  // Connect last to first
    }
}

void reflectX(int x[], int y[], int n, int xc, int yc) {
    for (int i = 0; i < n; i++) {
        y[i] = 2 * yc - y[i];
    }
}

void reflectY(int x[], int y[], int n, int xc, int yc) {
    for (int i = 0; i < n; i++) {
        x[i] = 2 * xc - x[i];
    }
}

void reflectOrigin(int x[], int y[], int n, int xc, int yc) {
    for (int i = 0; i < n; i++) {
        x[i] = 2 * xc - x[i];
        y[i] = 2 * yc - y[i];
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int xc = getmaxx() / 2;
    int yc = getmaxy() / 2;

    // Draw x and y axes
    line(0, yc, getmaxx(), yc);
    line(xc, 0, xc, getmaxy());

    int n;
    printf("Enter number of sides (vertices) of polygon: ");
    scanf("%d", &n);

    int *x = (int *)malloc(n * sizeof(int));
    int *y = (int *)malloc(n * sizeof(int));

    printf("Enter coordinates (x y) of each vertex:\n");
    for (int i = 0; i < n; i++) {
        printf("Vertex %d: ", i + 1);
        scanf("%d %d", &x[i], &y[i]);
        x[i] += xc;        // Translate to screen center
        y[i] = yc - y[i];  // Invert y-axis
    }

    drawPolygon(x, y, n, WHITE);  // Original polygon

    int choice;
    printf("\nChoose reflection type:\n");
    printf("1. Reflect about X-axis\n");
    printf("2. Reflect about Y-axis\n");
    printf("3. Reflect about Origin\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            reflectX(x, y, n, xc, yc);
            break;
        case 2:
            reflectY(x, y, n, xc, yc);
            break;
        case 3:
             reflectOrigin(x, y, n, xc, yc);
            break;
        default:
            printf("Invalid choice!\n");
            closegraph();
            return 0;
    }

    drawPolygon(x, y, n, YELLOW);  // Reflected polygon

    getch();
    closegraph();
    free(x);
    free(y);
    return 0;
}

