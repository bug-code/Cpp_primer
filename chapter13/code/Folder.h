// #ifndef FOLDER_H
// #define FOLDER_H
// #include "Message.cc"
// class Folder
// {
// private:
//     std::set<Message*> Msgs;
//     void add_to_Message(const Folder&);
//     void remove_from_Message();

//     void addMsg(Message *m) { Msgs.insert(m); }
//     void remMsg(Message *m) { Msgs.erase(m); }
// public:
//     Folder()=default;
//     //拷贝构造函数
//     Folder(const Folder& f):Msgs(f.Msgs){}
//     //拷贝赋值函数
//     Folder& operator=(const Folder&);

//     ~Folder();
// };

// #endif