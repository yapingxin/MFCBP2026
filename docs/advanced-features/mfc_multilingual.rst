
国际化：实现多国语言界面
=============================

《MFC程序国际化：实现多国语言界面》

前言
------

写作目的
~~~~~~~~~~

本文旨在演示如何为 MFC 程序增加多国语言界面。某产品从国内使用转为外贸出口，为此产品开发的上位机软件采用的是简体中文界面，现在需要对上位机软件进行改造，增加英文等多国语言界面。为了实现这一需求，本人编写了一个演示程序，通过为这个演示程序增加多国语言界面来探讨 MFC 程序的国际化技术。

演示程序
~~~~~~~~~~

本文配套的演示程序采用递进的方式逐渐增加多国语言界面及相关功能。演示程序的各个版本如 :numref:`table_mfcmul_DemoUtilVersionsTable` 所示。

.. list-table:: 演示程序的各个版本
   :name: table_mfcmul_DemoUtilVersionsTable
   :widths: 10 18 18
   :header-rows: 1
   :align: center

   * - 版本号
     - 下载链接
     - 说明
   * - 0.2.0.0
     - Resource/Demos/Multilingual_v0.2.0.0.zip
     - 初始版本
   * - 0.2.0.1
     - Resource/Demos/Multilingual_v0.2.0.1.zip
     - 小改动
   * - 0.2.0.2
     - Resource/Demos/Multilingual_v0.2.0.2.zip
     - 增加多国语言显示界面
   * - 0.2.0.3
     - Resource/Demos/Multilingual_v0.2.0.3.zip
     - 增加界面显示语言选择对话框

演示程序的初始版本
