// ConsoleApplication20180906.cpp: 定义控制台应用程序的入口点。
//



#include "stdafx.h"
#include<opencv2\core.hpp>
#include<opencv2\highgui.hpp>
 
using namespace cv;
 
int main()
{
	Mat img = imread("111.png");
	namedWindow("hahaha");
	imshow("hahaha",img);

	waitKey(1000);

	return 0;
}