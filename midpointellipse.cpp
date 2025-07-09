#include <graphics.h>
#include <stdio.h>

void drawEllipse(int xc, int yc, int rx, int ry) {
    int x = 0;
    int y = ry;

    // Initial decision parameter of region 1
    double p1 = ry*ry - (rx*rx)*ry + 0.25*(rx*rx);
    int dx = 2 * ry * ry * x;
    int dy = 2 * rx * rx * y;

    // Region 1
    while (dx < dy) {
        // Plot points in all four quadrants
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        x++;
        dx += 2 * ry * ry;

        if (p1 < 0) {
            p1 += ry * ry + dx;
        } else {
            y--;
            dy -= 2 * rx * rx;
            p1 += ry * ry + dx - dy;
        }
    }

    // Initial decision parameter of region 2
    double p2 = ry*ry*(x + 0.5)*(x + 0.5) + rx*rx*(y - 1)*(y - 1) - rx*rx*ry*ry;

    // Region 2
    while (y >= 0) {
        // Plot points in all four quadrants
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        y--;
        dy -= 2 * rx * rx;

        if (p2 > 0) {
            p2 += rx * rx - dy;
        } else {
            x++;
            dx += 2 * ry * ry;
            p2 += rx * rx - dy + dx;
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int xc, yc, rx, ry;

    printf("Enter center of ellipse (xc, yc): ");
    scanf("%d %d", &xc, &yc);
    printf("Enter radius along x-axis (rx): ");
    scanf("%d", &rx);
    printf("Enter radius along y-axis (ry): ");
    scanf("%d", &ry);
xs
    drawEllipse(xc, yc, rx, ry);

    getch();
    closegraph();
    return 0;
}
