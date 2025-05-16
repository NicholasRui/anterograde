
Get GLFW like this:
https://www.youtube.com/watch?v=7-dL6a5_B3I

Get GLAD like this:
https://glad.dav1d.de/

Compile and run like this:
/usr/bin/clang++ -I ./dependencies/include/ -L ./dependencies/libraries/ -fcolor-diagnostics -fansi-escape-codes -g main.cpp -o ./main -framework Cocoa -framework OpenGL -framework IOKit ./dependencies/libraries/libglfw.3.dylib ./dependencies/include/glad/glad.c -Wl,-rpath,./dependencies/libraries/ ; ./main



