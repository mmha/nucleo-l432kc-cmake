#pragma once
#include <chrono>

namespace sys
{
	class RTCClock
	{
		public:
		using rep = std::time_t;
		using period = std::ratio<1, 1>;
		using duration = std::chrono::duration<rep, period>;
		using time_point = std::chrono::time_point<RTCClock>;
		constexpr static bool is_steady = false;

		static void set(time_point t)
		{
			set_time(t.time_since_epoch().count());
		}

		static auto now() -> time_point
		{
			auto d = duration{time(nullptr)};
			return time_point{d};
		}
	};
}