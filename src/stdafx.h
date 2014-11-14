// stdafx.h : Includedatei f�r Standardsystem-Includedateien
// oder h�ufig verwendete projektspezifische Includedateien,
// die nur in unregelm��igen Abst�nden ge�ndert werden.
//

#pragma once

#include <stdio.h>
#ifdef __linux__
#else
#include <tchar.h>
#endif

#include <iostream>
#include <vector>	//for fib4

#ifdef __linux__
#include "gtest/gtest.h"
#else
#include "gtest\gtest.h"
#endif


#include <cmath>	//for fib5
#include <iostream>	//for fibToText
#include <fstream>
#include <array>
#include "Matrix.h"


// TODO: Hier auf zus�tzliche Header, die das Programm erfordert, verweisen.
