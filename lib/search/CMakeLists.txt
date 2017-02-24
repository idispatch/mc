add_library(mc-search STATIC
            glob.c
            hex.c
            internal.h
            lib.c
            normal.c
            regex.c
            search.c)
target_include_directories(mc-search PRIVATE ../..)
target_link_libraries(mc-search PUBLIC glib-2.0 pcre)