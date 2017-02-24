add_library(mc-skin
            colors.c
            colors-old.c
            common.c
            hc-skins.c
            ini-file.c
            lines.c
            internal.h)
target_include_directories(mc-skin PRIVATE ../..)
target_link_libraries(mc-skin PUBLIC glib-2.0)