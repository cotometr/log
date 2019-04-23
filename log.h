#pragma once

#include <WString.h>

// uncomment what needs to be printed
//#define COTOMETR_DEBUG_LOG

#if defined(COTOMETR_DEBUG_LOG) || defined(COTOMETR_ERROR_LOG)

// write this in the private section of the class
#define COTOMETR_LOG_CLEAR()                                    \
do {                                                        	\
     this->last_deb_log_str = String(__FUNCTION__)              \
                              + " is called\n";                 \
}while(0)

#else
#define COTOMETR_LOG_CLEAR()
#endif


#ifdef COTOMETR_DEBUG_LOG

#define COTOMETR_LOG_CREATE_DEBUG()                             \
String last_deb_log_str;                                        \

#define COTOMETR_LOG_ADD_DEBUG(value)                           \
do {                                                        	\
     this->last_deb_log_str += String(__FUNCTION__) + ":"       \
                            + __LINE__ + " " + (value) + "\n";  \
}while(0)

#define COTOMETR_LOG_GET_DEBUG()                                \
const String& get_log_debug() const                             \
{                                                               \
    return last_deb_log_str;                                    \
}                                                               \

#else
#define COTOMETR_LOG_CREATE_DEBUG()
#define COTOMETR_LOG_ADD_DEBUG(value)

#define COTOMETR_LOG_GET_DEBUG()                                \
const String& get_log_debug() const                             \
{                                                               \
    static String empty;                                        \
    return empty;                                               \
}                                                               \

#endif

