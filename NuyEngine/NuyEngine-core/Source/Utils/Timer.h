#pragma once

#include <Windows.h>

namespace nuy {

	class Timer
	{
	private:
		LARGE_INTEGER Start;
		double Frequency;

	public:
		Timer()
		{
			LARGE_INTEGER frequency;
			QueryPerformanceFrequency(&frequency);
			Frequency = 1.0 / frequency.QuadPart;
			QueryPerformanceCounter(&Start);
		}

		void Reset()
		{
			QueryPerformanceCounter(&Start);
		}

		float Elapsed()
		{
			LARGE_INTEGER current;
			QueryPerformanceCounter(&current);
			unsigned __int64 cycles = current.QuadPart - Start.QuadPart;
			
			return (float)(cycles * Frequency);
		}
	};

}
