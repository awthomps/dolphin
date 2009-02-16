// Copyright (C) 2003-2008 Dolphin Project.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, version 2.0.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License 2.0 for more details.

// A copy of the GPL 2.0 should have been included with the program.
// If not, see http://www.gnu.org/licenses/

// Official SVN repository and contact information can be found at
// http://code.google.com/p/dolphin-emu/

#ifndef _TIMER_H
#define _TIMER_H

#include "Common.h"
#include <string>

namespace Common
{
class Timer
{
	public:

		Timer();

		void Start();
		void Stop();
		void Update();

		// The time difference is always returned in milliseconds, regardless of alternative internal representation
		s64 GetTimeDifference(void);
		void AddTimeDifference();

		static void IncreaseResolution();
		static void RestoreResolution();
		static u64 GetTimeSinceJan1970();
		static u64 GetLocalTimeSinceJan1970();

		static std::string GetTimeFormatted();
		std::string GetTimeElapsedFormatted();
		u64 Timer::GetTimeElapsed();

	public:

		u64 m_LastTime;
		u64 m_StartTime;
		u64 m_frequency;
		bool m_Running;
};
} // end of namespace Common

#ifdef __GNUC__
u32 timeGetTime();
#endif
#endif
