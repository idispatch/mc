add_library(mc-vfs STATIC
            plugins_init.c
            plugins_init.h
            cpio/cpio.c
            extfs/extfs.c
            fish/fish.c
            ftpfs/ftpfs.c
            local/local.c
            sfs/sfs.c
            tar/tar.c)