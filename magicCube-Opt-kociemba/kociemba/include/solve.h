#pragma once
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "search.h"
using namespace std;

class Solve
{
public:
	Solve() {}
	~Solve() {}

public:
	static __declspec(dllexport) string _Slove(string* input);
};

