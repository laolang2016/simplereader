# 功能：程序运行脚本
# 作者：小代码
# 时间：2015年10月04日09:19:22
#
#


# 可执行程序的名称
program=contacts

# 程序的构建目录
build_dir=build

# 二进制文件目录
bin_dir=bin

all:execute


.PHONY:init compile clean execute
init:
	@echo "执行cmake"
	@cd build;	\
	cmake ..
	@echo "复制文件"
	@cd ./bin;	\
	cp person.xml.bak person.xml
compile:init
	@echo "编译"
	@cd build;	\
	${MAKE}
clean:
	@echo "清理"
	@cd build;	\
	${MAKE} clean
execute:compile
	@echo "运行"
	@cd bin;	\
	./${program} tree.xml


