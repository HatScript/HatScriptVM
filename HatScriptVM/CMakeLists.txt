add_library(HatScriptVM vm.c vm.h memory.c memory.h Chunk.c Chunk.h Instructions.h HatScriptValue.c HatScriptValue.h)

target_include_directories (HatScriptVM PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})