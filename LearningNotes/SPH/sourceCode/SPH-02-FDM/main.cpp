#include <iostream>
#include <vector>
#include <direct.h>
#include <math.h>
#include <windows.h>
#include <sys/stat.h>
#include <fstream>
#include <filesystem>
#include "SPH02-FDM.h"
#define M_PI 3.14159265358979323846

namespace fs = std::filesystem;

int main()
{
    // 申明自变量x数组
    std::vector<double> xAarry(12, 0.0);

    // 申明因变量y数组，用于存储数值解；采用第一种差分格式
    std::vector<double> y1ArrayNumericalSolution(xAarry.size(), 0.0);

    // 声明因变量y数组，用于存储数值解；采用第二种差分格式
    std::vector<double> y2ArrayNumericalSolution(xAarry.size(), 0.0);

    // 声明因变量y数组，用于存储解析解
    std::vector<double> yArrayAnalyticalSolution(xAarry.size(), 0.0);

    // 设置输出文件的存储路径
    std::string Path = "E:/CodeProjects/VScode/Zhihu_Paper/LearningNotes/SPH/sourceCode/build/data";
    
    // 设置计算区间
    std::vector<double> xDomain = { 0.0, 2.0 * M_PI };

    // 设置计算步长
    double h = (xDomain[1] - xDomain[0]) / (xAarry.size() - 1);

    // 设置边界条件
    xAarry[0] = 0.0;
    yArrayAnalyticalSolution[0] = 0.0;
    y1ArrayNumericalSolution[0] = 0.0;
    y2ArrayNumericalSolution[0] = 0.0;

    // 给x数组赋值
    for (int i = 1; i < xAarry.size(); i++)
    {
        xAarry[i] = xAarry[i - 1] + h;
    }

    // 第一种差分格式，计算Y的数值解
    for (int i = 1; i < xAarry.size() - 1; i++)
    {
        y1ArrayNumericalSolution[i] = y1ArrayNumericalSolution[i - 1] + std::sin(xAarry[i - 1]) * h;
    }

    // 第二种差分格式，计算Y的数值解
    for (int i = 1; i < xAarry.size() - 1; i++)
    {
        y2ArrayNumericalSolution[i] = y2ArrayNumericalSolution[i - 1] + std::sin(xAarry[i - 1] + h / 2.0) * h;
    }

    // 计算解析解`
    for (int i = 0; i < xAarry.size(); i++)
    {
        yArrayAnalyticalSolution[i] = 1.0 - std::cos(xAarry[i]);
    }

    
    if (fs::exists(Path))
    {   
        // 如果给定路径存在，先删除后创建
        fs::remove_all(Path);
        fs::create_directories(Path);
    }
    else
    {
        // 如果指定路径不存在，直接创建
        fs::create_directories(Path);
    }

    std::ofstream file;
    const std::string fileName = "SPH02-FDM-output.txt";
    std::string fullPath = Path + "/" + fileName;
    file.open(fullPath, std::ios::out);
    if (file.is_open())
    {   
        // 输出数值解
        for (int i = 0; i < xAarry.size(); i++)
        {
            file << xAarry[i] << " " << y1ArrayNumericalSolution[i] << " " << y2ArrayNumericalSolution[i] << " " << yArrayAnalyticalSolution[i] << std::endl;
        }
    }
    file.close();
    return 0;
}
