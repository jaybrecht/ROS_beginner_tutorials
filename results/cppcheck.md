# cppcheck

## Command Used
    cppcheck --enable=all --std=c++11 $( find . -name *.cpp)

## Results 
```
Checking src/change_greeting_client.cpp ...
1/3 files checked 31% done
Checking src/listener.cpp ...
2/3 files checked 44% done
Checking src/talker.cpp ...
3/3 files checked 100% done
(information) Cppcheck cannot find all the include files (use --check-config for details)
```