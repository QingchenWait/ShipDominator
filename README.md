# 驭船术 | ShipDominator
    曼大 MSc 机械工程学位中的 Group Design 项目。目标是为垃圾收集船编写远程控制程序。
    最终交付版本（V7）已经发布：https://github.com/QingchenWait/ShipDominator/releases/tag/V7-Final
- 预期目标 <br/>
使用Audrino作为控制中枢，通过蓝牙模块进行遥控，使垃圾收集船实现各类预期动作。<br/>
（例如：启动、停止；左转、右转；加速、减速......）
- 计划使用零件 <br/>
  - Arduino Mega 2560 开发板；
  - 两只 DC 马达，作为垃圾收集船的运动动力来源；
  - 两只 DC 马达，作为船体内垃圾传送带的动力来源；
  - L293D 马达控制IC芯片；
  - HC-05 蓝牙模块；
  - 其他零散部件。
- 版本迭代说明
  - 版本发布页面地址： https://github.com/QingchenWait/ShipDominator/releases
  - 本计划分为两个阶段。<br/>
  第一个阶段，新版本名以“控船术”为前缀。主要目标为利用自行在 Amazon 购买的 Arduino 入门开发套件中的零件(包括 Arduino UNO 开发板、低功率DC马达与红外模块），实现与 Group Design 目标类似的功能。<br/>
  第二个阶段，新版本名以“驭船术”为前缀。这一阶段将在所需零件全部到手后开启，进行针对 Group Design 设计需求的开发。<br/>
  - 进入“驭船术”阶段后，版本号依然在“控船术”的基础上进行迭代。
  - 在主分支上，将新建一个 Exercise 分支。用于保存与该项目没有直接关系的 Arduino 开发练习。
- 版权保护声明<br/>
  - 本仓库由曼彻斯特大学 2019/20 届 Haoyang.Li 创建并维护。仓库中包含的所有内容，仅供参考学习所用，版权仅由 Haoyang.Li 所在的 Group Design 小组全体成员共同拥有，并保留复制权。公开代码的时间戳，以本 GITHUB 仓库（名称：ShipDominator）中所示的时间戳为初始来源标准。<br/>
  - 为保护源码，计划在最新版的代码制作完成后，才会在本仓库内发布前一版代码的 Release 版本。
