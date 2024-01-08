
#include <oneapi/tbb.h>
#include <oneapi/tbb/partitioner.h>

#include <cassert>
#include <chrono>
#include <iostream>
#include <numeric>
#include <vector>

template <typename T>
void serial_add(const std::vector<T>& a, const std::vector<T>& b, std::vector<T>& c) {
  for (size_t i = 0; i < a.size(); ++i) {
    c[i] = a[i] + b[i];
  }
}

template <typename T>
void parallel_add(const std::vector<T>& a, const std::vector<T>& b, std::vector<T>& c, size_t grainsize = 1) {
  oneapi::tbb::parallel_for(
      oneapi::tbb::blocked_range<size_t>(0, a.size(), grainsize),
      [&](const oneapi::tbb::blocked_range<size_t> r) {
        for (int i = r.begin(); i < r.end(); ++i) {
          c[i] = a[i] + b[i];
        }
      },
      oneapi::tbb::simple_partitioner());
}

int main(int argc, char* argv[]) {
  const size_t N{100000};
  std::vector<int> a(N), b(N), c(N);
  std::iota(a.begin(), a.end(), 0);
  std::iota(b.begin(), b.end(), 0);

  if (argc == 1) {
    auto start_serial = std::chrono::high_resolution_clock::now();
    serial_add(a, b, c);
    auto end_serial = std::chrono::high_resolution_clock::now();
    std::cout << "Serial time: "
              << std::chrono::duration_cast<std::chrono::microseconds>(end_serial - start_serial).count() << " us\n";

    auto start_parallel = std::chrono::high_resolution_clock::now();
    parallel_add(a, b, c, 1);
    auto end_parallel = std::chrono::high_resolution_clock::now();
    std::cout << "Parallel time: "
              << std::chrono::duration_cast<std::chrono::microseconds>(end_parallel - start_parallel).count()
              << " us\n";

    start_parallel = std::chrono::high_resolution_clock::now();
    parallel_add(a, b, c, N);
    end_parallel = std::chrono::high_resolution_clock::now();
    std::cout << "Parallel time: "
              << std::chrono::duration_cast<std::chrono::microseconds>(end_parallel - start_parallel).count()
              << " us\n";

    start_parallel = std::chrono::high_resolution_clock::now();
    parallel_add(a, b, c, N / 2);
    end_parallel = std::chrono::high_resolution_clock::now();
    std::cout << "Parallel time: "
              << std::chrono::duration_cast<std::chrono::microseconds>(end_parallel - start_parallel).count()
              << " us\n";

    start_parallel = std::chrono::high_resolution_clock::now();
    parallel_add(a, b, c, N / 10);
    end_parallel = std::chrono::high_resolution_clock::now();
    std::cout << "Parallel time: "
              << std::chrono::duration_cast<std::chrono::microseconds>(end_parallel - start_parallel).count()
              << " us\n";

    start_parallel = std::chrono::high_resolution_clock::now();
    parallel_add(a, b, c, 2000);
    end_parallel = std::chrono::high_resolution_clock::now();
    std::cout << "Parallel time: "
              << std::chrono::duration_cast<std::chrono::microseconds>(end_parallel - start_parallel).count()
              << " us\n";

    for (size_t i = 0; i < N; ++i) {
      assert(c[i] == a[i] + b[i]);
    }
  } else {
    const size_t reps{100};
    double average{0};
    for (size_t i{}; i < reps; ++i) {
      auto start = std::chrono::high_resolution_clock::now();
      parallel_add(a, b, c, std::atoi(argv[1]));
      auto finish = std::chrono::high_resolution_clock::now();
      average += std::chrono::duration_cast<std::chrono::microseconds>(finish - start).count();
    }
    std::cout << average / reps << '\n';
  }
}
