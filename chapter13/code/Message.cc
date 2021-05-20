// #include "Message.h"
// //拷贝构造函数
// Message::Message(const Message& msg):contents(msg.contents),folders(msg.folders){
//     add_to_folders(msg);
// }
// //赋值运算符辅助函数
// void Message::add_to_folders(const Message& m){
//     for (auto &&f : m.folders)
//     {
//         f->addMsg(this);
//     }
// }
// void Message::remove_from_folders(){
//     for (auto &&f : folders)
//     {
//         f->remMsg(this);   
//     }
// }

// //赋值运算符
// Message& Message::operator=(const Message& msg){
//     //先删除在folders中的本msg信息
//     remove_from_folders();
//     //将右侧信息赋值给左侧
//     contents=msg.contents;
//     folders=msg.folders;
//     //将左侧msg添加到右侧msg中的folders中
//     //因为此时左侧和右侧相等，所以直接添加左侧信息即可
//     add_to_folders(msg);
//     return *this;
// }

// void Message::save(Folder& fd){
//     //在本信息记录中添加，记录新发送到哪个folder。 folder<-----msg
//     folders.insert(&fd);
//     //在该folder中记录接受到哪个信息 folder---->msg
//     fd->addMsg(this);
// }

// void Message::remove(Folder& fd){
//     //删除本msg中的该folder记录，set中的是指针，所有要用&取址地址符
//     folders.erase(&fd);
//     //在该folder中删除本msg folder--x-->msg
//     fd.remMsg(this);
// }

// //析构函数
// Message::~Message(){
//     remove_from_folders();
// }