typing game with Qt-Creator
===========================
使用Qt Creator制作的打字小游戏
--------------------------
# 一、 功能介绍
##  1． 程序启动时在画面左边随机产生字母，以一定的速度自左向右移动
##  2． 使用键盘敲击对应的字母即消失，并重新在画面最左端随机产生一个字母
##  3． 当字母由画面最左端移动至最右端，没有被键盘敲击到，则游戏结束
##  4． 运行状态下按下空格可暂停，暂停状态下按一次空格键即继续游戏
##  5． 一局后结束按 F1 继续游戏，按 ESC 即可退出
##  6． 按 F2 显示帮助信息
# 二、 编译运行环境
Windows10 系统下，使用 Qt Creator4.3.0
# 三、 模块划分
##  1. 图片模块
letterPic 类，定义了每一个图片的各种性质：
- a) x,y 坐标
- b) 图片宽和高
- c) 运动速度
- d) 图片的 ID（一共有 36 个 ID，对应数字 0\~9，字母 A\~Z 的图片）
##  2. 随机数模块
randChar()函数，随机产生一个数字或字母字符，作为产生的图片的 ID
##  3. 控制模块（主窗口）
控制游戏的流程，其中包含以下部分：
- a) 初始化：  

游戏开始时的状态，生成三个图片的对象进行显示，开始计数器
- b) 绘图：  

重写 QMainWindow 的 paintEvent（），重绘时把相应的要显示数字
和字母的图片绘至应用窗口上
- c) 运动：  

槽函数，与计时器连接，每隔 300ms 刷新一次运动状态，把字符图
片的位置像右移动一定像素
- d) 按键触发：  

重写 QMainWindow::keyPressEvent()函数，每按下一次按键刷新一次
运动状态。  

若按键按倒图片对应的字符，则删除该图片对象
