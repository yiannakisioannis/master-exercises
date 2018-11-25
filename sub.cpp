#include <climits> // INT_MIN

#include <iostream>

#include <random>

#include <chrono> 



#define N 1000



using namespace std;

using namespace std::chrono;



// O(n^3) (naive implementation)

int max_sub1(int a[], int n) {

  int max = INT_MIN;

  for (int i = 0; i < n; i++) {

    for (int j = i; j < n; j++) {

      int sum = 0;

      for (int k = i; k <= j; k++) {

        sum += a[k];

      }

      if (sum > max) {

        max = sum;

      }

    }

  }

  return max;

}



int main() {

  random_device device;

  mt19937 generator(device());

  //   mt19937 generator(42); // for reproducible results

  uniform_int_distribution<int> distribution(-10000, 10000);

  int a[N];

  for (int i = 0; i < N; i++) {

    a[i] = distribution(generator);

  }

  cout << "max subarray of " << N << " values" << endl;

  auto t1 = high_resolution_clock::now(); 

  cout << "O(n^3):   " << max_sub1(a, N) << endl;

  auto t2 = high_resolution_clock::now();

  auto duration = duration_cast<microseconds>(t2-t1).count();

  cout << "Time elapsed: " << duration << " microseconds " << duration/1000000.0 << " seconds" << endl;

}