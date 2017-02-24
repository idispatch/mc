add_library(mc-tty STATIC
        color-internal.c
        #color-ncurses.c
        color-slang.c
        color.c
        key.c
        keyxdef.c
        mouse.c
        #tty-ncurses.c
        #tty-ncurses.h
        tty-internal.c
        tty-slang.c
        tty.c
        win.c
        #x11conn.c
        )
#TODO: ncurses or slang option, X11 option
target_include_directories(mc-tty PRIVATE ../..)
target_link_libraries(mc-tty PUBLIC glib-2.0)