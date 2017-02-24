add_library(mc-config STATIC history.c common.c get.c paths.c set.c)
target_include_directories(mc-config PRIVATE ../..)
target_link_libraries(mc-config PUBLIC glib-2.0)