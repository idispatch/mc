add_library(mc-strutil STATIC
            filevercmp.c
            replace.c
            strescape.c
            strutil.c
            strutil8bit.c
            strutilascii.c
            strutilutf8.c
            strverscmp.c
            xstrtol.c)
target_include_directories(mc-strutil PRIVATE ../..)
target_link_libraries(mc-strutil PUBLIC glib-2.0)