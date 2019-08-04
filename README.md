一个简单的OpenGL Demo。

Util目录下为通用工具，如果文件读取，矩阵计算等等。

Util/Android会创建Android的特有工具类，继承Util下的通用父类，Util下的父类是为了解耦，同时以便其他操作系统的扩展。

DataObject -- 存储物体数据。

GameObject -- 为一个通用的3D物体，OpenGL或者Vulkan一个物体的父类，便于解耦和扩展。

Environment -- 管理整个3D通用环境。

GLObject/GLEnvironment -- GameObject和Envrionment的OpenGL实现。

game-jni -- 提供给java层用的接口。


