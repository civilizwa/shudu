// (C) Copyright 2023 Yunmei Guan, Jiaqi Shi
// Description：Sudoku Game
// Author：GYM, SJQ
// Date:2023-6
// Modify Record:
#pragma once
#include <math.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <random>
#include "SolveHandler.h"
using namespace std;
// using std::cout;
// using std::endl;
// 在需要使用std命名空间中的符号时，使用using-declaration逐个引入


class Generatehandler {
private:
	string FinalPath = "final.txt";
	string outputPath = "question.txt";
	string absolatePath = "D:\\LessonProjects\\shudu\\shudu";
	int FinalNum = 0;// 终局数目
	int current_HoleNum = 0;// 当前挖空数
	int current_selectFinal = 0;// 当前使用的棋盘终局
	int matrix[100][9][9] = { 0 };// 开辟一个大数组，存储最多100个终局
	int holeboard[9][9] = { 0 };// 当前挖空的棋盘位置

public:
	bool generate(int num, int beginNum, int endNum, bool isUnion);
	void holehole();// 挖呀挖呀挖
	void input(fstream& f);
	void output(fstream& f, vector<std::vector<int>>& board);
	void SelectFinal();
	int isNum(const string& s);
	// 检查在给定位置 (row, col) 是否可以放置数字 num
	bool isValid(const vector<std::vector<int>>& board, int row, int col, int num);
	// 使用回溯算法生成数独游戏的唯一解
	bool solveSudoku(vector<std::vector<int>>& board);
	// 生成数独游戏题目
	void generateSudoku(vector<std::vector<int>>& board);
	// 生成在min-max范围间的随机数
	int generateRandomNumber(int min, int max);
	// 设置绝对路径
	void setAbsPath(string abs) {
		absolatePath = abs;
	}
};