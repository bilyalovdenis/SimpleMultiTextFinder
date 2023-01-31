#ifndef SIMPLEGREPINTERFACEAREA_H
#define SIMPLEGREPINTERFACEAREA_H


class SimpleGrepInterfaceArea
{
public:
    static SimpleGrepInterfaceArea* get_instance();
private:
    static SimpleGrepInterfaceArea* instance_ = new(;
};

#endif // SIMPLEGREPINTERFACEAREA_H
