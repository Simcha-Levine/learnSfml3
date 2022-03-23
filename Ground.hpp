#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>
#include <string>
#include "Entity.hpp"
class Ground : public Entity, public sf::Drawable
{
private:
    void draw(sf::RenderTarget &target, sf::RenderStates) const override;

public:
    float scale;
    float x;
    float y;
    float width;
    float hight;
    b2World &world;
    b2Body *groundBody;
    sf::RectangleShape rect;
    char name1 = 'w';

    b2Body *createGround();

    Ground(b2World &world, float scale, float x, float y, float width, float hight);

    void onDetection(std::string otherName) override;

    Ground(const Ground &) = delete;
    Ground &operator=(const Ground &) = delete;
};