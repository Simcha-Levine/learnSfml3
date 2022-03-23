#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>
#include "Entity.hpp"

class Poly : public Entity, public sf::Drawable, public sf::Transformable
{
private:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

public:
    float scale;
    float x;
    float y;
    float width;
    b2World &world;
    b2Body *body;
    sf::VertexArray vertices;

    b2Body *createBody();
    void createShape(int i);
    void createShapes();

    Poly(b2World &world, float scale, float x, float y, float width);

    void setColor(sf::Color color);

    void update();

    void onDetection(std::string otherName) override;

    Poly(const Poly &) = delete;
    Poly &operator=(const Poly &) = delete;
};