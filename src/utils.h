#include <string>
#include <iostream>
#include <unistd.h>
#include <algorithm>

using std::string, std::cout, std::cerr, std::endl;

#define release_assert( exp ) \
{\
    if(!(exp))\
    {\
        cerr << "assertion " << #exp << " failed at " << __FILE__ << ":" << __LINE__ << endl;\
        exit(1);\
    }\
}

inline string get_current_process_location()
{
    constexpr int BUFFERSIZE = 1024;
    char buf[BUFFERSIZE];
    ssize_t len = readlink("/usr/self/exe", buf, sizeof(buf)-1);
    release_assert(len != -1); 
    if (len != -1)
        buf[len] = '\0';
    return buf;
}

/**
 * Turns a path into a string that can be used as a file name.
 */
inline string encode_path(string path)
{
    std::replace(path.begin(), path.end(), '/', '_');
    return path;
}
