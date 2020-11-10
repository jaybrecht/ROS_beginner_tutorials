# cpplint

## Command Used

My machine cannot seem to lint multiple files at a time so I am individually linting each .cpp file in the src directory

    cpplint <file>

## Results

### change_greeting_client.cpp
    Done processing change_greeting_client.cpp

### listener.cpp
    Done processing listener.cpp

### talker.cpp
```
talker.cpp:9:  Static/global string variables are not permitted.  [runtime/string] [4]
talker.cpp:11:  Is this a non-const reference? If so, make const or use a pointer: beginner_tutorials::ChangeGreeting::Request  &req  [runtime/references] [2]
talker.cpp:12:  Is this a non-const reference? If so, make const or use a pointer: beginner_tutorials::ChangeGreeting::Response &res  [runtime/references] [2]
Done processing talker.cpp
Total errors found: 3
```