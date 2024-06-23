#ifndef FUTURE_H
#define FUTURE_H
#include <future>
template<typename T>
bool future_is_ready(std::future<T>& t){
    return t.wait_for(std::chrono::seconds(0)) == std::future_status::ready;
}


#endif
