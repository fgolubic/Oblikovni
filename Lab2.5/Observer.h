#ifndef OBSERVER_H

#define OBSERVER_H

class NumberSequence;

class Observer
{
    friend bool operator==(Observer const& lhs, Observer const& rhs)
    {
        return lhs.identity_ == rhs.identity_;
    }

public:
    Observer();

    virtual void update(NumberSequence const& subject) = 0;

    virtual ~Observer() = default;
private:
    int identity_;
};

#endif // !OBSERVER_H