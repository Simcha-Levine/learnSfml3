#include <box2d/box2d.h>

class ContactListener : public b2ContactListener
{
private:
public:
    void BeginContact(b2Contact *contact) override;
};
