# set(target ${MP2_LIBRARY})

file(GLOB hdrs "*.h*" "include/*.h*")
file(GLOB srcs "*.cpp")

add_executable(arithEq ${srcs} ${hdrs})