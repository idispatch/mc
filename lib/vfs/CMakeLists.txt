add_library(mc-vfs-lib STATIC
            direntry.c
            gc.c
            gc.h
            interface.c
            netutil.c
            netutil.h
            parse_ls_vga.c
            path.c
            path.h
            utilvfs.c
            utilvfs.h
            vfs.c
            vfs.h
            xdirentry.h
            )
target_include_directories(mc-vfs-lib PRIVATE ../..)
target_link_libraries(mc-vfs-lib PUBLIC glib-2.0)
#TODO: vfs net option