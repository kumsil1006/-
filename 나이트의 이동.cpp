#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
struct point {
	int x{ 0 }, y{ 0 };
};
bool visitedOrNot[300][300];

int move(point p1, point p2, int size) {
	const int move_x[8] = { -2, 2, -1, 1, -2, 2, -1, 1 };
	const int move_y[8] = { -1, 1, -2, 2, 1, -1, 2, -2 };
	//bool hasGoal = false; // 목적지 도달여부
	int counter{ 0 };

	// 시작점
	queue<point> q;
	q.push(p1);
	visitedOrNot[p1.x][p1.y] = true; // 시작점은 이미 갔다옴

	while (!q.empty()) {
		int size1 = q.size();
		for (int i = 0; i < size1; i++) {
			point cur = q.front();
			q.pop();

			// 끝 지점에 도달한다면 빠져나감
			if (cur.x == p2.x && cur.y == p2.y) {
				return counter;
			}
			for (int diff = 0; diff < 8; diff++) {
				// 이동 경우의 수만큼 반복
				int nextX = cur.x + move_x[diff];
				int nextY = cur.y + move_y[diff];

				// 사이즈 넘어가면 그냥 skip
				if (nextX < 0 || nextX >= size || nextY < 0 || nextY >= size) {
					continue;
				}
				// 이미 방문했어도 skip

				if (visitedOrNot[nextX][nextY] != true) {

					point temp = { nextX, nextY };
					q.push(temp);
					visitedOrNot[nextX][nextY] = true;
				}
			}
		}
		counter++;
	}
	//if (hasGoal == true) break;
	return counter;
}

	


int main()
{
	int t{ 0 };
	cin >> t;
	
	point current;
	point dest;

	

	for (int i = 0; i < t;i++) {
		int l{ 0 };
	
		cin >> l >> current.x >> current.y >> dest.x >> dest.y;
		
		cout << move(current, dest, l) << endl;
		
	}
	
}