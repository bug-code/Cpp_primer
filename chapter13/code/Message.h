// #ifndef MESSAGE_H
// #define MESSAGE_H
// #include <string>
// #include <set>
// class Folder;
// class Message
// {
//     friend class Folder;
// private:
//     std::string contents;
//     std::set<Folder*> folders;
//     /*添加到新的消息目录folder*/
//     void add_to_folders(const Message&);
//     /*从所有消息目录floaders中删除消息*/
//     void remove_from_folders();
// public:
//     Message(const std::string& str="" ):contents(str),folders(std::set<Folder*>()){};
//     Message(const Message&);
//     Message& operator=(const  Message&);
//     /*添加新消息Message到消息队列.
//         1.在消息队列folder中需要添加指向该消息的指针
//         2.在消息的folders成员中需要添加指向添加到的folder的指针
//         3.删除同理
//     */
//     void save(Folder&);
//     void remove(Folder&);
//     /*删除所有指针*/
//     ~Message();
// };
// #endif