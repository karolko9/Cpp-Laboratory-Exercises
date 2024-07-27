#include <iostream>
using namespace std;

#include "user.h"
#include "windows.h"


string Windows::version() {
    return version_;
}
size_t Windows::activated_systems(){
    return activated_systems_;
}
Windows::Windows() {
    activated_systems_++;
    cout << "Windows " << version_ << '\n';
}
Windows::Windows(string version) {
    version_ = version;
    activated_systems_++;
    cout << "Windows " << version_ << '\n';
}
size_t Windows::add_user(const string& user_name, const string& password) {
    users_.push_back(User{user_name, password});
    return users_.size() - 1;
}
User Windows::user(size_t user_id){
    return users_[user_id];
}
std::string Windows::user_home_directory(size_t user_id){
    return ("/home/" + users_[user_id].user_name_ + "/");
}

