#include <graphics.h>
#include <stdio.h>

#define INSIDE 0 // 0000
#define LEFT 1   // 0001
#define RIGHT 2  // 0010
#define BOTTOM 4 // 0100
#define TOP 8    // 1000

int xmin, ymin, xmax, ymax;

// Function to compute region code
int computeCode(int x, int y) {
    int code = INSIDE;

    if (x < xmin)       code |= LEFT;
    else if (x > xmax)  code |= RIGHT;
    if (y < ymin)       code |= BOTTOM;
    else if (y > ymax)  code |= TOP;

    return code;
}

// Cohen�Sutherland Line Clipping Algorithm
void cohenSutherlandClip(int x1, int y1, int x2, int y2) {
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
    int accept = 0;

    while (1) {
        if ((code1 == 0) && (code2 == 0)) {
            // Trivially accepted
            accept = 1;
            break;
        } else if (code1 & code2) {
            // Trivially rejected
            break;
        } else {
            int codeOut;
            int x, y;

            // Pick endpoint outside window
            codeOut = code1 ? code1 : code2;

            // Find intersection
            if (codeOut & TOP) {
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                y = ymax;
            } else if (codeOut & BOTTOM) {
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
                y = ymin;
            } else if (codeOut & RIGHT) {
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
                x = xmax;
            } else if (codeOut & LEFT) {
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
                x = xmin;
            }

            // Replace outside point
            if (codeOut == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }

    // Draw clipped line if accepted
    if (accept) {
        setcolor(GREEN);
        line(x1, y1, x2, y2);
    } else {
        setcolor(RED);
        outtextxy(10, 10, (char*)"Line Rejected");
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int x1, y1, x2, y2;

    printf("Enter the clipping window (xmin, ymin, xmax, ymax): ");
    scanf("%d %d %d %d", &xmin, &ymin, &xmax, &ymax);

    printf("Enter the line endpoints (x1, y1, x2, y2): ");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    // Draw clipping rectangle
    rectangle(xmin, ymin, xmax, ymax);

    // Draw original line
    setcolor(WHITE);
    line(x1, y1, x2, y2);

    // Perform clipping
    cohenSutherlandClip(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}
