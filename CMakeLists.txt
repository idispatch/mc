cmake_minimum_required(VERSION 3.10)
project(mc LANGUAGES C)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GLIB REQUIRED glib-2.0)
pkg_check_modules(GMODULE REQUIRED gmodule-2.0)

pkg_check_modules(SLANG REQUIRED slang)

pkg_check_modules(LIBSSH2 REQUIRED libssh2)

#pkg_check_modules(ASPELL REQUIRED aspell)

add_library(mclib STATIC
        lib/event/event.c
        lib/event/internal.h
        lib/event/manage.c
        lib/event/raise.c

        lib/filehighlight/common.c
        lib/filehighlight/get-color.c
        lib/filehighlight/ini-file-read.c
        lib/filehighlight/internal.h
        lib/mcconfig/common.c
        lib/mcconfig/get.c
        lib/mcconfig/history.c
        lib/mcconfig/set.c
        lib/mcconfig/paths.c
        lib/search/search.c
        lib/search/internal.h
        lib/search/lib.c
        lib/search/normal.c
        lib/search/regex.c
        lib/search/glob.c
        lib/search/hex.c

        lib/skin/colors.c
        lib/skin/colors-old.c
        lib/skin/common.c
        lib/skin/hc-skins.c
        lib/skin/ini-file.c
        lib/skin/lines.c
        lib/skin/internal.h

        lib/strutil/filevercmp.c
        lib/strutil/replace.c
        lib/strutil/strescape.c
        lib/strutil/strutil8bit.c
        lib/strutil/strutilascii.c
        lib/strutil/strutil.c
        lib/strutil/strutilutf8.c
        lib/strutil/strverscmp.c
        lib/strutil/tokenize.c
        lib/strutil/xstrtol.c

        lib/tty/color-slang.c
        lib/tty/color-slang.h
        lib/tty/tty-slang.c
        lib/tty/tty-slang.h
        #else
        #TTY_SCREEN_SRC = \
        #color-ncurses.c \
        #tty-ncurses.c tty-ncurses.h
        #	endif

        lib/tty/color.c
        lib/tty/color.h
        lib/tty/color-internal.c
        lib/tty/color-internal.h
        lib/tty/key.c
        lib/tty/key.h
        lib/tty/keyxdef.c
        lib/tty/mouse.c
        lib/tty/mouse.h
        lib/tty/tty-internal.c
        lib/tty/tty-internal.h
        lib/tty/tty.c
        lib/tty/tty.h
        lib/tty/win.c
        lib/tty/win.h

        #if HAVE_TEXTMODE_X11_SUPPORT
        #TTY_SRC += x11conn.c x11conn.h
        #endif

        #libmctty_la_SOURCES = $(TTY_SRC) $(TTY_SCREEN_SRC)

        lib/vfs/direntry.c
        lib/vfs/gc.c
        lib/vfs/gc.h
        lib/vfs/interface.c
        lib/vfs/parse_ls_vga.c
        lib/vfs/path.c
        lib/vfs/path.h
        lib/vfs/vfs.c
        lib/vfs/vfs.h
        lib/vfs/utilvfs.c
        lib/vfs/utilvfs.h
        lib/vfs/xdirentry.h
        lib/vfs/netutil.c
        lib/vfs/netutil.h


        lib/widget/background.c
        lib/widget/background.h
        lib/widget/button.c
        lib/widget/button.h
        lib/widget/buttonbar.c
        lib/widget/buttonbar.h
        lib/widget/check.c
        lib/widget/check.h
        lib/widget/dialog.c
        lib/widget/dialog.h
        lib/widget/dialog-switch.c
        lib/widget/dialog-switch.h
        lib/widget/frame.c
        lib/widget/frame.h
        lib/widget/gauge.c
        lib/widget/gauge.h
        lib/widget/group.c
        lib/widget/group.h
        lib/widget/groupbox.c
        lib/widget/groupbox.h
        lib/widget/hline.c
        lib/widget/hline.h
        lib/widget/history.c
        lib/widget/history.h
        lib/widget/input.c
        lib/widget/input.h
        lib/widget/input_complete.c
        lib/widget/listbox-window.c
        lib/widget/listbox-window.h
        lib/widget/listbox.c
        lib/widget/listbox.h
        lib/widget/label.c
        lib/widget/label.h
        lib/widget/menu.c
        lib/widget/menu.h
        lib/widget/mouse.c
        lib/widget/mouse.h
        lib/widget/quick.c
        lib/widget/quick.h
        lib/widget/radio.c
        lib/widget/radio.h
        lib/widget/rect.c
        lib/widget/rect.h
        lib/widget/widget-common.c
        lib/widget/widget-common.h
        lib/widget/wtools.c
        lib/widget/wtools.h

        lib/charsets.c
        lib/charsets.h
        lib/event.h
        lib/event-types.h
        lib/file-entry.h
        lib/filehighlight.h
        lib/fileloc.h
        lib/fs.h
        lib/glibcompat.c
        lib/glibcompat.h
        lib/global.c
        lib/global.h
        lib/hook.c
        lib/hook.h
        lib/idx.h
        lib/intprops.h
        lib/intprops-internal.h
        lib/keybind.c
        lib/keybind.h
        lib/lock.c
        lib/lock.h
        lib/logging.c
        lib/logging.h
        lib/mcconfig.h
        lib/search.h
        lib/serialize.c
        lib/serialize.h
        lib/shell.c
        lib/shell.h
        lib/skin.h
        lib/stat-size.h
        lib/strutil.h
        lib/terminal.c
        lib/terminal.h
        lib/timefmt.c
        lib/timefmt.h
        lib/unixcompat.h
        lib/util.c
        lib/util.h
        lib/utilunix.c
        lib/widget.h

        src/consaver/cons.saver.c
        src/consaver/cons.saver.h

        src/diffviewer/internal.h
        src/diffviewer/search.c
        src/diffviewer/ydiff.c
        src/diffviewer/ydiff.h

        src/editor/bookmark.c
        src/editor/edit.c
        src/editor/edit.h
        src/editor/edit-impl.h
        src/editor/editbuffer.c
        src/editor/editbuffer.h
        src/editor/editcmd.c
        src/editor/editcomplete.c
        src/editor/editcomplete.h
        src/editor/editdraw.c
        src/editor/editmacros.c
        src/editor/editmacros.h
        src/editor/editmenu.c
        src/editor/editoptions.c
        src/editor/editsearch.c
        src/editor/editsearch.h
        src/editor/editwidget.c
        src/editor/editwidget.h
        src/editor/etags.c
        src/editor/etags.h
        src/editor/format.c
        src/editor/spell.c
        src/editor/spell.h
        src/editor/syntax.c


        src/filemanager/achown.c
        src/filemanager/boxes.c
        src/filemanager/boxes.h
        src/filemanager/cd.c
        src/filemanager/cd.h
        src/filemanager/chmod.c
        src/filemanager/chown.c
        src/filemanager/cmd.c
        src/filemanager/cmd.h
        src/filemanager/command.c
        src/filemanager/command.h
        src/filemanager/dir.c
        src/filemanager/dir.h
        src/filemanager/ext.c
        src/filemanager/ext.h
        src/filemanager/file.c
        src/filemanager/file.h
        src/filemanager/filegui.c
        src/filemanager/filegui.h
        src/filemanager/filemanager.h
        src/filemanager/filemanager.c
        src/filemanager/filenot.c
        src/filemanager/filenot.h
        src/filemanager/find.c
        src/filemanager/hotlist.c
        src/filemanager/hotlist.h
        src/filemanager/info.c
        src/filemanager/info.h
        src/filemanager/ioblksize.h
        src/filemanager/layout.c
        src/filemanager/layout.h
        src/filemanager/mountlist.c
        src/filemanager/mountlist.h
        src/filemanager/panelize.c
        src/filemanager/panelize.h
        src/filemanager/panel.c
        src/filemanager/panel.h
        src/filemanager/tree.c
        src/filemanager/tree.h
        src/filemanager/treestore.c
        src/filemanager/treestore.h

        src/subshell/common.c
        src/subshell/internal.h
        src/subshell/proxyfunc.c
        src/subshell/subshell.h

        src/vfs/cpio/cpio.c
        src/vfs/cpio/cpio.h

        src/vfs/extfs/extfs.c
        src/vfs/extfs/extfs.h

        src/vfs/ftpfs/ftpfs.c
        src/vfs/ftpfs/ftpfs.h
        src/vfs/ftpfs/ftpfs_parse_ls.c

        src/vfs/local/local.c
        src/vfs/local/local.h

        src/vfs/sfs/sfs.c
        src/vfs/sfs/sfs.h

        src/vfs/shell/shell.c
        src/vfs/shell/shell.h
        src/vfs/shell/shelldef.h

        src/vfs/sftpfs/config_parser.c
        src/vfs/sftpfs/connection.c
        src/vfs/sftpfs/dir.c
        src/vfs/sftpfs/file.c
        src/vfs/sftpfs/internal.c
        src/vfs/sftpfs/internal.h
        src/vfs/sftpfs/sftpfs.c
        src/vfs/sftpfs/sftpfs.h

        src/vfs/tar/tar.c
        src/vfs/tar/tar.h
        src/vfs/tar/tar-internal.c
        src/vfs/tar/tar-internal.h
        src/vfs/tar/tar-sparse.c
        src/vfs/tar/tar-xheader.c

        src/vfs/plugins_init.c
        src/vfs/plugins_init.h

        src/viewer/actions_cmd.c
        src/viewer/ascii.c
        src/viewer/coord_cache.c
        src/viewer/datasource.c
        src/viewer/dialogs.c
        src/viewer/display.c
        src/viewer/growbuf.c
        src/viewer/hex.c
        src/viewer/internal.h
        src/viewer/lib.c
        src/viewer/mcviewer.c
        src/viewer/mcviewer.h
        src/viewer/move.c
        src/viewer/nroff.c
        src/viewer/search.c

        src/args.c
        src/args.h
        src/background.c
        src/background.h
        src/clipboard.c
        src/clipboard.h
        src/cons.handler.c
        src/events_init.c
        src/events_init.h
        src/execute.c
        src/execute.h
        src/file_history.c
        src/file_history.h
        src/help.c
        src/help.h
        src/history.h
        src/keymap.c
        src/keymap.h
        src/learn.c
        src/learn.h
        src/selcodepage.c
        src/selcodepage.h
        src/setup.c
        src/setup.h
        src/textconf.c
        src/textconf.h
        src/usermenu.c
        src/usermenu.h
        src/util.c
        src/util.h
)

target_include_directories(mclib
        PUBLIC
        ${GLIB_INCLUDE_DIRS}
        ${LIBSSH2_INCLUDE_DIRS}
        ${SLANG_INCLUDE_DIRS}
        build
        ${CMAKE_CURRENT_LIST_DIR}

        #${ASPELL_INCLUDE_DIRS}
        /usr/local/include
)

target_compile_definitions(mclib PRIVATE
        -DLIBEXECDIR=\"bla\"
        -DEXTHELPERSDIR=\"bla\")

target_link_libraries(mclib
        PUBLIC
        ${GLIB_LIBRARIES}
        ${GMODULE_LIBRARIES}
        ${SLANG_LIBRARIES}
        ${LIBSSH2_LIBRARIES}
        aspell
        #${ASPELL_LIBRARIES}
)
target_link_directories(mclib PUBLIC ${GLIB_LIBDIR} /usr/local/lib)


add_executable(mc src/main.c)
target_compile_definitions(mc PRIVATE
        -DSYSCONFDIR=\"bla\"
        -DDATADIR=\"bla\"
        -DLOCALEDIR=\"bla\")
target_link_libraries(mc PRIVATE mclib)
