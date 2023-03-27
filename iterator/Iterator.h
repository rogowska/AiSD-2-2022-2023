template <typename T>
class Iterator
{
public:
    virtual ~Iterator() {}
    Iterator() { ; }
    virtual bool IsDone() const = 0;
    virtual const T &operator*() = 0;
    virtual void operator++() = 0;
};