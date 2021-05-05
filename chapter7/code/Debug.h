#ifndef DEBUG_H
#define DEBUG_H
class Debug
{
private:
    bool hw , io , others;
public:
    constexpr Debug(bool b=true);
    constexpr Debug(bool  , bool , bool  );
    constexpr bool any();
    void set_io(bool);
    void set_hw(bool);
    void set_other(bool);
    ~Debug();
};
#endif