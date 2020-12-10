#ifndef ZWIERZE
#define ZWIERZE

class Zwierze {
    public:
        virtual void dajGlos() = 0;
        Zwierze() = default;
        virtual ~Zwierze() = default;
    private:
};

#endif