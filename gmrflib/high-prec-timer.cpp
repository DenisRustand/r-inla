
/* high-prec-timer.cpp
 *
 * Copyright (C) 2023-2023 Havard Rue
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * The author's contact information:
 *
 *        Haavard Rue
 *        CEMSE Division
 *        King Abdullah University of Science and Technology
 *        Thuwal 23955-6900, Saudi Arabia
 *        Email: haavard.rue@kaust.edu.sa
 *        Office: +966 (0)12 808 0640
 *
 */

#if defined(WINDOWS)

#include <bits/stdc++.h>
#include <chrono>
using namespace std;
 
extern "C" double GMRFLib_cpu_default(void);

double GMRFLib_cpu_default()
{
	static auto start = chrono::high_resolution_clock::now();
	static int first = 1;
	if (first) {
		start = chrono::high_resolution_clock::now();
		first = 0;
	}

	auto now = chrono::high_resolution_clock::now();
	double time_taken = (chrono::duration_cast<chrono::nanoseconds>(now - start).count()) * 1.0e-9;
	return time_taken;
}

#endif