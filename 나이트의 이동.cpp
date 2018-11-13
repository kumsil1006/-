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
	//bool hasGoal = false; // ������ ���޿���
	int counter{ 0 };

	// ������
	queue<point> q;
	q.push(p1);
	visitedOrNot[p1.x][p1.y] = true; // �������� �̹� ���ٿ�

	while (!q.empty()) {
		int size1 = q.size();
		for (int i = 0; i < size1; i++) {
			point cur = q.front();
			q.pop();

			// �� ������ �����Ѵٸ� ��������
			if (cur.x == p2.x && cur.y == p2.y) {
				return counter;
			}
			for (int diff = 0; diff < 8; diff++) {
				// �̵� ����� ����ŭ �ݺ�
				int nextX = cur.x + move_x[diff];
				int nextY = cur.y + move_y[diff];

				// ������ �Ѿ�� �׳� skip
				if (nextX < 0 || nextX >= size || nextY < 0 || nextY >= size) {
					continue;
				}
				// �̹� �湮�߾ skip

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