//#include <graphics.h>
//#include <stdio.h>
//#include <math.h>
//
//#define ROUND(a) ((int)(a + 0.5))
//
//void lineDDA(int x1, int y1, int x2, int y2) {
//    int dx = x2 - x1;
//    int dy = y2 - y1;
//    int steps;
//    float xInc, yInc, x = x1, y = y1;
//
//    steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
//    xInc = dx / (float)steps;
//    yInc = dy / (float)steps;
//
//    for (int i = 0; i <= steps; i++) {
//        putpixel(ROUND(x), ROUND(y), WHITE);
//        x += xInc;
//        y += yInc;
//    }
//}
//
//int main() {
//    int gd = DETECT, gm;
//    initgraph(&gd, &gm, (char*)"");
//
//    int x1, y1, x2, y2;
//
//    // ?? Take input from user
//    printf("Enter x1 y1: ");
//    scanf("%d %d", &x1, &y1);
//
//    printf("Enter x2 y2: ");
//    scanf("%d %d", &x2, &y2);
//
//    // ?? Call DDA line drawing
//    lineDDA(x1, y1, x2, y2);
//
//    getch();
//    closegraph();
//    return 0;
//}
