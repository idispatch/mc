add_library(mc-event STATIC event.c manage.c raise.c internal.h)
target_include_directories(mc-event PRIVATE ../..)
target_link_libraries(mc-event PUBLIC glib-2.0)