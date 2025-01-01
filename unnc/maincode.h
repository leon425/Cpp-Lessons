#pragma once

#ifndef MAINCODE_H  // Header guard to prevent duplicate inclusion
#define MAINCODE_H
#include <vector>
#include <stdexcept> // exception throw in mainCode.cpp


std::vector<int> cons(int x, std::vector<int> list);

bool isEmpty(std::vector<int> list);

int value(std::vector<int> list);

std::vector<int> tail(std::vector<int> list);

int length(std::vector<int> list);

int getNth(int n, std::vector<int> list);

std::vector<int> delNth(int n, std::vector<int> list);

int max(int a, int b)

#endif
