#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

// 두 점 사이의 거리를 구하는 함수
int get_dist(int x1, int y1, int x2, int y2){
    return abs(x1-x2) + abs(y1-y2);
}

int main() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    // 모든 지점을 다 거칠 때 전체 거리
    int total_dist = 0;
    for(int i=0; i<n-1; i++){
        total_dist += get_dist(x[i], y[i], x[i+1], y[i+1]);
    }

    // 중간 지점 하나를 건너뛰었을 때 줄어드는 거리의 최댓값
    int max_dist = 0;

    //1부터 n-2까지 건너뛰기 시도
    for(int i=1; i<n-1; i++){
        // 원래 가야 했던 거리: (i-1 -> i) + (i -> i+1)
        int original = get_dist(x[i-1],y[i-1],x[i],y[i]) + 
                        get_dist(x[i],y[i],x[i+1],y[i+1]);
        
        // 건너뛰고 가는 거리 : (i-1 -> i+1)
        int short_dist = get_dist(x[i-1],y[i-1],x[i+1],y[i+1]);

        int benefit = original - short_dist;

        max_dist = max(max_dist, benefit);
    }

    cout<< total_dist - max_dist << "\n";

    return 0;
}