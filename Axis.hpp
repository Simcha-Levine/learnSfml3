#include <SFML/Graphics.hpp>

class Axis : public sf::Drawable
{
private:
    sf::RectangleShape *lines;

    void draw(sf::RenderTarget &target, sf::RenderStates) const override;

public:
    Axis();
    ~Axis();

    Axis(const Axis &) = delete;
    Axis &operator=(const Axis &) = delete;
};
