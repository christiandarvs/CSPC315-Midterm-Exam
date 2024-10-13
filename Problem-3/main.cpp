#include <iostream>

void TOH(int n, char A, char B, char C, int& moves) {
	if (n > 0) {
		TOH(n - 1, A, C, B, moves);
		std::cout << "Move disk from " << A << " to " << C << std::endl;
		moves++;
		TOH(n - 1, B, A, C, moves);
	}
}

int main() {
	int moves = 0;
	TOH(3, 'A', 'B', 'C', moves);
	std::cout << "Total moves: " << moves << std::endl;
	return 0;
}
