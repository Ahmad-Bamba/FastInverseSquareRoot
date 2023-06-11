// inverse_root_benchmark.cpp : Defines the entry point for the application.
//

#include "inverse_root.h"

#include <chrono>
#include <ranges>
#include <iostream>

int main() {
	using namespace RootBenchmark;

	static float constexpr number = 0.5f;
	static int constexpr ITERATIONS = 1'000'000;

	// warmup to clear cache
	for (int i : std::views::iota(1, ITERATIONS)) {
		cpp::isqrt(number);
		quake3::isqrt(number);
	}

	auto start = std::chrono::high_resolution_clock::now();
	for (int i : std::views::iota(1, ITERATIONS)) {
		cpp::isqrt(number);
	}
	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

	std::cout << "cpp implementation took: " << elapsed << "ms" << '\n';

	start = std::chrono::high_resolution_clock::now();
	for (int i : std::views::iota(1, ITERATIONS)) {
		quake3::isqrt(number);
	}
	end = std::chrono::high_resolution_clock::now();
	elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

	std::cout << "fast inverse square root took: " << elapsed << "ms" << '\n';

	std::cout << "Results: cpp " << cpp::isqrt(number) << '|' << "quake3 " << quake3::isqrt(number) << '\n';

	return 0;
}
