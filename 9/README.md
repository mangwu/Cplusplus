# vscode中的不同文件的编译方式

## 使用g++命令在bash中编译

配置编译器设置或构建系统：为了确保所有文件都被正确地编译和链接，你需要配置你的构建系统。如果你直接使用g++，可以在终端运行类似下面的命令来编译：

```bash
g++ -I./include src/main.cpp src/functions.cpp -o my_program
```

1. -I 是一个用于指定头文件搜索路径的编译器选项，后续./include是文件目录，根据需要修改
2. src/main.cpp 是包含main主函数的文件
3. src/functions.cpp 是包含函数定义的文件
4. -o 表示指定输出文件的名称，这里定义为了 my_program

## 配置vscode的`tasks.json`和`launch.json`文件

为了在VSCode中自动构建你的项目，你需要创建一个任务来运行你的编译命令。可以通过以下步骤完成：

### 配置`tasks.json`

打开命令面板（Ctrl+Shift+P），然后输入“Tasks: Configure Task”，选择它。
选择“Create tasks.json file from template”，然后选择“Others”模板。
在生成的tasks.json文件中，配置你的编译命令。例如：

```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "build",
            "type": "shell",
            "command": "g++",
            "args": [
                "-I./include",
                "src/main.cpp",
                "src/functions.cpp",
                "-o",
                "my_program"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "problemMatcher": ["$gcc"],
            "detail": "Generated task for building the project."
        }
    ]
}
```

1. `tasks.json`文件一般存在于.vscode文件夹下，之前创建了可以直接编译
2. `tasks`中的任务可以有多个和任务，其中args是你本次任务在调试时的文件头，文件名等的参数，按需修改

### 配置`launch.json`

接下来，需要配置调试器以便于启动你的程序并进行调试。按照以下步骤操作：

点击左侧活动栏中的调试图标，然后点击齿轮图标以打开launch.json配置文件。
添加一个新的配置，用于启动你的程序。这里是一个例子：

```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "(gdb) Launch",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/my_program", // 调整为你的可执行文件路径
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "build", // 这里引用之前定义的任务名称
            "miDebuggerPath": "/usr/bin/gdb", // 根据实际情况调整GDB路径
            "logging": {
                "trace": true,
                "traceResponse": true,
                "engineLogging": true
            }
        }
    ]
}
```

1. 确保 "preLaunchTask" 字段设置为你在 tasks.json 中定义的任务名称，这样每次启动调试前都会自动编译你的项目。
2. configurations中可以存在多个调试任务，注意`name`的名称，在vscode的运行和调试目录是以它为标识的

完成上述配置后，你可以通过点击侧边栏的调试图标，选择你配置好的调试环境，然后按F5键开始调试你的程序。这样，你就可以利用断点、变量观察等功能来进行调试了。
