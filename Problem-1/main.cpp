#include <iostream>
#include <cmath>


int sum(int n) {
	if (n <= 0) {
		std::cout << "Number is invalid. (0 or Negative)." << std::endl;
		return 0;
	} else {
		return n * (n + 1) / 2;
	}
}

double distance(double x1, double y1, double x2, double y2) {
	return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
}

double totalDistance(double points[][2], int N) {
	double total = 0;
	for (int i = 0; i < N - 1; ++i) {
		total += distance(points[i][0], points[i][1], points[i + 1][0], points[i + 1][1]);
	}
	return total;
}

int main() {
	int N;
	std::cout << "Enter the number of points: ";
	std::cin >> N;
	double points[N][2];
	std::cout << "Enter the coordinates (x y) of each point:" << std::endl;
	for (int i = 0; i < N; ++i) {
		std::cout << "Point " << i + 1 << ": ";
		std::cin >> points[i][0] >> points[i][1];
	}
	double totalDist = totalDistance(points, N);
	std::cout << "Total distance traveled: " << totalDist << std::endl;
	
	int naturalSum = sum(N);
	std::cout << "Sum of the first " << N << " natural numbers: " << naturalSum << std::endl;
	return 0;
}
