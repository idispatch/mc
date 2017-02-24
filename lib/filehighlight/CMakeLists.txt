add_library(mc-filehighlight STATIC
            common.c
            get-color.c
            ini-file-read.c
            internal.h)
target_include_directories(mc-filehighlight PRIVATE ../..)
target_link_libraries(mc-filehighlight PUBLIC glib-2.0)