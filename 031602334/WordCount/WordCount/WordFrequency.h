﻿//
//  WordFrequency.h
//  词频统计
//
//  Created by wenyiqian on 2018/9/10.
//  Copyright © 2018年 ding. All rights reserved.
//


#include <stdio.h>
#include <fstream>
#include <cstring>
#include <regex>
#include <map>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define pii pair<int, int>
#define msi map<string, int>
#define psi pair<string, int>
#define vpsi vector<psi>

long wordsCount(const char *filename);

void WordsPrint(const char *filename, const char *filename2, int num);