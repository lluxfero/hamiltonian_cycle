#include <iostream>
#include <Windows.h>
#include <clocale>
#include <vector>
using namespace std;

vector<int> result;
vector<bool> help_v;
const int n = 8;
int success = 0;

void hamiltonian_cycle(int m[n][n], int v) {
	result.push_back(v);
	help_v[v] = 1;

	if (result.size() == n) {
		if (m[result[0]][result.back()] == 1) { //есть ли путь от последней вершины в начальной	
			result.push_back(result[0]);
			success = 1;
		}
		else {
			help_v[v] = 0;
			result.pop_back();
		}
		return;
	}
	for (int j = 0; j < n; j++) {
		if (m[v][j] == 1 && help_v[j] == 0) {
			hamiltonian_cycle(m, j);
		}
	}
	if (success == 1) {
		return;
	}
	help_v[v] = 0;
	result.pop_back();
}

int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	/*int adj_matrix[n][n] = {
		{0, 1, 0, 1, 1, 0, 0, 1},
		{1, 0, 1, 0, 0, 0, 0, 0},
		{0, 1, 0, 1, 0, 0, 0, 0},
		{1, 0, 1, 0, 1, 0, 0, 1},
		{1, 0, 0, 1, 0, 1, 0, 1},
		{0, 0, 0, 0, 1, 0, 1, 0},
		{0, 0, 0, 0, 0, 1, 0, 1},
		{1, 0, 0, 1, 1, 0, 1, 0} };*/

	int adj_matrix[n][n] = {
		{0, 0, 1, 1, 1, 1, 0, 0},
		{0, 0, 1, 0, 0, 0, 0, 1},
		{1, 1, 0, 0, 1, 1, 1, 0},
		{1, 0, 0, 0, 0, 0, 1, 0},
		{1, 0, 1, 0, 0, 1, 0, 1},
		{1, 0, 1, 0, 1, 0, 1, 0},
		{0, 0, 1, 1, 0, 1, 0, 0},
		{0, 0, 0, 0, 1, 0, 0, 0} };

	for (int i = 0; i < n; i++) {
		help_v.push_back(0);
	}

	hamiltonian_cycle(adj_matrix, 0);

	cout << "Гамильтонов цикл: " << endl;
	for (size_t i = 0; i < result.size(); i++) {
		if (i != result.size() - 1) cout << result[i] + 1 << " -> ";
		else cout << result[i] + 1;
	}
}