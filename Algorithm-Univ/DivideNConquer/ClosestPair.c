#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

# define N 10

typedef struct {
    int x, y;
}Point;

void print(Point p[]) {
    for(int i = 0; i < N; i++) 
        printf("[%d %d] ", p[i].x, p[i].y);
    printf("\n");
}

double dist(Point p1, Point p2) {
    return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
}

void closetPairIter(Point p[]) {
    double dMin = 100000000.0, d;
    int iMin, jMin;
    for(int i = 0; i < N - 1; i++) {
        for(int j = i + 1; j < N ; j++) {
            d = dist(p[i], p[j]);
            if(d < dMin) {
                dMin = d;
                iMin = i;
                jMin = j;
            }
        }
    }
    printf("[%d %d] [%d %d] %.2f\n", p[iMin].x, p[iMin].y, p[jMin].x, p[jMin].y, dMin);
}

void insertionSortX(Point p[]) {
    int i, j, key;
    for(i = 1; i < N; i++) {
        Point t = p[i];
        key = p[i].x;
        for(j = i-1; j >= 0 && p[j].x > key; j--)
            p[j+1] = p[j];
        p[j+1] = t;
    }
}

void insertionSortY(Point p[]) {
    int i, j, key;
    for(i = 1; i < N; i++) {
        Point t = p[i];
        key = p[i].y;
        for(j = i-1; j >= 0 && p[j].y > key; j--)
            p[j+1] = p[j];
        p[j+1] = t;
    }
}

double DMZCheck(Point p[], int left, int right, double d) {
    insertionSortY(p);
    for(int i = left; i <= right; ++i) {
        for(int j = i+1; j <= right; ++j) {
            if(p[j].y - p[i].y > d)
                break;
            double tmp = dist(p[i], p[j]);
            d = d < tmp ? d : tmp;
        }
    }
    return d;
}

double closetPairRecur(Point p[], int left, int right) {
    int size = right - left + 1;
    double min;
    
    if(size == 2)
        return dist(p[left], p[right]);  // 거리 계산 1회 
    else if(size == 3) {  // 거리 계산 3회
        double a = dist(p[left], p[left + 1]);
        double b = dist(p[left + 1], p[left + 2]);
        double c = dist(p[left + 2], p[left]);
        
        if(a < b) {
            if(a < c)
                return a;
            return c;
        } 
        else {
            if(b < c)
                return b;
            return c;
        }
    }
    else {
        int mid = (left + right) / 2;
        double a = closetPairRecur(p, left, mid);
        double b = closetPairRecur(p, mid+1, right);
        min = (a < b) ? a : b;
        return DMZCheck(p, left, right, min);
    }
}

int main()
{
    Point p[N];
    srand(time(NULL));
    for(int i = 0; i < N; i++) {
        p[i].x = rand() % 100;
        p[i].y = rand() % 50;
    }
    
    insertionSortX(p);
    print(p);
    
    closetPairIter(p);
    
    printf("%.2f\n", closetPairRecur(p, 0, N-1));

    return 0;
}
