// HelloWorld.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

//C++输入输出库头文件
#include <iostream>
//OpenCV核心库头文件
#include <C:\Developer\opencv\build\include\opencv2\core\core.hpp>
//OpenCV图形处理头文件
#include <C:\Developer\opencv\build\include\opencv2\highgui\highgui.hpp>

//OpenCV核心动态链接库，和core.hpp头文件对应，d代表调试版本
#pragma comment(lib,"opencv_core242d.lib")
//OpenCV图形处理动态链接库，和highgui.hpp头文件对应，d代表调试版本
#pragma comment(lib,"opencv_highgui242d.lib")

int _tmain(int argc, _TCHAR* argv[])
{
	//窗口名称
	std::string windowName = "HelloWorld";
	//图像名称
	std::string imgFile = "opencv-logo.png";
	//读入图像
	cv::Mat image = cv::imread(imgFile, CV_LOAD_IMAGE_COLOR);
	//如果无法读取图形
	if (!image.data)
	{
		std::cout << "无法打开图像文件" << std::endl;
		system("PAUSE");//暂停窗口
		return -1;
	}
	//创建一个新窗口
	cv::namedWindow(windowName, CV_WINDOW_AUTOSIZE);
	//将图像显示都新创建的窗口中
	cv::imshow(windowName, image);
	//等待，直到用户按任意键时退出
	cv::waitKey(0);

	return 0;
}