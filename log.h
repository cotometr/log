#pragma once

// uncomment what needs to be printed
//#define COTOMETR_DEBUG_LOG

#if defined(COTOMETR_DEBUG_LOG) || defined(COTOMETR_ERROR_LOG)

// write this in the private section of the class
#define CLEAR_LOG()                                         	\
do {                                                        	\
     this->last_deb_log_str = String(__FUNCTION__)              \
                              + " is called\n";                 \
}while(0)

#else
#define CLEAR_LOG()
#endif


#ifdef COTOMETR_DEBUG_LOG

#define CREATE_DEBUG_LOG()                                      \
String last_deb_log_str;                                        \

#define ADD_TO_DEBUG_LOG(value)                                	\
do {                                                        	\
     this->last_deb_log_str += String(__FUNCTION__) + ":"       \
                            + __LINE__ + " " + (value) + "\n";  \
}while(0)

#define GET_DEBUG_LOG()                                         \
const String& get_debug_log() const                             \
{                                                               \
    return last_deb_log_str;                                    \
}                                                               \

#else
#define CREATE_DEBUG_LOG()
#define ADD_TO_DEBUG_LOG(value)

#define GET_DEBUG_LOG()                                         \
const String& get_debug_log() const                             \
{                                                               \
    return "";                                                  \
}                                                               \

#endif

