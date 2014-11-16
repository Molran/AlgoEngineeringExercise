// stdafx.h : Visual Studio doesn't compile data again and again, which is included here
#pragma once

#include <stdio.h>
#ifdef __linux__
#else
#include <tchar.h>
#endif

#include <iostream>
#include <vector>	

#ifdef __linux__
#include "gtest/gtest.h"
#else
#include "gtest\gtest.h"
#endif


#include <cmath>	
#include <iostream>	
#include <fstream>
#include <array>
#include "Matrix.h"

