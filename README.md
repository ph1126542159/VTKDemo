# TestVTK
VTK Example
# 环境配置
1.在主CMakeLists.txt 文件设置vtk的搜索路径
2.Qt版本5.15.2
3.VTK 版本9.3
# displaychinese 示例程序有bug 直接崩溃未查到原因

# custom3dwidget 示例中 Custom XY Widget有崩溃错误暂未查到原因

# filter 示例程序中 
引用的filereaderutils.h 中套用了vtkUnstructuredGridRelevantPointsFilter.h
在中套用了vtkUnstructuredGridRelevantPointsFilter.cpp 中 vtkCellArray类的 GetPointer()
老版本弃用暂未找到替代代码段 暂时注释掉部分代码

# imageprocess 示例程序中有错误 加载图片死循环

# shader 示例程序中vtkShaderProgram2 找不到,使用vtkShaderProgram后找不到老版本的加载shader函数
2个文件需要修改
    1)shaderwindow.cpp
    2)editshaderwindow.cpp