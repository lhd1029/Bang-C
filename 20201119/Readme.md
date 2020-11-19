# Bang C Hello world
有两种编程方式  
## 普通异构编程  
main.cpp 和 foo2.mlu 联合编译  
```
cncc --bang-device-only --bang-mlu-arch=MLU270 -c foo2.mlu -o foo2.o
g++ -o a.output main.cpp $NEUWARE_HOME/lib64/libcndrv.so foo2.o -I $NEUWARE_HOME/include -L $NEUWARE_HOME/lib64 -lcnrt
```
## 混合编程
```
cncc --bang-mlu-arch=MLU100 --bang-mlu-arch=MLU270  $NEUWARE_HOME/lib64/libcndrv.so foo3.mlu -o a.out
```
编译好的a.out和a.output均可直接运行
