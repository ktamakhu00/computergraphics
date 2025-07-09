//#include <graphics.h>
//#include <stdio.h>
//
//void drawCircle(int xc, int yc, int r) {
//    int x = 0;
//    int y = r;
//    int p = 1 - r;
//
//    while (x <= y) {
//        // Drawing all 8 octants
//        putpixel(xc + x, yc + y, WHITE);
//        putpixel(xc - x, yc + y, WHITE);
//        putpixel(xc + x, yc - y, WHITE);
//        putpixel(xc - x, yc - y, WHITE);
//        putpixel(xc + y, yc + x, WHITE);
//        putpixel(xc - y, yc + x, WHITE);
//        putpixel(xc + y, yc - x, WHITE);
//        putpixel(xc - y, yc - x, WHITE);
//
//        x++;
//        if (p < 0)
//            p += 2 * x + 1;
//        else {
//            y--;
//            p += 2 * (x - y) + 1;
//        }
//    }
//}
//
//int main() {
//    int gd = DETECT, gm;
//    initgraph(&gd, &gm, (char*)"");
//
//    int xc, yc, r;
//
//    printf("Enter center of circle (xc, yc): ");
//    scanf("%d %d", &xc, &yc);
//    printf("Enter radius of circle: ");
//    scanf("%d", &r);
//
//    drawCircle(xc, yc, r);
//
//    getch();
//    closegraph();
//    return 0;
//}
