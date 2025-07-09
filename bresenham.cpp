//#include <graphics.h>
//#include <stdio.h>
//#include <stdlib.h>  // for abs()
//
//void bresenham(int x1, int y1, int x2, int y2) {
//    int dx = abs(x2 - x1);
//    int dy = abs(y2 - y1);
//    int x = x1, y = y1;
//    int sx = (x2 > x1) ? 1 : -1;
//    int sy = (y2 > y1) ? 1 : -1;
//
//    int err = dx - dy;
//
//    while (1) {
//        putpixel(x, y, WHITE);
//        if (x == x2 && y == y2) break;
//        int e2 = 2 * err;
//        if (e2 > -dy) {
//            err -= dy;
//            x += sx;
//        }
//        if (e2 < dx) {
//            err += dx;
//            y += sy;
//        }
//    }
//}
//
//int main() {
//    int gd = DETECT, gm;
//    initgraph(&gd, &gm, (char*)"");
//
//    int x1, y1, x2, y2;
//
//    printf("Enter x1 y1: ");
//    scanf("%d %d", &x1, &y1);
//    printf("Enter x2 y2: ");
//    scanf("%d %d", &x2, &y2);
//
//    bresenham(x1, y1, x2, y2);
//
//    getch();
//    closegraph();
//    return 0;
//}
