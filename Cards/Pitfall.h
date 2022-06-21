#ifndef HW4_PITFALL_H
#define HW4_PITFALL_H
#include "Appliance.h"

class Pitfall : public Appliance
{
public:
    /*
  * C'tor of Pitfall class
  *Default
  * @return A new instance of Pitfall.
  */
    explicit Pitfall()=default;
    /*
   * D'tor of Pitfall class
   *
   *Default
   * destroys Pitfall
   */
    ~Pitfall()override=default;

    static std::unique_ptr<Pitfall> createPitfall();
    bool applyEncounter(Player& player) override;
    std::string getType() const override;

private:
    static const int GIVE_DAMAGE = 10;
    const std::string PITFALL = "Pitfall";

};


#endif //HW4_PITFALL_H
