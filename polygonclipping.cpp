#include <graphics.h>
#include <stdio.h>

#define MAX 20

int xmin, ymin, xmax, ymax;

void clipLeft(int poly[][2], int *n, int newPoly[][2], int *newN) {
    *newN = 0;
    for (int i = 0; i < *n; i++) {
        int x1 = poly[i][0], y1 = poly[i][1];
        int x2 = poly[(i + 1) % *n][0], y2 = poly[(i + 1) % *n][1];

        if (x1 >= xmin && x2 >= xmin) {
            newPoly[*newN][0] = x2;
            newPoly[*newN][1] = y2;
            (*newN)++;
        } else if (x1 >= xmin && x2 < xmin) {
            int y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
            newPoly[*newN][0] = xmin;
            newPoly[*newN][1] = y;
            (*newN)++;
        } else if (x1 < xmin && x2 >= xmin) {
            int y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
            newPoly[*newN][0] = xmin;
            newPoly[*newN][1] = y;
            (*newN)++;
            newPoly[*newN][0] = x2;
            newPoly[*newN][1] = y2;
            (*newN)++;
        }
    }
}

void clipRight(int poly[][2], int *n, int newPoly[][2], int *newN) {
    *newN = 0;
    for (int i = 0; i < *n; i++) {
        int x1 = poly[i][0], y1 = poly[i][1];
        int x2 = poly[(i + 1) % *n][0], y2 = poly[(i + 1) % *n][1];

        if (x1 <= xmax && x2 <= xmax) {
            newPoly[*newN][0] = x2;
            newPoly[*newN][1] = y2;
            (*newN)++;
        } else if (x1 <= xmax && x2 > xmax) {
            int y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
            newPoly[*newN][0] = xmax;
            newPoly[*newN][1] = y;
            (*newN)++;
        } else if (x1 > xmax && x2 <= xmax) {
            int y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
            newPoly[*newN][0] = xmax;
            newPoly[*newN][1] = y;
            (*newN)++;
            newPoly[*newN][0] = x2;
            newPoly[*newN][1] = y2;
            (*newN)++;
        }
    }
}

void clipBottom(int poly[][2], int *n, int newPoly[][2], int *newN) {
    *newN = 0;
    for (int i = 0; i < *n; i++) {
        int x1 = poly[i][0], y1 = poly[i][1];
        int x2 = poly[(i + 1) % *n][0], y2 = poly[(i + 1) % *n][1];

        if (y1 >= ymin && y2 >= ymin) {
            newPoly[*newN][0] = x2;
            newPoly[*newN][1] = y2;
            (*newN)++;
        } else if (y1 >= ymin && y2 < ymin) {
            int x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
            newPoly[*newN][0] = x;
            newPoly[*newN][1] = ymin;
            (*newN)++;
        } else if (y1 < ymin && y2 >= ymin) {
            int x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
            newPoly[*newN][0] = x;
            newPoly[*newN][1] = ymin;
            (*newN)++;
            newPoly[*newN][0] = x2;
            newPoly[*newN][1] = y2;
            (*newN)++;
        }
    }
}

void clipTop(int poly[][2], int *n, int newPoly[][2], int *newN) {
    *newN = 0;
    for (int i = 0; i < *n; i++) {
        int x1 = poly[i][0], y1 = poly[i][1];
        int x2 = poly[(i + 1) % *n][0], y2 = poly[(i + 1) % *n][1];

        if (y1 <= ymax && y2 <= ymax) {
            newPoly[*newN][0] = x2;
            newPoly[*newN][1] = y2;
            (*newN)++;
        } else if (y1 <= ymax && y2 > ymax) {
            int x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
            newPoly[*newN][0] = x;
            newPoly[*newN][1] = ymax;
            (*newN)++;
        } else if (y1 > ymax && y2 <= ymax) {
            int x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
            newPoly[*newN][0] = x;
            newPoly[*newN][1] = ymax;
            (*newN)++;
            newPoly[*newN][0] = x2;
            newPoly[*newN][1] = y2;
            (*newN)++;
        }
    }
}

void drawPolygon(int poly[][2], int n, int color) {
    setcolor(color);
    for (int i = 0; i < n; i++) {
        line(poly[i][0], poly[i][1], poly[(i + 1) % n][0], poly[(i + 1) % n][1]);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int n, poly[MAX][2], newPoly1[MAX][2], newPoly2[MAX][2];
    int newN;

    printf("Enter the number of vertices of the polygon: ");
    scanf("%d", &n);

    printf("Enter the coordinates (x y) of the polygon:\n");
    for (int i = 0; i < n; i++) {
        printf("Vertex %d: ", i + 1);
        scanf("%d %d", &poly[i][0], &poly[i][1]);
    }

    printf("Enter clipping window (xmin ymin xmax ymax): ");
    scanf("%d %d %d %d", &xmin, &ymin, &xmax, &ymax);

    // Draw original polygon
    drawPolygon(poly, n, WHITE);

    // Draw clipping rectangle
    rectangle(xmin, ymin, xmax, ymax);

    // Apply clipping
    clipLeft(poly, &n, newPoly1, &newN);
    clipRight(newPoly1, &newN, newPoly2, &n);
    clipBottom(newPoly2, &n, newPoly1, &newN);
    clipTop(newPoly1, &newN, newPoly2, &n);

    // Draw final clipped polygon
    drawPolygon(newPoly2, n, GREEN);

    getch();
    closegraph();
    return 0;
}
