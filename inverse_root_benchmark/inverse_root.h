#pragma once

#include <functional>
#include <cmath>
#include <cstdint>

namespace RootBenchmark {
	class InverseSquareRoot {
		std::function<float(float)> impl;

	public:
		InverseSquareRoot(std::function<float(float)> f) : impl { std::move(f) } { }

		float operator()(float x) const {
			return impl(x);
		}
	};

	namespace cpp {
		static InverseSquareRoot const isqrt{ [](float x) { return 1.f / std::sqrt(x); } };
	}

	namespace quake3 {
		inline float newtonRaphsonIteration(float x, float y) {
			const float threehalfs = 1.5f;

			// Perform one iteration of Newton-Raphson refinement
			y = y * (threehalfs - (x * 0.5f * y * y));

			return y;
		}

		static InverseSquareRoot const isqrt{ [](float x) { 
				std::uint32_t i = std::bit_cast<std::uint32_t>(x);

				// Initial guess using magic constant
				i = 0x5f3759df - (i >> 1);

				float y = std::bit_cast<float>(i);

				// Perform the desired number of iterations
				y = newtonRaphsonIteration(x, y);

				return y;
		} };
	}
}
