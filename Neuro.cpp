// Neuro.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>
using namespace std;
float activate(float a) {
	if (a <= 0) {
		return 0;
	}
	else {
		return 1;
	}
}
void test(float rl[3][3], float weights[3]) {
	float sum[3] = {0,0,0};
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			sum[i] += activate(rl[i][j] * weights[j]);
		}
	}
	for (int i = 0; i < size(sum); i++) {
		cout << "Output " << i + 1 << ". " << sum[i] << endl;
	}
}
void train(float data[4][4], float sum[4], float weights[3]) {
	const float LR = 0.1, EPOCH = 50; // epoch = кол-во повторений
	float error;
	float rl[3][3] = {
		{1,1,1},
		{1,1,0},
		{0,1,0}
	};
	for (int i = 0; i < 3; i++) {
		cout << "Not trained weights: " << weights[i] << " " << endl;
	}
	cout << "--------------------" << endl;
	for (int n = 0; n < EPOCH; n++) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 3; j++) {
				error = data[i][3] - activate(sum[i]);
				weights[j] += LR * error * data[i][j];
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		if (weights[i] < 0) {
			weights[i] = 0;
		}
		else {
			weights[i] = 1;
		}
		cout << "Trained weights: " << weights[i] << " " << endl;
	}
	cout << "--------------------" << endl;
	test(rl,weights);
}
void init(float weights[3], float inputs[4][4], float sum[4]) {
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			sum[i] += weights[j] * inputs[i][j];
		}
	}
	train(inputs,sum,weights);
}
int main()
{
	float weights[3] = { -0.3, 0.2, 0.3 };
	float inputs[4][4] = { // last num = right answer
		{1,0,0,1},
		{0,1,1,0},
		{0,0,1,0},
		{0,0,0,0}
	};
	float sum[4] = {0,0,0,0};
	init(weights,inputs, sum);
}

// sigmoid = f(x) = x / (1 + abs(x))
//weights[num строки][num столбца]
	//	1 0 0		1 
	//	0 1 1		0
	//	1 0 1		1
	//	0 0 1		0

