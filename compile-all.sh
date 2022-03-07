#!/bin/bash

# 现在时间
nowTime=""
# 带颜色格式的时间 echo 时 带上 -e 选项
colorTime=""
# 文件名时间
fileTime=""

# 获取时间函数
gtime() {
	nowTime="$(date +%Y-%m-%d) $(date +%H:%M:%S)"
	colorTime="\033[32m$nowTime\033[0m"
	fileTime="$(date +%Y-%m-%d)_$(date +%H:%M:%S)"
}

# 编译全部 cpp 文件到 sh 脚本

gtime
echo -e "$colorTime \033[34m编译开始\033[0m"
logname=$fileTime_Compile.log # 日志文件名
touch ./com_log/$logname      # 创建日志文件
startTime="$nowTime"          # 编译开始时间
fileNum=0                     # 文件数
cppNum=0                      # c++ 文件数
cNum=0                        # c 文件数
for file in $(ls); do
	if [ -f "$file" ]; then
		if [ "${file##*.}"x = "cpp"x ]; then
			gtime
			output="$colorTime Compiling file size & path : \033[36m$(du -h $file)\033[0m"
			echo -e $output
			echo $output >>./com_log/$logname
			g++ $file -o ./compiled/$file.sh
			fileNum=$(expr $fileNum + 1)
			cppNum=$(expr $cppNum + 1)
			gtime
			r="$colorTime Compiled file size & path : \033[36m$(du -h ./compiled/$file.sh)\033[0m"
			echo -e $r
		fi
		if [ "${file##*.}"x = "c"x ]; then
			gtime
			output="$colorTime Compiling file size & path : \033[36m$(du -h $file)\033[0m"
			echo -e "$output"
			echo $output >>./com_log/$logname
			gcc $file -o ./compiled/$file.sh
			fileNum=$(expr $fileNum + 1)
			cNum=$(expr $cNum + 1)
			gtime
			r="$colorTime Compiled file size & path : \033[36m$(du -h ./compiled/$file.sh)\033[0m"
			echo -e $r
		fi
	fi
done
gtime
echo -e "$colorTime 编译日志已记录，位置在：./com_log/$logname"
endTime="$nowTime"
sys_date1=$(date -d "$startTime" +%s)
sys_date2=$(date -d "$endTime" +%s)
deltaTime=$(expr $sys_date2 - $sys_date1)
echo -e "$colorTime 编译总用时：\033[35m$deltaTime\033[0m 秒, 编译项目：\033[35m$fileNum\033[0m 个"
echo -e "$colorTime 编译 C++ 项目 : \033[37;45m$cppNum\033[0m 个 ; C 项目 : \033[37;45m$cNum\033[0m 个 ;"
echo -e "$colorTime \033[31m编译结束，程序已退出\033[0m"
