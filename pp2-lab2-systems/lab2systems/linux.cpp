#include <iostream>
using namespace std;
#include <optional>
#include "user.h"
#include "linux.h"

using namespace std;
Linux::Linux() {
    distribution_ = "Ubuntu";
    open_source_system_users_++;
    cout << "+" << distribution_ << '\n';
}
Linux::Linux(std::string distribution) {
    distribution_ = distribution;
    open_source_system_users_++;
    cout << "+" << distribution_ << '\n';
}
Linux::~Linux(){
    open_source_system_users_--;
    cout << "~" << distribution_ << '\n';
}
size_t Linux::add_user(const string& user_name, const string& password) {
    users_.push_back(User{user_name, password});
    return users_.size() - 1;
}
std::string Linux::distribution(){
    return distribution_;
}
std::string Linux::user_home_directory(size_t user_id){
    return ("/home/" + users_[user_id].user_name_ + "/");
}
size_t Linux::open_source_sympathizers(){
    return open_source_system_users_;
}
optional<string> Linux::graphic_environment() const{
    return graphic_environment_;
}
void Linux::set_graphic_environment(const string& graphic_environment){
    graphic_environment_=graphic_environment;
}
User Linux::user(size_t user_id){
    return users_[user_id];
}
